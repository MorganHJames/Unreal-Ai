////////////////////////////////////////////////////////////
// File: Spy.h
// Author: Morgan Henry James
// Date Created: ‎‎13 December ‎2019, ‏‎23:53:52
// Brief: Declaration of the spy class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "GameController.h"
#include "CoreMinimal.h"
#include "Humanoid.h"
#include "Guard.h"
#include "Locker.h"
#include "HealthKit.h"
#include "ToxicSpill.h"
#include "Spy.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API ASpy : public AHumanoid
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// Called every frame.
	virtual void Tick(float a_deltaTime) override;

	// The box in which the spy can see guards looking at itself.
	UPROPERTY(EditAnywhere, Category = "References")
	class ATriggerBox* guardChecker;

	// The first locker that the spy can see.
	UPROPERTY(EditAnywhere, Category = "locations")
	class AActor* startingLockerocation;

	// The first health kit that the spy can see.
	UPROPERTY(EditAnywhere, Category = "locations")
	class AActor* startingHealthLocation;

	// All of the guards around the spy.
	TArray<AGuard*> guardsInArea;

public:
	// True when the spy can hide within a locker.
	bool canHide = false;

	// True when the spy is hiding.
	bool isHiding = false;

	// Kills the spy.
	virtual void Die() override;

	// Declare overlap begin function.
	UFUNCTION()
	void OnOverlapBegin2(class AActor* a_overlappedActor, class AActor* a_otherActor);

	// Declare overlap end function.
	UFUNCTION()
	void OnOverlapEnd2(class AActor* a_overlappedActor, class AActor* a_otherActor);

