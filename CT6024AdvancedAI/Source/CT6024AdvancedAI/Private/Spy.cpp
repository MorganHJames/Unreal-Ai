////////////////////////////////////////////////////////////
// File: Spy.h
// Author: Morgan Henry James
// Date Created: ‎‎13 December ‎2019, ‏‎23:53:52
// Brief: Controls the spy and creates the behavior tree for the spy's AI.
//////////////////////////////////////////////////////////// 

#include "Spy.h"
#include "SpectateAIGameMode.h"
#include "Engine/TriggerBox.h"
#include "Guard.h"
#include "SelfDestructLever.h"

// Called when the game starts or when spawned.
void ASpy::BeginPlay()
{
	// Register Events
	guardChecker->OnActorBeginOverlap.AddDynamic(this, &ASpy::OnOverlapBegin2);
	guardChecker->OnActorEndOverlap.AddDynamic(this, &ASpy::OnOverlapEnd2);

	// Adds the starting knowledge to the spy.
	actorsSeen.Add(startingLockerocation);
	actorsSeen.Add(startingHealthLocation);

	// Set the current position to the spy starting location.
	currentPositionHeadingTo = GetActorLocation();

	// Setup root node for the behavior tree.
	rootNode = new Selector;

	// Action declarations.
	// Move spy to lever.
	GoToLeverAction* goToLever = new GoToLeverAction(this);

	// Make spy search for lever.
	SearchForLeverAction* searchForLever = new SearchForLeverAction(this);

	// Checks to see if the time is low.
	CheckTimeAction* checkTime = new CheckTimeAction(this);

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

	// First Sequence that checks if the time is low and if so disregards a lot in pursuit of the lever.
	Sequence* rushingSequence = new Sequence;
	rushingSequence->AddAction(checkTime);
	rushingSequence->AddAction(searchForLever);
	rushingSequence->AddAction(goToLever);

	// The second sequence that safely searches for the lever.
	Sequence* normalSequence = new Sequence;
	normalSequence->AddAction(evadeGuard);
	normalSequence->AddAction(attackGuard);
	normalSequence->AddAction(heal);
	normalSequence->AddAction(avoidToxic);
	normalSequence->AddAction(searchForLeverSafe);
	normalSequence->AddAction(goToLeverSafe);

	// Adds the sequences to the root node.
	rootNode->AddAction(rushingSequence);
	rootNode->AddAction(normalSequence);

	Super::BeginPlay();
}

// Called every frame.
void ASpy::Tick(float a_deltaTime)
{
	AHumanoid::Tick(a_deltaTime);
	rootNode->Update();
}

// Kills the spy.
void ASpy::Die()
{
	if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
	{
		// Indicates that the guards have won.
		GM->GuardsWin();
	}
	Destroy();
}

// Checks if the spy knows the location of the lever.
bool ASpy::DoesSpyKnowLeverLocation()
{
	// For every actor the spy can see.
	for (AActor* actor : actorsSeen)
	{
		// Cast the actor to a lever.
		ASelfDestructLever* lever = Cast<ASelfDestructLever>(actor);

		// If the actor is a lever.
		if (lever)
		{
			// Indicate that the spy knows the location of the lever.
			return true;
		}
	}
	
	// Indicate that the spy does not know the location of the lever.
	return false;
}

// Returns the location of the lever.
FVector ASpy::GetLeverLocation()
{
	// For every actor that the spy has seen.
	for (AActor* actor : actorsSeen)
	{
		// cast the actor to a lever.
		ASelfDestructLever* lever = Cast<ASelfDestructLever>(actor);

		// If the actor is a lever.
		if (lever)
		{
			// Return the lever location.
			return lever->GetActorLocation();
		}
	}

	// Return a zeroed vector.
	return FVector(0.0f, 0.0f, 0.0f);
}

// Called when an actor starts overlapping.
void ASpy::OnOverlapBegin2(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it overlaps something.
	if (a_otherActor)
	{
		// Cast the actor to a guard.
		AGuard* guard = Cast<AGuard>(a_otherActor);

		// If the actor is a guard.
		if (guard)
		{
			// Add the guard to the array of guards in the area.
			guardsInArea.Add(guard);
		}
	}
}

// Called when an actor stops overlapping.
void ASpy::OnOverlapEnd2(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it stops overlapping something.
	if (a_otherActor)
	{
		// Cast the actor to a guard.
		AGuard* guard = Cast<AGuard>(a_otherActor);

		// If the actor is a guard.
		if (guard)
		{
			// If the guard is in the guards in area array.
			if (guardsInArea.Contains(guard))
			{
				// Remove the guard from the guards in area array.
				guardsInArea.Remove(guard);
			}
		}
	}
}