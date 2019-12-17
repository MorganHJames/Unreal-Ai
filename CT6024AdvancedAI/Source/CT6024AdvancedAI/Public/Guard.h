// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Humanoid.h"
#include "Guard.generated.h"

/**
 * 
 */
UCLASS()
class CT6024ADVANCEDAI_API AGuard : public AHumanoid
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties
	AGuard();

	bool Charging = false;

protected:
	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* EnergyText;

	float Energy = 100.0f;
	float MaxEnergy = 100.0f;

	void UpdateAI();

	virtual void Tick(float DeltaTime) override;

	enum States { Wander, Charge, Heal, Attack, Wait };

	States CurrentState = States::Wander;

	void WanderBehaviour();
	void ChargeBehaviour();
	void HealBehaviour();
	void AttackBehaviour();
	void WaitBehaviour();
};
