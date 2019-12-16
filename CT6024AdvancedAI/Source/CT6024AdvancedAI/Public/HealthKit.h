// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthKit.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AHealthKit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHealthKit();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The horizontal part of the health kit.
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* HorizontalMesh;

	// The vertical part of the health kit.
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* VerticalMesh;

	float FloatingDistance = 10.0f;
	float FloatingSpeed = 10.0f;
	bool GoingUp = true;
	FVector StartingLocation;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnHealthKitHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit);
};
