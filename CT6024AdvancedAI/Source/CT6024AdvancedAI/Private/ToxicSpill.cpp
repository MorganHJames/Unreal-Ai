// Fill out your copyright notice in the Description page of Project Settings.

#include "ToxicSpill.h"
#include "Engine/TriggerBox.h"
#include "Components/StaticMeshComponent.h" 
#include "Humanoid.h"

// Sets default values
AToxicSpill::AToxicSpill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//The trigger box.
	TriggerBox = CreateDefaultSubobject<ATriggerBox>("TriggerBox");

	//The toxic spillage.
	ToxicSpill = CreateDefaultSubobject<UStaticMeshComponent>("ToxicSpill");

	//The barrel of toxic waste.
	BarrelOfToxicWaste = CreateDefaultSubobject<UStaticMeshComponent>("BarrelOfToxicWaste");

	RemainingSpilledTime = FMath::RandRange(5.0f, 30.0f);

	RemainingTimeBetweenSpills = FMath::RandRange(0.0f, 50.0f);
}

// Called when the game starts or when spawned
void AToxicSpill::BeginPlay()
{
	//Register Events
	TriggerBox->OnActorBeginOverlap.AddDynamic(this, &AToxicSpill::OnOverlapBegin);
	TriggerBox->OnActorEndOverlap.AddDynamic(this, &AToxicSpill::OnOverlapEnd);
	Super::BeginPlay();
}

// Called every frame
void AToxicSpill::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// If the barrel is spilled.
	if (IsSpilled)
	{
		RemainingSpilledTime -= DeltaTime;

		// Spill barrel over.

		// Rise the toxic waste.

		// For each humanoid damage health by DeltaTime.
		for (AHumanoid* Humanoid : Humanoids)
		{
			Humanoid->ChangeHealth(-DeltaTime);
		}

		// Stop spilling.
		if (RemainingSpilledTime <= 0.0f)
		{
			RemainingSpilledTime = FMath::RandRange(5.0f, 30.0f);
			IsSpilled = false;
		}
	}

	// If the barrel is not spilled.
	if (!IsSpilled)
	{
		RemainingTimeBetweenSpills -= DeltaTime;

		// Unspill barrel over.

		// Lower the toxic waste.

		// Start spilling.
		if (RemainingTimeBetweenSpills <= 0.0f)
		{
			RemainingTimeBetweenSpills = FMath::RandRange(20.0f, 50.0f);;
			IsSpilled = true;
		}
	}
}

// Called when an actor starts overlapping.
void AToxicSpill::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it overlaps something.
	if (OtherActor)
	{
		// Check if it overlaps with a humanoid.
		AHumanoid* Humanoid = Cast<AHumanoid>(OtherActor);
		if (Humanoid)
		{
			// Add humanoid to array of humanoids.
			Humanoids.Add(Humanoid);
		}
	}
}

// Called when an actor stops overlapping.
void AToxicSpill::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it stops overlapping something.
	if (OtherActor)
	{
		// Check if it overlaps with a humanoid.
		AHumanoid* Humanoid = Cast<AHumanoid>(OtherActor);
		if (Humanoid)
		{
			// Remove humanoid from list of humanoids.
			Humanoids.Remove(Humanoid);
		}
	}
}
