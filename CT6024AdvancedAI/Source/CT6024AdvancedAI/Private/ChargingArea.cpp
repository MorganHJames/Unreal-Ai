////////////////////////////////////////////////////////////
// File: ChargingArea.cpp
// Author: Morgan Henry James
// Date Created: ‎15 December ‎2019, ‏‎19:37:20
// Brief: Controls how the guards get their charge when standing on the object that uses this class.
//////////////////////////////////////////////////////////// 

#include "ChargingArea.h"
#include "Guard.h"

// Constructor sets default values for this actor's properties.
AChargingArea::AChargingArea()
{
}

// Called when the game starts or when spawned.
void AChargingArea::BeginPlay()
{
	//Register Events
	OnActorBeginOverlap.AddDynamic(this, &AChargingArea::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AChargingArea::OnOverlapEnd);
	Super::BeginPlay();
}

// Called when an actor starts overlapping.
void AChargingArea::OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it overlaps something.
	if (a_otherActor)
	{
		// Check if it overlaps with a guard.
		AGuard* Guard = Cast<AGuard>(a_otherActor);

		// If the actor is a guard.
		if (Guard)
		{
			// Start charging the guard.
			Guard->charging = true;
		}
	}
}

// Called when an actor stops overlapping.
void AChargingArea::OnOverlapEnd(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it stops overlapping something.
	if (a_otherActor)
	{
		// Check if it stops overlapping with a guard.
		AGuard* Guard = Cast<AGuard>(a_otherActor);

		// If the actor is a guard.
		if (Guard)
		{
			// Stop charging the guard.
			Guard->charging = false;
		}
	}
}