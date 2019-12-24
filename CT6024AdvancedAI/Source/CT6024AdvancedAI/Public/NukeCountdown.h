////////////////////////////////////////////////////////////
// File: NukeCountdown.h
// Author: Morgan Henry James
// Date Created: ‎‎14 December ‎2019, ‏‎03:19:43
// Brief: Declaration of the nuke countdown class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NukeCountdown.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API ANukeCountdown : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties.
	ANukeCountdown();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// The background mesh for the bill board.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* background;

	// The text that has the number indicating the time left until a rocket launch happens.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* countDownText;

	// The text that indicates what the timer indicates.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* infoText;

	// The time until the rocket launches.
	float timeRemaining = 60.0f;

	// True when the timer is counting down to launch.
	bool countdown = true;

	// Called when restarting the level to indicate that it is doing so.
	void DisplayRestartingText();

public:	
	// Called every frame.
	virtual void Tick(float a_deltaTime) override;

	// Displays the guards winning text on the billboard.
	void DisplayGuardWin();

	// Displays the spy winning text on the billboard.
	void DisplaySpyWin();
};
