// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Humanoid.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AHumanoid : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHumanoid();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override; 

	void Shoot();

	UPROPERTY(EditAnywhere, Category = "Shooting")
	TSubclassOf<class ABullet> BulletClass;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* HealthText;

	float Health = 100.0f;
	float MaxHealth = 100.0f;
	float CurrentChargeTimeRemaining = 0.0f;
	float ChargeTime = 2.0f;
	bool CanShoot = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ChangeHealth(float HealthChange);

	virtual void Die();
};