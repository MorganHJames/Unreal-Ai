////////////////////////////////////////////////////////////
// File: GameController.h
// Author: Morgan Henry James
// Date Created: ‎‎16 December ‎2019, ‏‎00:20:58
// Brief: Declaration of the game controller class.
//////////////////////////////////////////////////////////// 

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

	// True when the guards win.
	static bool guardVictory;

	// True when the spy wins.
	static bool spyVictory;

	// The current time for level.
	static float currentTime;

	// True when the game has ended.
	bool gameEnded = false;

	// The time between ending the gaming and restarting the game.
	float endTime = 5.0f;

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// The rocket.
	UPROPERTY(EditAnywhere, Category = "References")
	class AStaticMeshActor* rocket;

	// The lever the spy needs to pull.
	UPROPERTY(EditAnywhere, Category = "References")
	class AStaticMeshActor* lever;

	// The count down billboard.
	UPROPERTY(EditAnywhere, Category = "References")
	class ANukeCountdown* countDownBillboard;

public:	
	// Called every frame.
	virtual void Tick(float DeltaTime) override;

	// Called when the guards win.
	void GuardVicorySequence();

	// Called when the spy wins.
	void SpyVicorySequence();

	// Resets the game.
	void ResetGame();
};
