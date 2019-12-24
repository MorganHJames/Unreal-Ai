////////////////////////////////////////////////////////////
// File: HealthKit.cpp
// Author: Morgan Henry James
// Date Created: ‎15 December ‎2019, ‏‎18:00:57
// Brief: Controls how health kits can be interacted with.
//////////////////////////////////////////////////////////// 

#include "HealthKit.h"
#include "Components/StaticMeshComponent.h" 
#include "Humanoid.h"

// Sets default values.
AHealthKit::AHealthKit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// The horizontal mesh of the health kit.
	horizontalMesh = CreateDefaultSubobject<UStaticMeshComponent>("horizontalMesh");

	// Set the root.
	SetRootComponent(horizontalMesh);

	// The vertical mesh of the health kit.
	verticalMesh = CreateDefaultSubobject<UStaticMeshComponent>("verticalMesh");
}

// Called when the game starts or when spawned.
void AHealthKit::BeginPlay()
{
	// Add the on health kit hit event to the health kit.
	OnActorHit.AddDynamic(this, &AHealthKit::OnHealthKitHit);

	// Set the starting location of the health kit.
	startingLocation = GetActorLocation();
	Super::BeginPlay();
}

// Called every frame.
void AHealthKit::Tick(float a_deltaTime)
{
	Super::Tick(a_deltaTime);

	// Sets the new location to the actors current location.
	FVector NewLocation = GetActorLocation();

	// If the health should be going up.
	if (goingUp)
	{
		// Move the health kit up.
		NewLocation.Z += (a_deltaTime * floatingSpeed);

		// If the health kit is too high.
		if (NewLocation.Z - startingLocation.Z > floatingDistance)
		{
			// Indicate for the health kit to go down.
			goingUp = false;
		}
	}
	else
	{
		// Move the health kit down.
		NewLocation.Z -= (a_deltaTime * floatingSpeed);

		// If the health kit is too low.
		if (NewLocation.Z - startingLocation.Z < -floatingDistance)
		{
			// Indicate for the health kit to go up.
			goingUp = true;
		}
	}

	// Set the actors location to the new location.
	SetActorLocation(NewLocation);
}

// Heal the player if they collide with the health kit.
void AHealthKit::OnHealthKitHit(AActor* a_selfActor, AActor* a_otherActor, FVector a_normalImpulse, const FHitResult& a_hit)
{
	// Check if it hits something.
	if (a_otherActor)
	{
		// Check if it hits a human.
		AHumanoid* humanoid = Cast<AHumanoid>(a_otherActor);

		// If the actor is a humanoid.
		if (humanoid)
		{
			// Increase the hit humans health.
			humanoid->ChangeHealth(100.0f);
		}
	}
}

