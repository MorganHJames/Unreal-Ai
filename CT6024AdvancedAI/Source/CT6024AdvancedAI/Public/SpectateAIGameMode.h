// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "SpectateAIGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CT6024ADVANCEDAI_API ASpectateAIGameMode : public AGameMode
{
	GENERATED_BODY()

protected:

public:
	void GuardsWin();
	void SpyWin();
};
