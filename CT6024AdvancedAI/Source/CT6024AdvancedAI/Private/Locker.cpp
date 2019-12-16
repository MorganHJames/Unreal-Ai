// Fill out your copyright notice in the Description page of Project Settings.

#include "Locker.h"
#include "Spy.h"
#include "Engine/TriggerBox.h"
#include "Components/StaticMeshComponent.h" 

ALocker::ALocker()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//The trigger box.
	TriggerBox = CreateDefaultSubobject<ATriggerBox>("TriggerBox");

	//The locker.
	Locker = CreateDefaultSubobject<UStaticMeshComponent>("Locker");
}

// Called when the game starts or when spawned
void ALocker::BeginPlay()
{
	//Register Events
	TriggerBox->OnActorBeginOverlap.AddDynamic(this, &ALocker::OnOverlapBegin);
	TriggerBox->OnActorEndOverlap.AddDynamic(this, &ALocker::OnOverlapEnd);
	Super::BeginPlay();
}

// Called when an actor starts overlapping.
void ALocker::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it overlaps something.
	if (OtherActor)
	{
		// Check if it overlaps with a spy.
		ASpy* Spy = Cast<ASpy>(OtherActor);
		if (Spy)
		{
			TheSpy = Spy;
			TheSpy->CanHide = true;
		}
	}
}

// Called when an actor stops overlapping.
void ALocker::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it stops overlapping something.
	if (OtherActor)
	{
		// Check if it stops overlapping with a spy.
		ASpy* Spy = Cast<ASpy>(OtherActor);
		if (Spy && Spy == TheSpy)
		{
			TheSpy->CanHide = false;
			TheSpy = nullptr;
		}
	}
}

// Called every frame
void ALocker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TheSpy)
	{
		// Moves the spy in the locker.
		if (TheSpy->CanHide && TheSpy->IsHiding && !LockerFull)
		{
			LockerFull = true;
			SpyPreviousLocation = TheSpy->GetTransform();
			TheSpy->SetActorLocation(Locker->GetComponentLocation());
			TheSpy->GetRootComponent()->SetMobility(EComponentMobility::Type::Static);
			TheSpy->CanHide = false;
		}

		// Moves the spy out of the locker.
		if (!TheSpy->CanHide && !TheSpy->IsHiding && LockerFull)
		{
			LockerFull = false;
			TheSpy->GetRootComponent()->SetMobility(EComponentMobility::Type::Movable);
			TheSpy->SetActorTransform(SpyPreviousLocation);
			TheSpy->CanHide = true;
		}
	}
}