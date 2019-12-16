// Fill out your copyright notice in the Description page of Project Settings.


#include "SpectateAIGameMode.h"
#include "GameController.h"

void ASpectateAIGameMode::GuardsWin()
{
	AGameController::GuardVicory = true;
}

void ASpectateAIGameMode::SpyWin()
{
	AGameController::SpyVicory = true;
}