private:
	// All the states the actions of the behavior tree.
	enum ActionState
	{
		Succeeded,
		Running,
		Failed
	};

	// The actions that make up the behavior tree.
	class Action
	{
	public:
		// The update function for the action that returns an action state when called.
		virtual ActionState Update() = 0;
	};

	// Multiple actions binded together.
	class MultipleActions : public Action
	{
	private:
		// The actions that are binded together.
		TArray<Action*> actions;

	public:
		// The index of the action that the multiple action class is on.
		int currentIndex = 0;

		// Resets the current index.
		void Reset()
		{
			currentIndex = 0;
		}

		// Returns all the action array.
		const TArray<Action*>& GetActions() const
		{
			return actions;
		}

		// Adds an action to the action array.
		void AddAction(Action* Action)
		{
			actions.Add(Action);
		}
	};

	// For the selector to be considered a success only one of it's child actions needs to succeed.
	class Selector : public MultipleActions
	{
	public:
		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// Returns the action that the selector is currently on.
			Action* currentAction = GetActions()[currentIndex];

			// If the selector has actions as children.
			if (currentAction)
			{
				// Call the action's update allowing the actions logic to unfold.
				ActionState actionState = currentAction->Update();

				// If the action failed.
				if (actionState == ActionState::Failed)
				{
					// If the action was the last in the array.
					if (currentIndex == GetActions().IndexOfByKey(GetActions().Last()))
					{
						// Reset the current index for next time as the selector has now failed.
						Reset();

						// Indicate to the selector parent node that it has failed.
						return ActionState::Failed;
					}
					else
					{
						// Increase the current index of the selector.
						currentIndex++;

						// Indicate to the parent node that the selector is now running.
						return ActionState::Running;
					}
				}
				// If the child is running.
				else if (actionState == ActionState::Running)
				{
					// Indicate to the parent node that the selector is now running.
					return ActionState::Running;
				}
				// If the child has succeeded.
				else if (actionState == ActionState::Succeeded)
				{
					// Reset the current index for next time as the selector has now succeed.
					Reset();

					// Indicated to the parent node that the selector has succeeded.
					return ActionState::Succeeded;
				}
			}

			// Indicate to the parent node that the selector has failed.
			return ActionState::Failed;
		}
	};

	// For a sequence to be considered as succeed all children must return succeed.
	class Sequence : public MultipleActions
	{
	public:
		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// Returns the action that the sequence is currently on.
			Action* currentAction = GetActions()[currentIndex];

			// If the sequence has actions as children.
			if (currentAction)
			{
				// Call the action's update allowing the actions logic to unfold.
				ActionState actionState = currentAction->Update();

				// If the child has succeeded.
				if (actionState == ActionState::Succeeded)
				{
					// If the child was the last in the array.
					if (currentIndex == GetActions().IndexOfByKey(GetActions().Last()))
					{
						// Reset the current index as the sequence is now considered a success.
						Reset();

						// Indicate to the parent node that the sequence has succeeded.
						return ActionState::Succeeded;
					}
					else
					{
						// Increase the current index as every node must be a success for the sequence to be.
						currentIndex++;

						// Indicate to the parent node that the sequence is running.
						return ActionState::Running;
					}
				}
				// If the child is running.
				else if (actionState == ActionState::Running)
				{
					// Indicate to the parent node that the sequence is running.
					return ActionState::Running;
				}
				// If the child has failed.
				else if (actionState == ActionState::Failed)
				{
					// Reset the current index.
					Reset();

					// Indicate to the parent node that the sequence failed.
					return ActionState::Failed;
				}
			}

			// Indicate to the parent node that the sequence failed.
			return ActionState::Failed;
		}
	};

	// The root node at the of the behavior tree.
	Selector* rootNode;

	// A decorator can have only one child and modifies the action state it returns in some way.
	class DecoratorNode : public Action 
	{  
	public:
		// The action that the decorator node effects.
		Action* action;

		// Sets the action that the decorator node effects.
		void SetAction(Action* a_newAction) 
		{
			action = a_newAction; 
		}
	};

	// The node this decorator effects will return succeeded.
	class Succeeder : public DecoratorNode 
	{ 
	private:
		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{ 
			// Call the action's update allowing the actions logic to unfold.
			action->Update();

			// Indicates to the parent node that the decorator succeeded.
			return ActionState::Succeeded;
		}
	};

	// The node this decorator effects will return failed.
	class Failer : public DecoratorNode 
	{
	private:
		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// Call the action's update allowing the actions logic to unfold.
			action->Update();

			// Indicates to the parent node that the decorator failed.
			return ActionState::Failed;
		}
	};

	// The node this decorator effects will be called repeatedly.
	class Repeater : public DecoratorNode 
	{
	private:
		// How many times the node will be repeated.
		int numberOfRepitions;

		// The current index of repetitions.
		int currentIndex = 0;

		// The number that indicated no repetitions.
		static const int noRepititions = -1;

		// Constructor for the repeater.
		Repeater(int a_numberOfRepitions = noRepititions) : numberOfRepitions(a_numberOfRepitions)
		{
		
		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// If no repetitions are to be had.
			if (numberOfRepitions == noRepititions)
			{
				// Call the action's update allowing the actions logic to unfold.
				action->Update();

				// Indicates to the parent node that the repeater is running.
				return ActionState::Running;
			}
			// If there are repetitions to be had.
			else
			{
				// If the current index is less than the number of repetitions.
				if (currentIndex < numberOfRepitions)
				{
					// Call the action's update allowing the actions logic to unfold.
					action->Update();

					// Increases the current index of the repetition.
					currentIndex++;

					// Indicate to the parent node that the repeater is running.
					return ActionState::Running;
				}

				// Reset the current index of the repetitions.
				currentIndex = 0;

				// Indicate to the parent node that the repeater has succeeded.
				return ActionState::Succeeded;
			}
		}
	};

	// The node this decorator effects will be called repeatedly until it fails.
	class RepeatUntilFail : public DecoratorNode 
	{ 
	private:
		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// Call the action's update allowing the actions logic to unfold.
			ActionState actionState = action->Update();

			// If the action fails.
			if (actionState == ActionState::Failed)
			{
				// Indicates to the parent node that the decorator failed.
				return ActionState::Failed;
			}
			else
			{
				// Indicates to the parent node that the decorator is running.
				return ActionState::Running;
			}
		}
	};

	// The node this decorator effects will be called repeatedly until it succeeds.
	class RepeatUntilSucceed : public DecoratorNode
	{
	private:
		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// Call the action's update allowing the actions logic to unfold.
			ActionState actionState = action->Update();

			// If the action succeeded.
			if (actionState == ActionState::Succeeded)
			{
				// Indicates to the parent node that the decorator has succeeded.
				return ActionState::Succeeded;
			}
			else
			{
				// Indicates to the parent node that the decorator is running.
				return ActionState::Running;
			}
		}
	};

	// An action that makes the spy go to a lever if it knows it's location.
	class GoToLeverAction : public Action
	{
	private:
		// The spy.
		ASpy* spy;

	public:
		// Constructor.
		GoToLeverAction(ASpy* a_spy) : spy(a_spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// If the spy does not know the location of the lever.
			if (!spy->DoesSpyKnowLeverLocation())
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}
			else
			{
				// If the spy is at the lever.
				if (FVector::Dist(spy->GetLeverLocation(), spy->GetActorLocation()) < 10.0f)
				{
					// Indicate to the parent node that the action succeeded.
					return ActionState::Succeeded;
				}
				else
				{
					// If the spy is not headed to the lever.
					if (spy->currentPositionHeadingTo != spy->GetLeverLocation())
					{
						// Make the spy head to the lever.
						spy->currentPositionHeadingTo = spy->GetLeverLocation();
						spy->MoveToLocation(spy->GetLeverLocation());
					}

					// Indicate to the parent node that the action is running.
					return ActionState::Running;
				}
			}
		}
	};

	// An action that makes the spy search for the lever to blow up the nuke.
	class SearchForLeverAction : public Action
	{
	private:
		// The spy.
		ASpy* spy;

	public:
		// Constructor.
		SearchForLeverAction(ASpy* a_spy) : spy(a_spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// If the spy knows the location of the lever.
			if (spy->DoesSpyKnowLeverLocation())
			{
				// Indicate to the parent node that the action succeeded.
				return ActionState::Succeeded;
			}
			// If the spy does not know the location of the lever.
			else
			{
				// If the spy is close to the position it is heading to.
				if (FVector::Dist(spy->currentPositionHeadingTo, spy->GetActorLocation()) < 100.0f)
				{
					// Pick a new random location to go to.
					spy->currentPositionHeadingTo = spy->locations[FMath::RandRange(0, spy->locations.IndexOfByKey(spy->locations.Last()))]->GetActorLocation();
					
					// Go to the new random location.
					spy->MoveToLocation(spy->currentPositionHeadingTo);
				}

				// Indicate to the parent node that the action is running.
				return ActionState::Running;
			}
		}
	};

	// An action that checks the current time until the nuke launches.
	class CheckTimeAction : public Action
	{
	private:
		// The spy.
		ASpy* spy;

	public:
		// Constructor.
		CheckTimeAction(ASpy* a_spy) : spy(a_spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// If the time until launch is less than or equal to 15 seconds.
			if (AGameController::currentTime <= 15.0f)
			{
				// If the spy is hiding.
				if (spy->isHiding == true)
				{
					// Make the spy stop hiding.
					spy->isHiding = false;
				}

				// Indicate to the parent node that the action succeeded.
				return ActionState::Succeeded;
			}
			else
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}
		}
	};

	class EvadeGuardAction : public Action
	{
	private:
		// The spy.
		ASpy* spy;

		// The current time the spy has been hiding.
		float timeHiding = 0.0f;

	public :
		// Constructor.
		EvadeGuardAction(ASpy* spy) : spy(spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// If the spy is seen or not.
			bool isSeen = false;

			// The current closest distance to a locker.
			float closestDistance = 1000000000.0f;

			// The current closest locker.
			ALocker* closestLocker = nullptr;

			// Search for closest locker.
			for (AActor* actor : spy->actorsSeen)
			{
				// Cast the actors in actors seen to lockers.
				ALocker* locker = Cast<ALocker>(actor);

				// If the actor is a locker.
				if (locker)
				{
					// If the distance to the locker is shorter than the current closest distance.
					if (FVector::Dist(locker->GetActorLocation(), spy->GetActorLocation()) < closestDistance)
					{
						// Assign the closest locker to the new closest locker.
						closestLocker = locker;

						// Assign the shortest distance to the new closest locker distance.
						closestDistance = FVector::Dist(locker->GetActorLocation(), spy->GetActorLocation());
					}
				}
			}
			
			// For all guards in the area.
			for (AGuard* guard : spy->guardsInArea)
			{
				// If the guard can see the spy.
				if (guard->CanSeeSpy())
				{
					// Allow the spy to know that it has been spotted.
					isSeen = true;
				}
			}

			// If the current time is less than or equal to 15 seconds until a nuke launches.
			if (AGameController::currentTime <= 15.0f)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;

			}
			// If the spy has not been spotted and is not hiding.
			else if (!isSeen && spy->isHiding == false)
			{
				// Indicate to the parent node that the action succeeded.
				return ActionState::Succeeded;
			}
			else
			{
				// If in a locker.
				if (spy->isHiding == true)
				{
					// Increase hiding time.
					timeHiding += 0.01f;

					// If the time the spy has spent hidden is above 5.
					if (timeHiding > 5.0f)
					{
						// Make the spy stop hiding.
						spy->isHiding = false;

						// Reset the time that the spy has spent hiding.
						timeHiding = 0.0f;

						// Indicate to the parent node that the action succeeded.
						return ActionState::Succeeded;
					}
				}
				// If is moving to locker.
				else if (spy->currentPositionHeadingTo == closestLocker->GetActorLocation())
				{
					// If close to the locker.
					if (FVector::Dist(closestLocker->GetActorLocation(), spy->GetActorLocation()) < 350.0f)
					{
						// Allow the spy to enter the locker.
						spy->isHiding = true;
					}
				}
				else
				{
					// Check if guards are looking.
					for (AGuard* guard : spy->guardsInArea)
					{
						// If a guard can see a spy.
						if (guard->CanSeeSpy())
						{
							// Make the spy move to the closest locker.
							spy->currentPositionHeadingTo = closestLocker->GetActorLocation();
							spy->MoveToLocation(spy->currentPositionHeadingTo);

							// Early out.
							break;
						}
					}
				}

				// Indicate to the parent node that the action is running.
				return ActionState::Running;
			}
		}
	};

	// An action that makes the spy attack a guard.
	class AttackGuardAction : public Action
	{
	private:
		// The spy.
		ASpy* spy;

	public:
		// Constructor.
		AttackGuardAction(ASpy* a_spy) : spy(a_spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// If seen.
			for (AGuard* guard : spy->guardsInArea)
			{
				// If the guards can see the spy.
				if (guard->CanSeeSpy())
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}
			
			// If the current time is less than or equal to 15 seconds until a nuke launches.
			if (AGameController::currentTime <= 15.0f)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}
			// Too risky to attack.
			else if (spy->health < 50.0f)
			{
				// Indicate to the parent node that the action succeeded.
				return ActionState::Succeeded;
			}
			else 
			{
				//Can see a guard.
				for (AActor* actor : spy->actorsInVison)
				{
					// Check if guard is in spy's vision.
					AGuard* guard = Cast<AGuard>(actor);

					// If there is a guard within the vision of the spy.
					if (guard)
					{
						// Move to the guard.
						spy->currentPositionHeadingTo = guard->GetActorLocation();
						spy->MoveToLocation(spy->currentPositionHeadingTo);

						// Shoot the guard.
						spy->Shoot();

						// Indicate to the parent node that the action is running.
						return ActionState::Running;
					}
				}

				// Indicate to the parent node that the action succeeded.
				return ActionState::Succeeded;
			}
		}
	};

	// An action that makes the spy find a source of healing.
	class HealAction : public Action
	{
	private:
		// If the spy is moving to the closest health pack or not.
		bool locationSet = false;

		// The spy.
		ASpy* spy;

	public:
		// Constructor.
		HealAction(ASpy* a_spy) : spy(a_spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// For all the guards around the spy.
			for (AGuard* guard : spy->guardsInArea)
			{
				// If the guard can see the spy.
				if (guard->CanSeeSpy())
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}

			// If the current time is less than or equal to 15 seconds until a nuke launches.
			if (AGameController::currentTime <= 15.0f)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}

			//Can see a guard.
			for (AActor* actor : spy->actorsInVison)
			{
				// Check if guard is in spy's vision.
				AGuard* guard = Cast<AGuard>(actor);

				// If there is a guard in the spy's vision.
				if (guard)
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}

			// If the spy is at gull health.
			if (spy->health >= 100.0f)
			{
				// Indicate to the parent node that the action succeeded.
				return ActionState::Succeeded;
			}

			// If the spy is not currently going to a health kit.
			else if (!locationSet)
			{
				// The location of the closest health kit.
				FVector closestHealthKitLocation;

				// The distance to the closest health kit.
				float shortestDistance = 10000000.0f;

				// For all the actors that the spy has seen.
				for (AActor* actor : spy->actorsSeen)
				{
					// Check for closest seen health kit.
					AHealthKit* healthKit = Cast<AHealthKit>(actor);

					// If the actor is a health kit.
					if (healthKit)
					{
						// If the distance from the spy to the health kit is shorter that the current shortest distance.
						if (FVector::Distance(healthKit->GetActorLocation(), spy->GetActorLocation()) < shortestDistance)
						{
							// Set the shortest distance to be that of the new closest health kit.
							shortestDistance = FVector::Distance(healthKit->GetActorLocation(), spy->GetActorLocation());

							// Set the health kit location to be that of the closest health kit's location.
							closestHealthKitLocation = healthKit->GetActorLocation();
						}
					}
				}

				// If the spy is not currently going to the closest health kit.
				if (spy->currentPositionHeadingTo != closestHealthKitLocation)
				{
					// Make the spy move to the location of the closest health kit.
					spy->currentPositionHeadingTo = closestHealthKitLocation;
					spy->MoveToLocation(spy->currentPositionHeadingTo);

					// Indicate that the spy is now headed to the location of the closest health kit.
					locationSet = true;
				}

				// Indicate to the parent node that the action is running.
				return ActionState::Running;
			}
			else
			{
				// Indicate to the parent node that the action is running.
				return ActionState::Running;
			}
		}
	};

	// An action that makes the spy avoid standing within toxic waste.
	class AvoidToxicAction : public Action
	{
	private:
		// The spy.
		ASpy* spy;

	public:
		// Constructor.
		AvoidToxicAction(ASpy* a_spy) : spy(a_spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// For all the guards around the spy.
			for (AGuard* guard : spy->guardsInArea)
			{
				// If the guard can see the spy.
				if (guard->CanSeeSpy())
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}

			// If the current time is less than or equal to 15 seconds until a nuke launches.
			if (AGameController::currentTime <= 15.0f)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}

			//Can see a guard.
			for (AActor* actor : spy->actorsInVison)
			{
				// Check if guard is in spy's vision.
				AGuard* guard = Cast<AGuard>(actor);

				// If there is a guard in the spy's vision.
				if (guard)
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}

			// If the spy is less than full health.
			if (spy->health < spy->maxHealth)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}
			
			// For all the actors in the spy's vision.
			for (AActor* actor : spy->actorsInVison)
			{
				// Check if actor is toxic waste.
				AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);

				// If the actor is toxic waste.
				if (toxicSpill)
				{
					// If the distance from the spy to the toxic waste is less than 750.
					if (FVector::Dist(toxicSpill->GetActorLocation(), spy->GetActorLocation()) < 750.0f)
					{
						// Choose a new random location to head to.
						spy->currentPositionHeadingTo = spy->locations[FMath::RandRange(0, spy->locations.IndexOfByKey(spy->locations.Last()))]->GetActorLocation();
						spy->MoveToLocation(spy->currentPositionHeadingTo);

						// Indicate to the parent node that the action succeeded.
						return ActionState::Succeeded;
					}
				}
			}

			// Indicate to the parent node that the action succeeded.
			return ActionState::Succeeded;
		}
	};

	// An action that makes the spy go to the lever that stops the nuke launching but only if it's safe for it to do so.
	class GoToLeverSafeAction : public Action
	{
	private:
		// The spy.
		ASpy* spy;

	public:
		// Constructor.
		GoToLeverSafeAction(ASpy* a_spy) : spy(a_spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// For all the guards around the spy.
			for (AGuard* guard : spy->guardsInArea)
			{
				// If the guard can see the spy.
				if (guard->CanSeeSpy())
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}

			// If the current time is less than or equal to 15 seconds until a nuke launches.
			if (AGameController::currentTime <= 15.0f)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}

			//Can see a guard.
			for (AActor* actor : spy->actorsInVison)
			{
				// Check if guard is in spy's vision.
				AGuard* guard = Cast<AGuard>(actor);

				// If there is a guard in the spy's vision.
				if (guard)
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}

			// If the spy is less than full health.
			if (spy->health < spy->maxHealth)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}

			// For all actors in the spy's vision.
			for (AActor* actor : spy->actorsInVison)
			{
				// Check if actor is toxic waste.
				AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);

				// If the actor is toxic waste.
				if (toxicSpill)
				{
					// If the distance to the toxic waste is less than 750.
					if (FVector::Dist(toxicSpill->GetActorLocation(), spy->GetActorLocation()) < 750.0f)
					{
						// Indicate to the parent node that the action failed.
						return ActionState::Failed;
					}
				}
			}

			// If the spy does not know the location of the lever.
			if (!spy->DoesSpyKnowLeverLocation())
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}
			// If the spy does know the location of the lever.
			else
			{
				// If the spy is at the lever.
				if (FVector::Dist(spy->GetLeverLocation(), spy->GetActorLocation()) < 10.0f)
				{
					// Indicate to the parent node that the action succeeded.
					return ActionState::Succeeded;
				}
				// If the spy is not at the lever.
				else
				{
					// If the spy is not headed to the lever.
					if (spy->currentPositionHeadingTo != spy->GetLeverLocation())
					{
						// Make the spy head to the lever.
						spy->currentPositionHeadingTo = spy->GetLeverLocation();
						spy->MoveToLocation(spy->GetLeverLocation());
					}

					// Indicate to the parent node that the action is running.
					return ActionState::Running;
				}
			}
		}
	};

	class SearchForLeverSafeAction : public Action
	{
	private:
		// The spy.
		ASpy* spy;

	public:
		// Constructor.
		SearchForLeverSafeAction(ASpy* a_spy) : spy(a_spy)
		{

		}

		// The update function for the action that returns an action state when called.
		virtual ActionState Update() override
		{
			// For all the guards around the spy.
			for (AGuard* guard : spy->guardsInArea)
			{
				// If the guard can see the spy.
				if (guard->CanSeeSpy())
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}

			// If the current time is less than or equal to 15 seconds until a nuke launches.
			if (AGameController::currentTime <= 15.0f)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}

			//Can see a guard.
			for (AActor* actor : spy->actorsInVison)
			{
				// Check if guard is in spy's vision.
				AGuard* guard = Cast<AGuard>(actor);

				// If there is a guard in the spy's vision.
				if (guard)
				{
					// Indicate to the parent node that the action failed.
					return ActionState::Failed;
				}
			}

			// If the spy is less than full health.
			if (spy->health < spy->maxHealth)
			{
				// Indicate to the parent node that the action failed.
				return ActionState::Failed;
			}

			// For all actors in the spy's vision.
			for (AActor* actor : spy->actorsInVison)
			{
				// Check if actor is toxic waste.
				AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);

				// If the actor is toxic waste.
				if (toxicSpill)
				{
					// If the distance to the toxic waste is less than 750.
					if (FVector::Dist(toxicSpill->GetActorLocation(), spy->GetActorLocation()) < 750.0f)
					{
						// Indicate to the parent node that the action failed.
						return ActionState::Failed;
					}
				}
			}

			// If the spy knows the location of the lever.
			if (spy->DoesSpyKnowLeverLocation())
			{
				// Indicate to the parent node that the action succeeded.
				return ActionState::Succeeded;
			}
			// If the spy does not know the location of the lever.
			else
			{
				// If the distance to the current position that the spy is headed to is less than 100.
				if (FVector::Dist(spy->currentPositionHeadingTo, spy->GetActorLocation()) < 100.0f)
				{
					// Pick a new random location for the spy to go to.
					spy->currentPositionHeadingTo = spy->locations[FMath::RandRange(0, spy->locations.IndexOfByKey(spy->locations.Last()))]->GetActorLocation();
					spy->MoveToLocation(spy->currentPositionHeadingTo);
				}

				// Indicate to the parent node that the action is running.
				return ActionState::Running;
			}
		}
	};

	// Returns true if the spy knows the location of the lever.
	bool DoesSpyKnowLeverLocation();

	// Returns the location of the lever.
	FVector GetLeverLocation();
};
