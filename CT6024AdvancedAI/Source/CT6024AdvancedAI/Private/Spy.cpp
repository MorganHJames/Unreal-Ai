// Fill out your copyright notice in the Description page of Project Settings.

#include "Spy.h"
#include "SpectateAIGameMode.h"
#include "Engine/TriggerBox.h"
#include "Guard.h"
#include "SelfDestructLever.h"

// Called when the game starts or when spawned.
void ASpy::BeginPlay()
{
	// Register Events
	GuardChecker->OnActorBeginOverlap.AddDynamic(this, &ASpy::OnOverlapBegin2);
	GuardChecker->OnActorEndOverlap.AddDynamic(this, &ASpy::OnOverlapEnd2);

	ActorsSeen.Add(startingLockerocation);
	ActorsSeen.Add(startingHealthLocation);

	CurrentPositionHeadingTo = GetActorLocation();
	Root = new Selector;// Setup root node.

	GoToLeverAction* goToLever = new GoToLeverAction(this);
	SearchForLeverAction* searchForLever = new SearchForLeverAction(this);
	CheckTimeAction* checkTime = new CheckTimeAction();
	// Guard sees spy and spy is damaged.
	EvadeGuardAction* evadeGuard = new EvadeGuardAction(this);
	// Spy Attack Guard if unseen and healthy.
	AttackGuardAction* attackGuard = new AttackGuardAction(this);
	// Heal if unhealthy.
	HealAction* heal = new HealAction(this);
	// Avoid waste.
	AvoidToxicAction* avoidToxic = new AvoidToxicAction(this);
	// Safely find the lever.
	SearchForLeverSafeAction* searchForLeverSafe = new SearchForLeverSafeAction(this);
	// Safely pull the lever.
	GoToLeverSafeAction* goToLeverSafe = new GoToLeverSafeAction(this);

	Sequence* rushingSequence = new Sequence;
	rushingSequence->AddAction(checkTime);
	rushingSequence->AddAction(searchForLever);
	rushingSequence->AddAction(goToLever);

	Sequence* normalSequence = new Sequence;
	normalSequence->AddAction(evadeGuard);
	normalSequence->AddAction(attackGuard);
	normalSequence->AddAction(heal);
	normalSequence->AddAction(avoidToxic);
	normalSequence->AddAction(searchForLeverSafe);
	normalSequence->AddAction(goToLeverSafe);

	Root->AddAction(rushingSequence);
	Root->AddAction(normalSequence);

	Super::BeginPlay();
}

void ASpy::Tick(float DeltaTime)
{
	AHumanoid::Tick(DeltaTime);
	Root->Update();
}

// Kills the spy.
void ASpy::Die()
{
	if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
	{
		GM->GuardsWin();
	}
	Destroy();
}

// Checks if the spy knows the location of the lever.
bool ASpy::DoesSpyKnowLeverLocation()
{
	for (AActor* actor : ActorsSeen)
	{
		ASelfDestructLever* lever = Cast<ASelfDestructLever>(actor);

		if (lever)
		{
			return true;
		}
	}
	
	return false;
}

FVector ASpy::GetLeverLocation()
{
	for (AActor* actor : ActorsSeen)
	{
		ASelfDestructLever* lever = Cast<ASelfDestructLever>(actor);

		if (lever)
		{
			return lever->GetActorLocation();
		}
	}

	return FVector(0.0f, 0.0f, 0.0f);
}

// Called when an actor starts overlapping.
void ASpy::OnOverlapBegin2(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it overlaps something.
	if (OtherActor)
	{
		AGuard* guard = Cast<AGuard>(OtherActor);

		if (guard)
		{
			guardsInArea.Add(guard);
		}
	}
}

// Called when an actor stops overlapping.
void ASpy::OnOverlapEnd2(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it stops overlapping something.
	if (OtherActor)
	{
		AGuard* guard = Cast<AGuard>(OtherActor);

		if (guard)
		{
			if (guardsInArea.Contains(guard))
			{
				guardsInArea.Remove(guard);
			}
		}
	}
}