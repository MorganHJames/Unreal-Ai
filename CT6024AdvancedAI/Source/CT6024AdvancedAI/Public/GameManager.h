﻿////////////////////////////////////////////////////////////
// File: GameManager.h
// Author: Morgan Henry James
// Date Created: ‎‎‎14 December ‎2019, ‏‎17:27:18
// Brief: Declaration of the game manager class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AGameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties.
	AGameManager();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:	
	// Called every frame.
	virtual void Tick(float DeltaTime) override;
};
