// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameController.h"
#include "CoreMinimal.h"
#include "Humanoid.h"
#include "Guard.h"
#include "Locker.h"
#include "HealthKit.h"
#include "ToxicSpill.h"
#include "Spy.generated.h"

/**
 * 
 */
UCLASS()
class CT6024ADVANCEDAI_API ASpy : public AHumanoid
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "References")
	class ATriggerBox* GuardChecker;

	UPROPERTY(EditAnywhere, Category = "Locations")
	class AActor* startingLockerocation;

	UPROPERTY(EditAnywhere, Category = "Locations")
	class AActor* startingHealthLocation;

	TArray<AGuard*> guardsInArea;

public:
	bool CanHide = false;
	bool IsHiding = false;
	virtual void Die() override;

	// declare overlap begin function.
	UFUNCTION()
	void OnOverlapBegin2(class AActor* OverlappedActor, class AActor* OtherActor);

	// declare overlap end function.
	UFUNCTION()
	void OnOverlapEnd2(class AActor* OverlappedActor, class AActor* OtherActor);

private:
	enum ActionState
	{
		Succeeded,
		Running,
		Failed
	};

	class Action
	{
	public:
		virtual ActionState Update() = 0;
	};

	class MultipleActions : public Action
	{
	private:
		TArray<Action*> Actions;
	public:
		int currentIndex = 0;
		void Reset()
		{
			currentIndex = 0;
		}
		const TArray<Action*>& GetActions() const
		{
			return Actions;
		}

		void AddAction(Action* Action)
		{
			Actions.Add(Action);
		}
	};

	class Selector : public MultipleActions
	{
	public:
		virtual ActionState Update() override
		{
			Action* currentAction = GetActions()[currentIndex];

			if (currentAction)
			{
				ActionState actionState = currentAction->Update();

				if (actionState == ActionState::Failed)
				{
					if (currentIndex == GetActions().IndexOfByKey(GetActions().Last()))
					{
						Reset();
						return ActionState::Failed;
					}
					else
					{
						currentIndex++;
						return ActionState::Running;
					}
				}
				else if (actionState == ActionState::Running)
				{
					return ActionState::Running;
				}
				else if (actionState == ActionState::Succeeded)
				{
					Reset();
					return ActionState::Succeeded;
				}
			}

			return ActionState::Failed;
		}
	};

	class Sequence : public MultipleActions
	{
	public:
		virtual ActionState Update() override
		{
			Action* currentAction = GetActions()[currentIndex];

			if (currentAction)
			{
				ActionState actionState = currentAction->Update();

				if (actionState == ActionState::Succeeded)
				{
					if (currentIndex == GetActions().IndexOfByKey(GetActions().Last()))
					{
						Reset();
						return ActionState::Succeeded;
					}
					else
					{
						currentIndex++;
						return ActionState::Running;
					}
				}
				else if (actionState == ActionState::Running)
				{
					return ActionState::Running;
				}
				else if (actionState == ActionState::Failed)
				{
					Reset();
					return ActionState::Failed;
				}
			}

			return ActionState::Failed;
		}
	};

	Selector* Root;

	class DecoratorNode : public Action 
	{  
	public:
		Action* action;

		void SetAction(Action* newAction) 
		{
			action = newAction; 
		}
	};

	class Succeeder : public DecoratorNode 
	{ 
	private:
		virtual ActionState Update() override
		{ 
			action->Update();
			return ActionState::Succeeded;
		}
	};

	class Failer : public DecoratorNode 
	{
	private:
		virtual ActionState Update() override
		{
			action->Update();
			return ActionState::Failed;
		}
	};

	class Repeater : public DecoratorNode 
	{
	private:
		int numberOfRepitions;
		int currentIndex = 0;
		static const int NoRepititions = -1;

		Repeater(int numberOfRepitions = NoRepititions) : numberOfRepitions(numberOfRepitions)
		{
		
		}

		virtual ActionState Update() override
		{
			if (numberOfRepitions == NoRepititions)
			{
				action->Update();
				return ActionState::Running;
			}
			else
			{
				if (currentIndex < numberOfRepitions)
				{
					action->Update();
					currentIndex++;
					return ActionState::Running;
				}

				currentIndex = 0;

				return ActionState::Succeeded;
			}
		}
	};

	class RepeatUntilFail : public DecoratorNode 
	{ 
	private:
		virtual ActionState Update() override
		{
			ActionState actionState = action->Update();

			if (actionState == ActionState::Failed)
			{
				return ActionState::Failed;
			}
			else
			{
				return ActionState::Running;
			}
		}
	};

	class RepeatUntilSucceed : public DecoratorNode
	{
	private:
		virtual ActionState Update() override
		{
			ActionState actionState = action->Update();

			if (actionState == ActionState::Succeeded)
			{
				return ActionState::Succeeded;
			}
			else
			{
				return ActionState::Running;
			}
		}
	};

	class GoToLeverAction : public Action
	{
	private:
		ASpy* spy;
	public:
		GoToLeverAction(ASpy* spy) : spy(spy)
		{

		}

		virtual ActionState Update() override
		{
			if (!spy->DoesSpyKnowLeverLocation())
			{
				return ActionState::Failed;
			}
			else
			{
				if (FVector::Dist(spy->GetLeverLocation(), spy->GetActorLocation()) < 10.0f)
				{
					return ActionState::Succeeded;
				}
				else
				{
					if (spy->CurrentPositionHeadingTo != spy->GetLeverLocation())
					{
						spy->CurrentPositionHeadingTo = spy->GetLeverLocation();
						spy->MoveToLocation(spy->GetLeverLocation());
					}
					return ActionState::Running;
				}
			}
		}
	};

	class SearchForLeverAction : public Action
	{
	private:
		ASpy* spy;
	public:
		SearchForLeverAction(ASpy* spy) : spy(spy)
		{

		}

		virtual ActionState Update() override
		{
			if (spy->DoesSpyKnowLeverLocation())
			{
				return ActionState::Succeeded;
			}
			else
			{
				if (FVector::Dist(spy->CurrentPositionHeadingTo, spy->GetActorLocation()) < 100.0f)
				{
					spy->CurrentPositionHeadingTo = spy->Locations[FMath::RandRange(0, spy->Locations.IndexOfByKey(spy->Locations.Last()))]->GetActorLocation();
					spy->MoveToLocation(spy->CurrentPositionHeadingTo);
				}

				return ActionState::Running;
			}
		}
	};

	class CheckTimeAction : public Action
	{
	public:
		CheckTimeAction()
		{

		}

		virtual ActionState Update() override
		{
			if (AGameController::currentTime <= 15.0f)
			{
				return ActionState::Succeeded;
			}
			else
			{
				return ActionState::Failed;
			}
		}
	};

	class EvadeGuardAction : public Action
	{
	private:
		ASpy* spy;
		float timeHiding = 0.0f;
	public :
		EvadeGuardAction(ASpy* spy) : spy(spy)
		{

		}

		virtual ActionState Update() override
		{
			bool isSeen = false;

			float closestDistance = 1000000000.0f;
			ALocker* closestLocker = nullptr;

			// Search for closest locker.
			for (AActor* actor : spy->ActorsSeen)
			{
				ALocker* locker = Cast<ALocker>(actor);

				if (locker)
				{
					if (FVector::Dist(locker->GetActorLocation(), spy->GetActorLocation()) < closestDistance)
					{
						closestLocker = locker;
						closestDistance = FVector::Dist(locker->GetActorLocation(), spy->GetActorLocation());
					}
				}
			}

			for (AGuard* guard : spy->guardsInArea)
			{
				if (guard->CanSeeSpy())
				{
					isSeen = true;
				}
			}

			if (AGameController::currentTime <= 15.0f)
			{
				return ActionState::Failed;

			}
			else if (!isSeen && spy->IsHiding == false)
			{
				return ActionState::Succeeded;
			}
			else
			{
				// If in a locker.
				if (spy->IsHiding == true)
				{
					timeHiding += 0.01f;
					if (timeHiding > 5.0f)
					{
						spy->IsHiding = false;
						timeHiding = 0.0f;
						return ActionState::Succeeded;
					}
				}
				// If is moving to locker.
				else if (spy->CurrentPositionHeadingTo == closestLocker->GetActorLocation())
				{
					if (FVector::Dist(closestLocker->GetActorLocation(), spy->GetActorLocation()) < 350.0f)
					{
						spy->IsHiding = true;
					}
				}
				else
				{
					// Check if guards are looking.
					for (AGuard* guard : spy->guardsInArea)
					{
						if (guard->CanSeeSpy())
						{
							spy->CurrentPositionHeadingTo = closestLocker->GetActorLocation();
							spy->MoveToLocation(spy->CurrentPositionHeadingTo);
							break;
						}
					}
				}

				return ActionState::Running;
			}
		}
	};

	class AttackGuardAction : public Action
	{
	private:
		ASpy* spy;
	public:
		AttackGuardAction(ASpy* spy) : spy(spy)
		{

		}

		virtual ActionState Update() override
		{
			// If seen.
			for (AGuard* guard : spy->guardsInArea)
			{
				if (guard->CanSeeSpy())
				{
					return ActionState::Failed;
				}
			}
			

			// If running out of time.
			if (AGameController::currentTime <= 15.0f)
			{
				return ActionState::Failed;
			}
			// Too risky.
			else if (spy->Health < 50.0f)
			{
				return ActionState::Succeeded;
			}
			else 
			{
				//Can see a guard.
				for (AActor* actor : spy->ActorsInVison)
				{
					// Check if guard is in spy's vision.
					AGuard* guard = Cast<AGuard>(actor);
					if (guard)
					{
						spy->CurrentPositionHeadingTo = guard->GetActorLocation();
						spy->MoveToLocation(spy->CurrentPositionHeadingTo);
						spy->Shoot();
						return ActionState::Running;
					}
				}
				return ActionState::Succeeded;
			}
		}
	};

	class HealAction : public Action
	{
	private:
		bool locationSet = false;
		ASpy* spy;
	public:
		HealAction(ASpy* spy) : spy(spy)
		{

		}

		virtual ActionState Update() override
		{
			for (AGuard* guard : spy->guardsInArea)
			{
				if (guard->CanSeeSpy())
				{
					return ActionState::Failed;
				}
			}
			

			// If running out of time.
			if (AGameController::currentTime <= 15.0f)
			{
				return ActionState::Failed;
			}

			//Can see a guard.
			for (AActor* actor : spy->ActorsInVison)
			{
				// Check if guard is in spy's vision.
				AGuard* guard = Cast<AGuard>(actor);

				if (guard)
				{
					return ActionState::Failed;
				}
			}

			if (spy->Health >= 100.0f)
			{
				return ActionState::Succeeded;
			}
			else if (!locationSet)
			{
				FVector closestHealthKitLocation;
				float shortestDistance = 10000000.0f;

				for (AActor* actor : spy->ActorsSeen)
				{
					// Check for closest seen health kit.
					AHealthKit* healthKit = Cast<AHealthKit>(actor);
					if (healthKit)
					{
						if (FVector::Distance(healthKit->GetActorLocation(), spy->GetActorLocation()) < shortestDistance)
						{
							shortestDistance = FVector::Distance(healthKit->GetActorLocation(), spy->GetActorLocation());
							closestHealthKitLocation = healthKit->GetActorLocation();
						}
					}
				}

				if (spy->CurrentPositionHeadingTo != closestHealthKitLocation)
				{
					spy->CurrentPositionHeadingTo = closestHealthKitLocation;
					spy->MoveToLocation(spy->CurrentPositionHeadingTo);
					locationSet = true;
				}
				return ActionState::Running;
			}
			else
			{
				return ActionState::Running;
			}
		}
	};

	class AvoidToxicAction : public Action
	{
	private:
		ASpy* spy;
	public:
		AvoidToxicAction(ASpy* spy) : spy(spy)
		{

		}

		virtual ActionState Update() override
		{
			
			for (AGuard* guard : spy->guardsInArea)
			{
				if (guard->CanSeeSpy())
				{
					return ActionState::Failed;
				}
			}
			

			// If running out of time.
			if (AGameController::currentTime <= 15.0f)
			{
				return ActionState::Failed;
			}

			//Can see a guard.
			for (AActor* actor : spy->ActorsInVison)
			{
				// Check if guard is in spy's vision.
				AGuard* guard = Cast<AGuard>(actor);

				if (guard)
				{
					return ActionState::Failed;
				}
			}

			if (spy->Health < 100.0f)
			{
				return ActionState::Failed;
			}
			
			for (AActor* actor : spy->ActorsInVison)
			{
				// Check if actor is toxic waste.
				AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);
				if (toxicSpill)
				{
					if (FVector::Dist(toxicSpill->GetActorLocation(), spy->GetActorLocation()) < 750.0f)
					{
						spy->CurrentPositionHeadingTo = spy->Locations[FMath::RandRange(0, spy->Locations.IndexOfByKey(spy->Locations.Last()))]->GetActorLocation();
						spy->MoveToLocation(spy->CurrentPositionHeadingTo);
						return ActionState::Succeeded;
					}
				}
			}
			return ActionState::Succeeded;
		}
	};

	class GoToLeverSafeAction : public Action
	{
	private:
		ASpy* spy;
	public:
		GoToLeverSafeAction(ASpy* spy) : spy(spy)
		{

		}

		virtual ActionState Update() override
		{
			for (AGuard* guard : spy->guardsInArea)
			{
				if (guard->CanSeeSpy())
				{
					return ActionState::Failed;
				}
			}

			// If running out of time.
			if (AGameController::currentTime <= 15.0f)
			{
				return ActionState::Failed;
			}

			//Can see a guard.
			for (AActor* actor : spy->ActorsInVison)
			{
				// Check if guard is in spy's vision.
				AGuard* guard = Cast<AGuard>(actor);

				if (guard)
				{
					return ActionState::Failed;
				}
			}

			if (spy->Health < 100.0f)
			{
				return ActionState::Failed;
			}

			for (AActor* actor : spy->ActorsInVison)
			{
				// Check if actor is toxic waste.
				AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);
				if (toxicSpill)
				{
					if (FVector::Dist(toxicSpill->GetActorLocation(), spy->GetActorLocation()) < 750.0f)
					{
						return ActionState::Failed;
					}
				}
			}

			if (!spy->DoesSpyKnowLeverLocation())
			{
				return ActionState::Failed;
			}
			else
			{
				if (FVector::Dist(spy->GetLeverLocation(), spy->GetActorLocation()) < 10.0f)
				{
					return ActionState::Succeeded;
				}
				else
				{
					if (spy->CurrentPositionHeadingTo != spy->GetLeverLocation())
					{
						spy->CurrentPositionHeadingTo = spy->GetLeverLocation();
						spy->MoveToLocation(spy->GetLeverLocation());
					}
					return ActionState::Running;
				}
			}
		}
	};

	class SearchForLeverSafeAction : public Action
	{
	private:
		ASpy* spy;
	public:
		SearchForLeverSafeAction(ASpy* spy) : spy(spy)
		{

		}

		virtual ActionState Update() override
		{
			for (AGuard* guard : spy->guardsInArea)
			{
				if (guard->CanSeeSpy())
				{
					return ActionState::Failed;
				}
			}
			

			// If running out of time.
			if (AGameController::currentTime <= 15.0f)
			{
				return ActionState::Failed;
			}

			//Can see a guard.
			for (AActor* actor : spy->ActorsInVison)
			{
				// Check if guard is in spy's vision.
				AGuard* guard = Cast<AGuard>(actor);

				if (guard)
				{
					return ActionState::Failed;
				}
			}

			if (spy->Health < 100.0f)
			{
				return ActionState::Failed;
			}

			for (AActor* actor : spy->ActorsInVison)
			{
				// Check if actor is toxic waste.
				AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);
				if (toxicSpill)
				{
					if (FVector::Dist(toxicSpill->GetActorLocation(), spy->GetActorLocation()) < 750.0f)
					{
						return ActionState::Failed;
					}
				}
			}

			if (spy->DoesSpyKnowLeverLocation())
			{
				return ActionState::Succeeded;
			}
			else
			{
				if (FVector::Dist(spy->CurrentPositionHeadingTo, spy->GetActorLocation()) < 300.0f)
				{
					spy->CurrentPositionHeadingTo = spy->Locations[FMath::RandRange(0, spy->Locations.IndexOfByKey(spy->Locations.Last()))]->GetActorLocation();
					spy->MoveToLocation(spy->CurrentPositionHeadingTo);
				}

				return ActionState::Running;
			}
		}
	};

	bool DoesSpyKnowLeverLocation();

	FVector GetLeverLocation();
};
