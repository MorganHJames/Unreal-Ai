// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfDestructLever.h"
#include "Spy.h"
#include "Engine/TriggerBox.h"
#include "SpectateAIGameMode.h"
#include "Components/StaticMeshComponent.h" 

ASelfDestructLever::ASelfDestructLever()
{
	//The lever base.
	LeverBase = CreateDefaultSubobject<UStaticMeshComponent>("LeverBase");

	SetRootComponent(LeverBase);

	//The trigger box.
	TriggerBox = CreateDefaultSubobject<ATriggerBox>("TriggerBox");
}

// Called when the game starts or when spawned
void ASelfDestructLever::BeginPlay()
{
	//Register Events
	TriggerBox->OnActorBeginOverlap.AddDynamic(this, &ASelfDestructLever::OnOverlapBegin);
	Super::BeginPlay();
}

// Called when an actor starts overlapping.
void ASelfDestructLever::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it overlaps something.
	if (OtherActor)
	{
		// Check if it overlaps with a spy.
		ASpy* Spy = Cast<ASpy>(OtherActor);
		if (Spy)
		{
			if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
			{
				GM->SpyWin();
			}
		}
	}
}