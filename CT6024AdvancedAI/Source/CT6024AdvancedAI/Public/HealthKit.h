////////////////////////////////////////////////////////////
// File: HealthKit.h
// Author: Morgan Henry James
// Date Created: ‎15 December ‎2019, ‏‎18:00:57
// Brief: Declaration of the health kit class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HealthKit.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AHealthKit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties.
	AHealthKit();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// The horizontal part of the health kit.
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* horizontalMesh;

	// The vertical part of the health kit.
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* verticalMesh;

	// The distance that the health kit should be able to float up and down.
	float floatingDistance = 10.0f;

	// The speed at which the health kit should float up and down.
	float floatingSpeed = 10.0f;

	// True when the health kit is floating up.
	bool goingUp = true;

	// The starting location of the health kit.
	FVector startingLocation;

public:	
	// Called every frame.
	virtual void Tick(float a_deltaTime) override;

	// The on hit functionality of the health kit.
	UFUNCTION()
	void OnHealthKitHit(AActor* a_selfActor, AActor* a_otherActor, FVector a_normalImpulse, const FHitResult& a_hit);
};
