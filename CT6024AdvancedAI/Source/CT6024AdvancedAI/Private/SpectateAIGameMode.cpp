////////////////////////////////////////////////////////////
// File: SpectateAIGameMode.cpp
// Author: Morgan Henry James
// Date Created: ‎15 December ‎2019, ‏‎21:03:26
// Brief: Sets the states of victory.
//////////////////////////////////////////////////////////// 

#include "SpectateAIGameMode.h"
#include "GameController.h"

// Indicates that the guards have won.
void ASpectateAIGameMode::GuardsWin()
{
	AGameController::guardVictory = true;
}

// Indicates that the spy won.
void ASpectateAIGameMode::SpyWin()
{
	AGameController::spyVictory = true;
}
