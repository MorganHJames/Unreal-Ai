// Fill out your copyright notice in the Description page of Project Settings.


#include "SelfDestructLever.h"
#include "Spy.h"
#include "SpectateAIGameMode.h"

ASelfDestructLever::ASelfDestructLever()
{
}

// Called when the game starts or when spawned
void ASelfDestructLever::BeginPlay()
{
	//Register Events
	OnActorBeginOverlap.AddDynamic(this, &ASelfDestructLever::OnOverlapBegin);
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