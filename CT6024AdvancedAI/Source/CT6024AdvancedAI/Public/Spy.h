// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Humanoid.h"
#include "Spy.generated.h"

/**
 * 
 */
UCLASS()
class CT6024ADVANCEDAI_API ASpy : public AHumanoid
{
	GENERATED_BODY()

public:
	bool CanHide = false;
	bool IsHiding = false;
	virtual void Die() override;
};
