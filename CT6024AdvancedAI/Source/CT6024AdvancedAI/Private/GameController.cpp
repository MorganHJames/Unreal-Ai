////////////////////////////////////////////////////////////
// File: GameController.cpp
// Author: Morgan Henry James
// Date Created: ‎‎16 December ‎2019, ‏‎00:20:58
// Brief: Controls how the game ends.
//////////////////////////////////////////////////////////// 

#include "GameController.h"
#include "Engine/StaticMeshActor.h"
#include "NukeCountdown.h"
#include "SpectateAIGameMode.h"

// Initialize static variables.
bool AGameController::guardVictory = false;
bool AGameController::spyVictory = false;
float AGameController::currentTime = 0.0f;

// Sets default values.
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned.
void AGameController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame.
void AGameController::Tick(float a_deltaTime)
{
	Super::Tick(a_deltaTime);

	// If the spy won and the game hasn't been indicated that it's over.
	if (spyVictory && !gameEnded)
	{
		// Indicate that the game is ending.
		gameEnded = true;

		// Play the spy victory sequence.
		SpyVicorySequence();
	}

	// If the guards won and the game hasn't been indicated that it's over.
	if (guardVictory && !gameEnded)
	{
		// Indicate that the game is ending.
		gameEnded = true;

		// Play the guard victory sequence.
		GuardVicorySequence();
	}

	// Launch Rocket.
	if (guardVictory && gameEnded)
	{
		// Decreases the end time so you can see the result of the simulation.
		endTime -= a_deltaTime;

		// Launch the rocket.
		FVector NewLocation = rocket->GetActorLocation();
		NewLocation.Z += (a_deltaTime * 300.0f);
		rocket->SetActorLocation(NewLocation);

		// Ends the game.
		if (endTime <= 0.0f)
		{
			// Resets the game.
			ResetGame();
		}
	}

	// Tilt Rocket and lever.
	if (spyVictory && gameEnded)
	{
		// Decreases the end time so you can see the result of the simulation.
		endTime -= a_deltaTime;

		// Rotate the rocket.
		FRotator NewRotation = FRotator(5.0f, 5.0f, 5.0f);
		FQuat QuatRotation = FQuat(NewRotation);
		rocket->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

		// Scale the rocket.
		FVector RocketScale = rocket->GetActorScale3D();
		float ScaleStep = a_deltaTime * 2.0f;
		RocketScale = FVector(RocketScale.X - ScaleStep, RocketScale.Y - (ScaleStep * 1.5f) , RocketScale.Z - ScaleStep);
		if (RocketScale.X < 0.0f || RocketScale.Y < 0.0f || RocketScale.Z < 0.0f)
		{
			RocketScale = FVector(0.0f, 0.0f, 0.0f);
		}
		rocket->SetActorScale3D(RocketScale);

		// Pull the lever.
		NewRotation = FRotator(1.0f, 0.0f, 0.0f);
		QuatRotation = FQuat(NewRotation);
		lever->AddActorLocalRotation(QuatRotation);
		FRotator CurrentLeverRotation = lever->GetActorRotation();
		if (CurrentLeverRotation.Pitch > 50.0f)
		{
			FRotator NewLeverRotation = FRotator(50.0f, 0.0f, 0.0f);
			lever->SetActorRotation(NewLeverRotation);
		}

		// Ends the game.
		if (endTime <= 0.0f)
		{
			// Resets the game.
			ResetGame();
		}
	}
}

// Makes the billboard indicate that the guards won.
void AGameController::GuardVicorySequence()
{
	countDownBillboard->DisplayGuardWin();
}

// Makes the billboard indicate that the spy won.
void AGameController::SpyVicorySequence()
{
	countDownBillboard->DisplaySpyWin();
}

// Resets the game.
void AGameController::ResetGame()
{
	if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
	{
		AGameController::guardVictory = false;
		AGameController::spyVictory = false;
		GM->RestartGame();
	}
}

