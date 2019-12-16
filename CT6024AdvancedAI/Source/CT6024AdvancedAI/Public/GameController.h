// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameController.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AGameController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameController();

	static bool GuardVicory;
	static bool SpyVicory;

	bool GameEnded = false;
	float EndTime = 5.0f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The rocket.
	UPROPERTY(EditAnywhere, Category = "References")
	class AStaticMeshActor* Rocket;

	UPROPERTY(EditAnywhere, Category = "References")
	class AStaticMeshActor* Lever;

	// The count down billboard.
	UPROPERTY(EditAnywhere, Category = "References")
	class ANukeCountdown* CountDownBillboard;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GuardVicorySequence();
	void SpyVicorySequence();
	void ResetGame();
};
