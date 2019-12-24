////////////////////////////////////////////////////////////
// File: Locker.cpp
// Author: Morgan Henry James
// Date Created: ‎16 December ‎2019, ‏‎04:58:49
// Brief: Controls the interactions between the spy and the locker.
//////////////////////////////////////////////////////////// 

#include "Locker.h"
#include "Spy.h"
#include "Engine/TriggerBox.h"
#include "Components/StaticMeshComponent.h" 

// Turns ticks on and sets up the trigger and the locker mesh.
ALocker::ALocker()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// The trigger box.
	triggerBox = CreateDefaultSubobject<ATriggerBox>("triggerBox");

	// The locker.
	locker = CreateDefaultSubobject<UStaticMeshComponent>("locker");
}

// Called when the game starts or when spawned
void ALocker::BeginPlay()
{
	// Register Events.
	triggerBox->OnActorBeginOverlap.AddDynamic(this, &ALocker::OnOverlapBegin);
	triggerBox->OnActorEndOverlap.AddDynamic(this, &ALocker::OnOverlapEnd);
	Super::BeginPlay();
}

// Called when an actor starts overlapping.
void ALocker::OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it overlaps something.
	if (a_otherActor)
	{
		// Check if it overlaps with a spy.
		ASpy* Spy = Cast<ASpy>(a_otherActor);

		// If the actor is a spy.
		if (Spy)
		{
			// Set the lockers reference to the spy.
			spy = Spy;

			// Indicates to the spy that it can hide.
			spy->canHide = true;
		}
	}
}

// Called when an actor stops overlapping.
void ALocker::OnOverlapEnd(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it stops overlapping something.
	if (a_otherActor)
	{
		// Check if it stops overlapping with a spy.
		ASpy* Spy = Cast<ASpy>(a_otherActor);

		// If the spy leaves lockers trigger box.
		if (Spy && Spy == spy)
		{
			// Indicates to the spy that it can no longer hide.
			spy->canHide = false;

			// Removes the reference to the spy.
			spy = nullptr;
		}
	}
}

// Called every frame.
void ALocker::Tick(float a_deltaTime)
{
	Super::Tick(a_deltaTime);

	// If the locker has a reference to the spy.
	if (spy)
	{
		// Moves the spy in the locker if the spy indicates it wants to hide.
		if (spy->canHide && spy->isHiding && !lockerFull)
		{
			lockerFull = true;
			spyPreviousLocation = spy->GetTransform();
			spy->SetActorLocation(locker->GetComponentLocation());
			spy->GetRootComponent()->SetMobility(EComponentMobility::Type::Static);
			spy->canHide = false;
		}

		// Moves the spy out of the locker if the spy indicates it wants to leave.
		if (!spy->canHide && !spy->isHiding && lockerFull)
		{
			lockerFull = false;
			spy->GetRootComponent()->SetMobility(EComponentMobility::Type::Movable);
			spy->SetActorTransform(spyPreviousLocation);
			spy->canHide = true;
		}
	}
}