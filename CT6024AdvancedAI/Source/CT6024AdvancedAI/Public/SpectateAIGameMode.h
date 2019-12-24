////////////////////////////////////////////////////////////
// File: SpectateAIGameMode.h
// Author: Morgan Henry James
// Date Created: ‎15 December ‎2019, ‏‎21:03:26
// Brief: Declaration of the self destruct lever class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SpectateAIGameMode.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API ASpectateAIGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// Indicates that the guards have won.
	void GuardsWin();

	// Indicates that the spy won.
	void SpyWin();
};
