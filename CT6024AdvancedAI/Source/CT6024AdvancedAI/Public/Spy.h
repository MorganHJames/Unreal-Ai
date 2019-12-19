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

public:
	bool CanHide = false;
	bool IsHiding = false;
	virtual void Die() override;

private:
	class Action
	{
	public:
		virtual bool Succeeded() = 0;
	};

	class MultipleActions : public Action
	{
	private:
		std::list<Action*> Actions;
	public:
		const std::list<Action*>& GetActions() const
		{
			return Actions;
		}

		void AddAction(Action* Action)
		{
			Actions.emplace_back(Action);
		}
	};

	class Selector : public MultipleActions
	{
	public:
		virtual bool Succeeded() override
		{
			for (Action* Action : GetActions())
			{
				if (Action->Succeeded())
				{
					return true;
				}
			}
			return false;
		}
	};

	Selector* Root;

	class Sequence : public MultipleActions
	{
	public:
		virtual bool Succeeded() override
		{
			for (Action* Action : GetActions())
			{
				if (!Action->Succeeded())
				{
					return false;
				}
			}
			return true;
		}
	};

	class GoToLeverAction : public Action
	{
	private:
		bool knowsWhereLeverIs;
		FVector leverLocation;
		ASpy* spy;
	public:
		GoToLeverAction(bool knowsWhereLeverIs, FVector leverLocation, ASpy* spy) : knowsWhereLeverIs(knowsWhereLeverIs), leverLocation(leverLocation), spy(spy)
		{

		}

		virtual bool Succeeded() override
		{
			if (!knowsWhereLeverIs)
			{
				return false;
			}
			else
			{
				spy->MoveToLocation(leverLocation);
				return true;
			}
		}
	};
};
