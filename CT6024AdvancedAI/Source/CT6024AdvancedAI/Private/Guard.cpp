////////////////////////////////////////////////////////////
// File: Guard.cpp
// Author: Morgan Henry James
// Date Created: ‎‎‎‎13 December ‎2019, ‏‎23:54:43
// Brief: Controls the guard AI with a finite state machine.
//////////////////////////////////////////////////////////// 

#include "Guard.h"
#include "Spy.h"
#include "ToxicSpill.h"
#include "Components/TextRenderComponent.h"

// Sets default values.
AGuard::AGuard()
{
	// The energy text for the guard.
	energyText = CreateDefaultSubobject<UTextRenderComponent>("energyText");
}

// If the guard can see the spy or not.
bool AGuard::CanSeeSpy()
{
	// For all actors in the guards vision
	for (AActor* actor : actorsInVison)
	{
		// Check if actor is spy.
		ASpy* Spy = Cast<ASpy>(actor);

		// If the actor is a spy.
		if (Spy)
		{
			// Indicate that the guard can see the spy.
			return true;
		}
	}

	// Indicate that the guard can not see the spy.
	return false;
}

// Called when the game starts or when spawned.
void AGuard::BeginPlay()
{
	// Set a random position to go to.
	energy -= FMath::RandRange(0, 80);
	currentPositionHeadingTo = locations[FMath::RandRange(0, locations.IndexOfByKey(locations.Last()))]->GetActorLocation();
	MoveToLocation(currentPositionHeadingTo);
	AHumanoid::BeginPlay();
}

// Changes the guards charge and updates the ai.
void AGuard::Tick(float DeltaTime)
{
	AHumanoid::Tick(DeltaTime);

	// If the guard is charging.
	if (charging)
	{
		// Increase the energy of the guard.
		energy += DeltaTime * 5.0f;
	}
	// Drain the energy of the guard over time.
	else
	{
		// Decreases the energy of the guard.
		energy -= DeltaTime;
	}

	// Clamp the energy.
	if (energy > maxEnergy)
	{
		energy = maxEnergy;
	}

	// If the guard runs out of energy.
	if (energy <= 0)
	{
		// Kill the guard.
		Die();
	}

	// Sets up the text string.
	FString EnergyRemaining = FString::FromInt((int)energy);

	// Sets the text.
	energyText->SetText(EnergyRemaining);

	// Updates the AI.
	UpdateAI();
}

// Contains the state machine for the guard AI behavior.
void AGuard::UpdateAI()
{
	switch (currentState)
	{
	case AGuard::Wander:
		CheckTransitionToAttackBehaviour();
		CheckTransitionToChargeBehaviour(15);
		CheckTransitionToHealBehaviour(25);
		CheckTransitionToAvoidToxicBehaviour();
		WanderBehaviour();
		break;
	case AGuard::Charge:
		CheckTransitionToAttackBehaviour();
		CheckTransitionToWanderFromChargeBehaviour();
		ChargeBehaviour();
		break;
	case AGuard::Heal:
		CheckTransitionToAttackBehaviour();
		CheckTransitionToWanderFromHealBehaviour();
		HealBehaviour();
		break;
	case AGuard::Attack:
		CheckTransitionToWanderFromAttackBehaviour();
		AttackBehaviour();
		break;
	case AGuard::AvoidToixc:
		CheckTransitionToWanderFromAvoidToxicBehaviour();
		AvoidToxicBehaviour();
		break;
	default:
		WanderBehaviour();
		break;
	}
}

// Checks the transition to wander from charging.
bool AGuard::CheckTransitionToWanderFromChargeBehaviour()
{
	// If the guard is charged.
	if (energy >= 100)
	{
		// Go back to wandering.
		currentState = Wander;
		return true;
	}
	else
	{
		return false;
	}
}

// Checks the transitions to wanter from attacking.
bool AGuard::CheckTransitionToWanderFromAttackBehaviour()
{
	// For all the actors in the guards vision.
	for (AActor* actor : actorsInVison)
	{
		// Check if actor is spy.
		ASpy* Spy = Cast<ASpy>(actor);

		// If the actor is a spy.
		if (Spy)
		{
			return true;
		}
	}

	// Go back to wandering.
	currentState = Wander;
	return false;
}

// Checks the transition from wander to healing.
bool AGuard::CheckTransitionToWanderFromHealBehaviour()
{
	// If the guard is at full health.
	if (health >= 100)
	{
		// go back to wandering.
		currentState = Wander;
		return true;
	}
	else
	{
		return false;
	}
}

// Checks the transition from wander to avoiding toxic waste.
bool AGuard::CheckTransitionToWanderFromAvoidToxicBehaviour()
{
	// For all actors in the guards vision.
	for (AActor* actor : actorsInVison)
	{
		// Check if actor is a toxic spill.
		AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);

		// If the actor is a toxic spill.
		if (toxicSpill)
		{
			// If the guard is close to the spill.
			if (FVector::Dist(toxicSpill->GetActorLocation(), this->GetActorLocation()) < 300.0f)
			{
				return false;
			}
			break;
		}
	}

	// Go back to wandering.
	currentState = Wander;

	return true;
}

