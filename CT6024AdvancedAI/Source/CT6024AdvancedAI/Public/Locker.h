// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Locker.generated.h"

/**
 * 
 */
UCLASS()
class CT6024ADVANCEDAI_API ALocker : public AActor
{
	GENERATED_BODY()
public:
	// Turn ticks on.
	ALocker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class ASpy* TheSpy;

	FTransform SpyPreviousLocation;

	bool LockerFull = false;

	UPROPERTY(EditAnywhere, Category = "Reference")
	class ATriggerBox* TriggerBox;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* Locker;
	
public:

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	// declare overlap end function
	UFUNCTION()
	void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
};
