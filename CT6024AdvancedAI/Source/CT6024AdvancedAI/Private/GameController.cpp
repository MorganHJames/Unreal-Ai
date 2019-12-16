// Fill out your copyright notice in the Description page of Project Settings.

#include "GameController.h"
#include "Engine/StaticMeshActor.h"
#include "NukeCountdown.h"
#include "SpectateAIGameMode.h"

// Initialize booleans.
bool AGameController::GuardVicory = false;
bool AGameController::SpyVicory = false;

// Sets default values
AGameController::AGameController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (SpyVicory && !GameEnded)
	{
		GameEnded = true;
		SpyVicorySequence();
	}
	
	if (GuardVicory && !GameEnded)
	{
		GameEnded = true;
		GuardVicorySequence();
	}

	// Launch Rocket.
	if (GuardVicory && GameEnded)
	{
		// Decreases the end time so you can see the result of the simulation.
		EndTime -= DeltaTime;

		// Launch the rocket.
		FVector NewLocation = Rocket->GetActorLocation();
		NewLocation.Z += (DeltaTime * 300.0f);
		Rocket->SetActorLocation(NewLocation);

		// Ends the game.
		if (EndTime <= 0.0f)
		{
			ResetGame();
		}
	}

	// Tilt Rocket and lever.
	if (SpyVicory && GameEnded)
	{
		// Decreases the end time so you can see the result of the simulation.
		EndTime -= DeltaTime;

		// Rotate the rocket.
		FRotator NewRotation = FRotator(5.0f, 5.0f, 5.0f);
		FQuat QuatRotation = FQuat(NewRotation);
		Rocket->AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

		// Scale the rocket.
		FVector RocketScale = Rocket->GetActorScale3D();
		float ScaleStep = DeltaTime * 2.0f;
		RocketScale = FVector(RocketScale.X - ScaleStep, RocketScale.Y - (ScaleStep * 1.5f) , RocketScale.Z - ScaleStep);
		if (RocketScale.X < 0.0f || RocketScale.Y < 0.0f || RocketScale.Z < 0.0f)
		{
			RocketScale = FVector(0.0f, 0.0f, 0.0f);
		}
		Rocket->SetActorScale3D(RocketScale);

		// Pull the lever.
		NewRotation = FRotator(1.0f, 0.0f, 0.0f);
		QuatRotation = FQuat(NewRotation);
		Lever->AddActorLocalRotation(QuatRotation);
		FRotator CurrentLeverRotation = Lever->GetActorRotation();
		if (CurrentLeverRotation.Pitch > 50.0f)
		{
			FRotator NewLeverRotation = FRotator(50.0f, 0.0f, 0.0f);
			Lever->SetActorRotation(NewLeverRotation);
		}

		// Ends the game.
		if (EndTime <= 0.0f)
		{
			ResetGame();
		}
	}
}

// Makes the billboard indicate that the guards won.
void AGameController::GuardVicorySequence()
{
	CountDownBillboard->DisplayGuardWin();
}

// Makes the billboard indicate that the spy won.
void AGameController::SpyVicorySequence()
{
	CountDownBillboard->DisplaySpyWin();
}

// Resets the game.
void AGameController::ResetGame()
{
	if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
	{
		AGameController::GuardVicory = false;
		AGameController::SpyVicory = false;
		GM->RestartGame();
	}
}