// Checks the transition to the charging behavior.
bool AGuard::CheckTransitionToChargeBehaviour(int a_energyUnder)
{
	// If the guards energy level is below the energy under value.
	if (energy < a_energyUnder)
	{
		// Go charge.
		currentState = Charge;
		return true;
	}
	else
	{
		return false;
	}
}

// Checks the transition to the healing behavior.
bool AGuard::CheckTransitionToHealBehaviour(int a_healthUnder)
{
	// If the guards health is under or equal to the health under value.
	if (health <= a_healthUnder)
	{
		// go heal.
		currentState = Heal;
		return true;
	}
	else
	{
		return false;
	}
}

// Checks the transition to the attack behavior.
bool AGuard::CheckTransitionToAttackBehaviour()
{
	// For all actors in the guards vision.
	for (AActor* actor : actorsInVison)
	{
		// Check if actor is spy.
		ASpy* Spy = Cast<ASpy>(actor);

		// If the actor is a spy.
		if (Spy)
		{
			// Go to attack.
			currentState = Attack;
			return true;
		}
	}

	return false;
}


// Checks the transition to the avoiding toxic waste behavior.
bool AGuard::CheckTransitionToAvoidToxicBehaviour()
{
	// For all actors in the guards vision.
	for (AActor* actor : actorsInVison)
	{
		// Check if actor is toxic spill.
		AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);

		// If the actor is a toxic spill.
		if (toxicSpill)
		{
			// If the guard is close to the spill.
			if (FVector::Dist(toxicSpill->GetActorLocation(), this->GetActorLocation()) < 750.0f)
			{
				// Go to avoid the toxic.
				currentState = AvoidToixc;
				return true;
			}
		}
		break;
	}
	return false;
}

// What the guard should do whilst wandering.
void AGuard::WanderBehaviour()
{
	// If the guard is almost at the location it is headed to.
	if (FVector::Dist(currentPositionHeadingTo, this->GetActorLocation()) < 100.0f)
	{
		// Set a new random location to go to.
		currentPositionHeadingTo = locations[FMath::RandRange(0, locations.IndexOfByKey(locations.Last()))]->GetActorLocation();
		MoveToLocation(currentPositionHeadingTo);
	}
}

// What the guard should do when charging.
void AGuard::ChargeBehaviour()
{
	// If the guard is not headed to the charging location.
	if (currentPositionHeadingTo != chargingLocation->GetActorLocation())
	{
		// Set the guard to go to the charging location.
		currentPositionHeadingTo = chargingLocation->GetActorLocation();
		MoveToLocation(currentPositionHeadingTo);
	}
}

// What the guard does when healing.
void AGuard::HealBehaviour()
{
	// The closest health kit location.
	FVector closestHealthKitLocation;

	// The shortest distance to a health kit.
	float shortestDistance = 10000000.0f;

	// For all the health kits on the map.
	for (AActor* healthKit : healthKitLocations)
	{
		// If the distance from the guard to the health kit is shorter than the current shortest distance.
		if (FVector::Distance(healthKit->GetActorLocation(), this->GetActorLocation()) < shortestDistance)
		{
			// Set the shortest distance to be the distance to the new health kit.
			shortestDistance = FVector::Distance(healthKit->GetActorLocation(), this->GetActorLocation());
			
			// Set the closest health kit location to be that of the new closest health kit.
			closestHealthKitLocation = healthKit->GetActorLocation();
		}
	}

	// If the guard is not currently headed to the location of the closest health kit.
	if (currentPositionHeadingTo != closestHealthKitLocation)
	{
		// Make the guard head to the location of the closest health kit.
		currentPositionHeadingTo = closestHealthKitLocation;
		MoveToLocation(currentPositionHeadingTo);
	}
}

// What the guard does when attacking.
void AGuard::AttackBehaviour()
{
	// For all actors in the vision of the guard.
	for (AActor* actor : actorsInVison)
	{
		// Check if actor is spy.
		ASpy* Spy = Cast<ASpy>(actor);

		// If the actor is a spy.
		if (Spy)
		{
			// Move to the spy.
			currentPositionHeadingTo = Spy->GetActorLocation();
			MoveToLocation(currentPositionHeadingTo);

			// Early out.
			break;
		}
	}

	// Shoot the spy.
	Shoot();
}

// What the guard does when avoiding toxic waste.
void AGuard::AvoidToxicBehaviour()
{
	// Set a new random location to head towards.
	currentPositionHeadingTo = locations[FMath::RandRange(0, locations.IndexOfByKey(locations.Last()))]->GetActorLocation();
	MoveToLocation(currentPositionHeadingTo);
}
