// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <list>
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

	UPROPERTY(EditAnywhere, Category = "References")
	class ATriggerBox* VisionBox;

	TArray<class AActor*> ActorsInVisonBox;
	TArray<class AActor*> ActorsInVison;

	float Health = 100.0f;
	float MaxHealth = 100.0f;
	float CurrentChargeTimeRemaining = 0.0f;
	float ChargeTime = 2.0f;
	bool CanShoot = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ChangeHealth(float HealthChange);

	virtual void Die();

	void MoveToLocation(FVector LocationToGoTo);

	// declare overlap begin function.
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// declare overlap end function.
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);

	static bool Trace(UWorld* world, AActor* actorToIgnore, const FVector& start, const FVector& dir, float length, FHitResult& hit, ECollisionChannel CollisionChannel = ECC_Pawn, bool ReturnPhysMat = false);
	static bool Trace(UWorld* world, AActor* actorToIgnore, const FVector& start, const FVector& end, FHitResult& hit, ECollisionChannel CollisionChannel = ECC_Pawn, bool ReturnPhysMat = false);
};
