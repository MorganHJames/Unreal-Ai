// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NukeCountdown.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API ANukeCountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANukeCountdown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* Background;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* CountDownText;

	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* InfoText;

	float TimeRemaining = 60.0f;

	bool Countdown = true;

	void DisplayRestartingText();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void DisplayGuardWin();

	void DisplaySpyWin();
};
