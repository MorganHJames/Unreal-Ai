// Fill out your copyright notice in the Description page of Project Settings.

#include "Spy.h"
#include "SpectateAIGameMode.h"
#include "SelfDestructLever.h"

// Called when the game starts or when spawned.
void ASpy::BeginPlay()
{
	CurrentPositionHeadingTo = GetActorLocation();
	Root = new Sequence;// Setup root node.
	GoToLeverAction* goToLever = new GoToLeverAction(this);
	SearchForLeverAction* searchForLever = new SearchForLeverAction(this);
	Root->AddAction(searchForLever);
	Root->AddAction(goToLever);
	Super::BeginPlay();
}

void ASpy::Tick(float DeltaTime)
{
	AHumanoid::Tick(DeltaTime);
	Root->Update();
}

// Kills the spy.
void ASpy::Die()
{
	if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
	{
		GM->GuardsWin();
	}
	Destroy();
}

// Checks if the spy knows the location of the lever.
bool ASpy::DoesSpyKnowLeverLocation()
{
	for (AActor* actor : ActorsSeen)
	{
		ASelfDestructLever* lever = Cast<ASelfDestructLever>(actor);

		if (lever)
		{
			return true;
		}
	}
	
	return false;
}

FVector ASpy::GetLeverLocation()
{
	for (AActor* actor : ActorsSeen)
	{
		ASelfDestructLever* lever = Cast<ASelfDestructLever>(actor);

		if (lever)
		{
			return lever->GetActorLocation();
		}
	}

	return FVector(0.0f, 0.0f, 0.0f);
}
