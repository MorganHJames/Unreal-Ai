////////////////////////////////////////////////////////////
// File: ToxicSpill.cpp
// Author: Morgan Henry James
// Date Created: ‎‎‎16 December ‎2019, ‏‎18:22:52
// Brief: Controls the toxic spills on the map turning them on and off randomly.
//////////////////////////////////////////////////////////// 

#include "ToxicSpill.h"
#include "Engine/TriggerBox.h"
#include "Components/StaticMeshComponent.h" 
#include "Humanoid.h"
#include "Engine/StaticMeshActor.h"

// Sets default values.
AToxicSpill::AToxicSpill()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// The trigger box.
	triggerBox = CreateDefaultSubobject<ATriggerBox>("triggerBox");

	// The toxic spillage.
	toxicSpill = CreateDefaultSubobject<UStaticMeshComponent>("ToxicSpill");

	SetRootComponent(toxicSpill);

	// The barrel of toxic waste.
	barrelOfToxicWaste = CreateDefaultSubobject<AStaticMeshActor>("BarrelOfToxicWaste");

	// Randomize the remaining spilled time.
	remainingSpilledTime = FMath::RandRange(5.0f, 30.0f);

	// Randomize the remaining time between spills.
	remainingTimeBetweenSpills = FMath::RandRange(5.0f, 30.0f);
}

// Called when the game starts or when spawned.
void AToxicSpill::BeginPlay()
{
	// Register Events
	triggerBox->OnActorBeginOverlap.AddDynamic(this, &AToxicSpill::OnOverlapBegin);
	triggerBox->OnActorEndOverlap.AddDynamic(this, &AToxicSpill::OnOverlapEnd);
	Super::BeginPlay();
}

// Called every frame.
void AToxicSpill::Tick(float a_deltaTime)
{
	Super::Tick(a_deltaTime);

	// If the barrel is spilled.
	if (isSpilled)
	{
		remainingSpilledTime -= a_deltaTime;

		// Spill barrel over.
		FRotator NewRotation = FRotator(2.0f, 0.0f, 0.0f);
		FQuat QuatRotation = FQuat(NewRotation);
		barrelOfToxicWaste->AddActorLocalRotation(QuatRotation);
		FRotator CurrentBarrelRotation = barrelOfToxicWaste->GetActorRotation();
		if (CurrentBarrelRotation.Pitch > 87.0f)
		{
			FRotator NewLeverRotation = FRotator(87.0f, 0.0f, 0.0f);
			barrelOfToxicWaste->SetActorRotation(NewLeverRotation);
		}

		// Rise the toxic waste.
		FVector NewLocation = toxicSpill->GetComponentLocation();
		NewLocation.Z = -5.0f;
		toxicSpill->SetWorldLocation(NewLocation);

		// For each humanoid damage health by DeltaTime.
		for (AHumanoid* Humanoid : humanoids)
		{
			Humanoid->ChangeHealth(-a_deltaTime);
		}

		// Stop spilling.
		if (remainingSpilledTime <= 0.0f)
		{
			remainingSpilledTime = FMath::RandRange(5.0f, 30.0f);
			isSpilled = false;
		}
	}

	// If the barrel is not spilled.
	if (!isSpilled)
	{
		remainingTimeBetweenSpills -= a_deltaTime;

		// Unspill barrel over.
		FRotator NewRotation = FRotator(-2.0f, 0.0f, 0.0f);
		FQuat QuatRotation = FQuat(NewRotation);
		barrelOfToxicWaste->AddActorLocalRotation(QuatRotation);
		FRotator CurrentBarrelRotation = barrelOfToxicWaste->GetActorRotation();
		if (CurrentBarrelRotation.Pitch < 0.0f)
		{
			FRotator NewLeverRotation = FRotator(0.0f, 0.0f, 0.0f);
			barrelOfToxicWaste->SetActorRotation(NewLeverRotation);
		}

		// Lower the toxic waste.
		FVector NewLocation = toxicSpill->GetComponentLocation();
		NewLocation.Z = -15.0f;
		toxicSpill->SetWorldLocation(NewLocation);

		// Start spilling.
		if (remainingTimeBetweenSpills <= 0.0f)
		{
			remainingTimeBetweenSpills = FMath::RandRange(20.0f, 50.0f);;
			isSpilled = true;
		}
	}
}

// Called when an actor starts overlapping.
void AToxicSpill::OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it overlaps something.
	if (a_otherActor)
	{
		// Check if it overlaps with a humanoid.
		AHumanoid* Humanoid = Cast<AHumanoid>(a_otherActor);
		if (Humanoid)
		{
			// Add humanoid to array of humanoids.
			humanoids.Add(Humanoid);
		}
	}
}

// Called when an actor stops overlapping.
void AToxicSpill::OnOverlapEnd(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it stops overlapping something.
	if (a_otherActor)
	{
		// Check if it overlaps with a humanoid.
		AHumanoid* Humanoid = Cast<AHumanoid>(a_otherActor);
		if (Humanoid)
		{
			// Remove humanoid from list of humanoids.
			humanoids.Remove(Humanoid);
		}
	}
}
