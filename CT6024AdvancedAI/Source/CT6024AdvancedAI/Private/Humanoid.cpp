// Fill out your copyright notice in the Description page of Project Settings.

#include "Humanoid.h"
#include "Bullet.h"
#include <Runtime\Engine\Classes\Engine\World.h>
#include "Components/TextRenderComponent.h"

// Sets default values
AHumanoid::AHumanoid()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//The health text for the humanoid.
	HealthText = CreateDefaultSubobject<UTextRenderComponent>("HealthText"); 
}

// Called when the game starts or when spawned
void AHumanoid::BeginPlay()
{
	Super::BeginPlay();
}

// Spawns a bullet that moves forward.
void AHumanoid::Shoot()
{
	// If a bullet has been set.
	if (BulletClass && CanShoot)
	{
		CanShoot = false;
		CurrentChargeTimeRemaining = ChargeTime;
		// Set up spawning parameters.
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParameters.bNoFail = true;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = this;

		// Set up bullet transform.
		FTransform BulletSpawnTransform;
		BulletSpawnTransform.SetLocation(GetActorForwardVector() * 50.0f + GetActorLocation() + FVector(0.f,0.f, 75.0f));
		BulletSpawnTransform.SetRotation(GetActorRotation().Quaternion());

		// Spawn the bullet.
		GetWorld()->SpawnActor<ABullet>(BulletClass, BulletSpawnTransform, SpawnParameters);
	}
}

// Called every frame
void AHumanoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Stops rapid fire.
	CurrentChargeTimeRemaining -= DeltaTime;

	if (CurrentChargeTimeRemaining < 0.0f)
	{
		CanShoot = true;
	}
}

// Called to bind functionality to input
void AHumanoid::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Changes the health of the humanoid.
void AHumanoid::ChangeHealth(float HealthChange)
{
	Health += HealthChange;

	if (Health > MaxHealth)
	{
		Health = MaxHealth;
	}

	if (Health <= 0.0f)
	{
		Die();
	}

	//Sets up the text string.
	FString RemainingHealth = FString::FromInt((int)Health);

	//Sets the text.
	HealthText->SetText(RemainingHealth);
}

// Kills the humanoid.
void AHumanoid::Die()
{
	Destroy();
}

