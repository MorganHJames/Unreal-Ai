// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Humanoid.h"
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

public:
	bool CanHide = false;
	bool IsHiding = false;
	virtual void Die() override;

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

	Sequence* Root;

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

	bool DoesSpyKnowLeverLocation();

	FVector GetLeverLocation();
};
