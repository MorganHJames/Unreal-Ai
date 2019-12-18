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
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* EnergyText;

	UPROPERTY(EditAnywhere, Category = "Locations")
	TArray<class AActor*> Locations;
	FVector CurrentPositionHeadingTo;

	UPROPERTY(EditAnywhere, Category = "Locations")
	class AActor* ChargingLocation;

	FVector ree = FVector(0.f, 0.f, 0.f);
	FVector vRandLoc[1];

	float Energy = 100.0f;
	float MaxEnergy = 100.0f;

	void UpdateAI();

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	enum States { Wander, Charge, Heal, Attack, Wait };

	States CurrentState = States::Wander;

	void WanderBehaviour();
	void ChargeBehaviour();
	void HealBehaviour();
	void AttackBehaviour();
	void WaitBehaviour();
};
