// Fill out your copyright notice in the Description page of Project Settings.


#include "ChargingArea.h"
#include "Guard.h"

AChargingArea::AChargingArea()
{
}

// Called when the game starts or when spawned
void AChargingArea::BeginPlay()
{
	//Register Events
	OnActorBeginOverlap.AddDynamic(this, &AChargingArea::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AChargingArea::OnOverlapEnd);
	Super::BeginPlay();
}

// Called when an actor starts overlapping.
void AChargingArea::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it overlaps something.
	if (OtherActor)
	{
		// Check if it overlaps with a guard.
		AGuard* Guard = Cast<AGuard>(OtherActor);
		if (Guard)
		{
			// Start charging the guard.
			Guard->Charging = true;
		}
	}
}

// Called when an actor stops overlapping.
void AChargingArea::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it stops overlapping something.
	if (OtherActor)
	{
		// Check if it stops overlapping with a guard.
		AGuard* Guard = Cast<AGuard>(OtherActor);
		if (Guard)
		{
			// Stop charging the guard.
			Guard->Charging = false;
		}
	}
}