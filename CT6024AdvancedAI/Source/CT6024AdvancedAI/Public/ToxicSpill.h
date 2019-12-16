// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToxicSpill.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AToxicSpill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AToxicSpill();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Reference")
	class ATriggerBox* TriggerBox;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* ToxicSpill;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* BarrelOfToxicWaste;

	TArray<class AHumanoid*> Humanoids;

	bool IsSpilled = false;

	float RemainingSpilledTime;

	float RemainingTimeBetweenSpills;

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
