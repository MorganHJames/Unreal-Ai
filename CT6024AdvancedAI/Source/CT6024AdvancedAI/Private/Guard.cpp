// Fill out your copyright notice in the Description page of Project Settings.

#include "Guard.h"
#include "Components/TextRenderComponent.h"
#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
//#include "Math/Vector.h"
//#include "GameFramework/Actor.h"
//#include "Containers/Array.h"
//#include "AIController.h"
//#include "Classes/Blueprint/AIBlueprintHelperLibrary.h"


// Sets default values.
AGuard::AGuard()
{
	// The energy text for the guard.
	EnergyText = CreateDefaultSubobject<UTextRenderComponent>("EnergyText");
}

// Called when the game starts or when spawned.
void AGuard::BeginPlay()
{
	Super::BeginPlay();
	// Set a random position to go to.
	//CurrentPositionHeadingTo = Locations[FMath::RandRange(0, Locations.IndexOfByKey(Locations.Last()))]->GetActorLocation();
	vRandLoc[0] = FVector(350, 350, 270);
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(this->GetController(), vRandLoc[0]);
}

// Changes the guards charge.
void AGuard::Tick(float DeltaTime)
{
	AHumanoid::Tick(DeltaTime);

	if (Charging)
	{
		// Decreases the energy of the guard.
		Energy += DeltaTime * 2.0f;
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
		WanderBehaviour();
		break;
	case AGuard::Charge:
		ChargeBehaviour();
		break;
	case AGuard::Heal:
		HealBehaviour();
		break;
	case AGuard::Attack:
		AttackBehaviour();
		break;
	case AGuard::Wait:
		WaitBehaviour();
		break;
	default:
		WanderBehaviour();
		break;
	}
}

// The functionality of wandering.
void AGuard::WanderBehaviour()
{
	if (FVector::Dist(CurrentPositionHeadingTo, this->GetActorLocation()) < 100.0f)
	{
		//CurrentPositionHeadingTo = LocationPositions[FMath::RandRange(0, LocationPositions.IndexOfByKey(LocationPositions.Last()))];
		//UAIBlueprintHelperLibrary::SimpleMoveToLocation(this->GetController(), CurrentPositionHeadingTo);
	}
}

// The functionality of charging.
void AGuard::ChargeBehaviour()
{
}

// The functionality of healing.
void AGuard::HealBehaviour()
{
}

// The functionality of attacking.
void AGuard::AttackBehaviour()
{
}

// The functionality of waiting.
void AGuard::WaitBehaviour()
{
}

// Called to bind functionality to input
void AGuard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


