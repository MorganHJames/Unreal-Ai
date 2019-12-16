// Fill out your copyright notice in the Description page of Project Settings.

#include "Spy.h"
#include "SpectateAIGameMode.h"

// Kills the spy.
void ASpy::Die()
{
	if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
	{
		GM->GuardsWin();
	}
	Destroy();
}