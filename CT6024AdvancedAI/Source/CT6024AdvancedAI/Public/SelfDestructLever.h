// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SelfDestructLever.generated.h"

/**
 * 
 */
UCLASS()
class CT6024ADVANCEDAI_API ASelfDestructLever : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* LeverBase;

	UPROPERTY(EditAnywhere, Category = "Reference")
	class ATriggerBox* TriggerBox;

public:

	// constructor sets default values for this actor's properties
	ASelfDestructLever();

	// declare overlap begin function
	UFUNCTION()
	void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
};
