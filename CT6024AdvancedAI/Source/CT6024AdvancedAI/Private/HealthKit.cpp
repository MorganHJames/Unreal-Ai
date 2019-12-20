// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthKit.h"
#include "Components/StaticMeshComponent.h" 
#include "Humanoid.h"

// Sets default values
AHealthKit::AHealthKit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HorizontalMesh = CreateDefaultSubobject<UStaticMeshComponent>("HorizontalMesh");

	// Set the root.
	SetRootComponent(HorizontalMesh);

	VerticalMesh = CreateDefaultSubobject<UStaticMeshComponent>("VerticalMesh");
}

// Called when the game starts or when spawned
void AHealthKit::BeginPlay()
{
	OnActorHit.AddDynamic(this, &AHealthKit::OnHealthKitHit);
	StartingLocation = GetActorLocation();
	Super::BeginPlay();
}

// Called every frame
void AHealthKit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();

	if (GoingUp)
	{
		NewLocation.Z += (DeltaTime * FloatingSpeed);
		if (NewLocation.Z - StartingLocation.Z > FloatingDistance)
		{
			GoingUp = false;
		}
	}
	else
	{
		NewLocation.Z -= (DeltaTime * FloatingSpeed);
		if (NewLocation.Z - StartingLocation.Z < -FloatingDistance)
		{
			GoingUp = true;
		}
	}

	SetActorLocation(NewLocation);
}

// Heal the player if they collide with the health kit.
void AHealthKit::OnHealthKitHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	// Check if it hits something.
	if (OtherActor)
	{
		// Check if it hits a human.
		AHumanoid* humanoid = Cast<AHumanoid>(OtherActor);
		if (humanoid)
		{
			// Increase the hit humans health.
			humanoid->ChangeHealth(100.0f);
		}
	}
}

