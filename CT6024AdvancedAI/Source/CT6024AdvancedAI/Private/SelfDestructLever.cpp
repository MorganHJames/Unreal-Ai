////////////////////////////////////////////////////////////
// File: SelfDestructLever.cpp
// Author: Morgan Henry James
// Date Created: ‎‎‎15 December ‎2019, ‏‎22:36:28
// Brief: Controls the lever trigger box.
//////////////////////////////////////////////////////////// 

#include "SelfDestructLever.h"
#include "Spy.h"
#include "Engine/TriggerBox.h"
#include "SpectateAIGameMode.h"
#include "Components/StaticMeshComponent.h" 

// Sets up the components.
ASelfDestructLever::ASelfDestructLever()
{
	//The lever base.
	leverBase = CreateDefaultSubobject<UStaticMeshComponent>("LeverBase");

	//The trigger box.
	triggerBox = CreateDefaultSubobject<ATriggerBox>("triggerBox");
}

// Called when the game starts or when spawned.
void ASelfDestructLever::BeginPlay()
{
	// Register Events.
	triggerBox->OnActorBeginOverlap.AddDynamic(this, &ASelfDestructLever::OnOverlapBegin);
	Super::BeginPlay();
}

// Called when an actor starts overlapping.
void ASelfDestructLever::OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it overlaps something.
	if (a_otherActor)
	{
		// Check if it overlaps with a spy.
		ASpy* Spy = Cast<ASpy>(a_otherActor);

		// If the actor is a spy.
		if (Spy)
		{
			if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
			{
				// Indicate that the spy won.
				GM->SpyWin();
			}
		}
	}
}