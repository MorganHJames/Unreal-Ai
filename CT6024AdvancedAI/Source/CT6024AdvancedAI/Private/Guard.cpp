// Fill out your copyright notice in the Description page of Project Settings.

#include "Guard.h"
#include "Spy.h"
#include "ToxicSpill.h"
#include "Components/TextRenderComponent.h"

// Sets default values.
AGuard::AGuard()
{
	// The energy text for the guard.
	EnergyText = CreateDefaultSubobject<UTextRenderComponent>("EnergyText");
}

// If the guard can see the spy or not.
bool AGuard::CanSeeSpy()
{
	for (AActor* actor : ActorsInVison)
	{
		// Check if actor is spy.
		ASpy* Spy = Cast<ASpy>(actor);

		if (Spy)
		{
			return true;
		}
	}
	return false;
}

// Called when the game starts or when spawned.
void AGuard::BeginPlay()
{
	// Set a random position to go to.
	Energy -= FMath::RandRange(0, 80);
	CurrentPositionHeadingTo = Locations[FMath::RandRange(0, Locations.IndexOfByKey(Locations.Last()))]->GetActorLocation();
	MoveToLocation(CurrentPositionHeadingTo);
	AHumanoid::BeginPlay();
}

// Changes the guards charge and updates the ai.
void AGuard::Tick(float DeltaTime)
{
	AHumanoid::Tick(DeltaTime);

	if (Charging)
	{
		// Decreases the energy of the guard.
		Energy += DeltaTime * 5.0f;
	}
	else
	{
		// Decreases the energy of the guard.
		Energy -= DeltaTime;
	}

	if (Energy > MaxEnergy)
	{
		Energy = MaxEnergy;
	}

	if (Energy <= 0)
	{
		Die();
	}

	//Sets up the text string.
	FString EnergyRemaining = FString::FromInt((int)Energy);

	//Sets the text.
	EnergyText->SetText(EnergyRemaining);

	// Updates the AI.
	UpdateAI();
}

// Holds the state machine for the guard AI.
void AGuard::UpdateAI()
{
	switch (CurrentState)
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

bool AGuard::CheckTransitionToWanderFromChargeBehaviour()
{
	if (Energy >= 100)
	{
		CurrentState = Wander;
		return true;
	}
	else
	{
		return false;
	}
}

bool AGuard::CheckTransitionToWanderFromAttackBehaviour()
{
	for (AActor* actor : ActorsInVison)
	{
		// Check if actor is spy.
		ASpy* Spy = Cast<ASpy>(actor);
		if (Spy)
		{
			return true;
		}
	}

	CurrentState = Wander;
	return false;
}

bool AGuard::CheckTransitionToWanderFromHealBehaviour()
{
	if (Health >= 100)
	{
		CurrentState = Wander;
		return true;
	}
	else
	{
		return false;
	}
}

bool AGuard::CheckTransitionToWanderFromAvoidToxicBehaviour()
{
	for (AActor* actor : ActorsInVison)
	{
		// Check if actor is spy.
		AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);
		if (toxicSpill)
		{
			if (FVector::Dist(toxicSpill->GetActorLocation(), this->GetActorLocation()) < 300.0f)
			{
				return false;
			}
			break;
		}
	}

	CurrentState = Wander;

	return true;
}

bool AGuard::CheckTransitionToChargeBehaviour(int energyUnder)
{
	if (Energy < energyUnder)
	{
		CurrentState = Charge;
		return true;
	}
	else
	{
		return false;
	}
}

bool AGuard::CheckTransitionToHealBehaviour(int healthUnder)
{
	if (Health <= healthUnder)
	{
		CurrentState = Heal;
		return true;
	}
	else
	{
		return false;
	}
}

bool AGuard::CheckTransitionToAttackBehaviour()
{
	for (AActor* actor : ActorsInVison)
	{
		// Check if actor is spy.
		ASpy* Spy = Cast<ASpy>(actor);
		if (Spy)
		{
			CurrentState = Attack;
			return true;
		}
	}

	return false;
}

bool AGuard::CheckTransitionToAvoidToxicBehaviour()
{
	for (AActor* actor : ActorsInVison)
	{
		// Check if actor is spy.
		AToxicSpill* toxicSpill = Cast<AToxicSpill>(actor);
		if (toxicSpill)
		{
			if (FVector::Dist(toxicSpill->GetActorLocation(), this->GetActorLocation()) < 750.0f)
			{
				CurrentState = AvoidToixc;
				return true;
			}
		}
		break;
	}
	return false;
}

// The functionality of wandering.
void AGuard::WanderBehaviour()
{
	if (FVector::Dist(CurrentPositionHeadingTo, this->GetActorLocation()) < 100.0f)
	{
		CurrentPositionHeadingTo = Locations[FMath::RandRange(0, Locations.IndexOfByKey(Locations.Last()))]->GetActorLocation();
		MoveToLocation(CurrentPositionHeadingTo);
	}
}

// The functionality of charging.
void AGuard::ChargeBehaviour()
{
	if (CurrentPositionHeadingTo != ChargingLocation->GetActorLocation())
	{
		CurrentPositionHeadingTo = ChargingLocation->GetActorLocation();
		MoveToLocation(CurrentPositionHeadingTo);
	}
}

// The functionality of healing.
void AGuard::HealBehaviour()
{
	FVector closestHealthKitLocation;
	float shortestDistance = 10000000.0f;

	for (AActor* healthKit : healthKitLocations)
	{
		if (FVector::Distance(healthKit->GetActorLocation(), this->GetActorLocation()) < shortestDistance)
		{
			shortestDistance = FVector::Distance(healthKit->GetActorLocation(), this->GetActorLocation());
			closestHealthKitLocation = healthKit->GetActorLocation();
		}
	}

	if (CurrentPositionHeadingTo != closestHealthKitLocation)
	{
		CurrentPositionHeadingTo = closestHealthKitLocation;
		MoveToLocation(CurrentPositionHeadingTo);
	}
}

// The functionality of attacking.
void AGuard::AttackBehaviour()
{
	for (AActor* actor : ActorsInVison)
	{
		// Check if actor is spy.
		ASpy* Spy = Cast<ASpy>(actor);
		if (Spy)
		{
			CurrentPositionHeadingTo = Spy->GetActorLocation();
			MoveToLocation(CurrentPositionHeadingTo);
			break;
		}
	}
	Shoot();
}

// The functionality of avoiding toxic waste.
void AGuard::AvoidToxicBehaviour()
{
	CurrentPositionHeadingTo = Locations[FMath::RandRange(0, Locations.IndexOfByKey(Locations.Last()))]->GetActorLocation();
	MoveToLocation(CurrentPositionHeadingTo);
}
