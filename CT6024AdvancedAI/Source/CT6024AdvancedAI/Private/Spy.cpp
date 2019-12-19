// Fill out your copyright notice in the Description page of Project Settings.

#include "Spy.h"
#include "SpectateAIGameMode.h"

// Called when the game starts or when spawned.
void ASpy::BeginPlay()
{
	Root = new Selector;// Setup root node.
	GoToLeverAction* goToLever = new GoToLeverAction(true, FVector(0.0f, 0.0f, 0.0f), this);
	Root->AddAction(goToLever);
	Root->Succeeded();
	Super::BeginPlay();
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