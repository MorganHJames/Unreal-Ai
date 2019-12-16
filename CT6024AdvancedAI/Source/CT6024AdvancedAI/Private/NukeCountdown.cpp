// Fill out your copyright notice in the Description page of Project Settings.

#include "NukeCountdown.h"
#include "Components/TextRenderComponent.h"
#include "SpectateAIGameMode.h"

// Sets default values
ANukeCountdown::ANukeCountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//The background object for the countdown.
	Background = CreateDefaultSubobject<UStaticMeshComponent>("Background");

	//The text that counts down.
	CountDownText = CreateDefaultSubobject<UTextRenderComponent>("CountDownText");

	//The info text explaining what the timer indicates.
	InfoText = CreateDefaultSubobject<UTextRenderComponent>("InfoText");
}

// Called when the game starts or when spawned
void ANukeCountdown::BeginPlay()
{
	Super::BeginPlay();
}

// Display the restarting soon text.
void ANukeCountdown::DisplayRestartingText()
{
	FString RestartText = FString("Simulation Restarting Soon!");
	InfoText->SetText(RestartText);
}

// Called every frame
void ANukeCountdown::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Countdown)
	{
		//Counts down the timer.
		TimeRemaining -= DeltaTime;

		if (TimeRemaining < 0.0f)
		{
			TimeRemaining = 0.0f;
		}

		if (TimeRemaining == 0.0f)
		{
			if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
			{
				GM->GuardsWin();
			}
		}
		//Sets up the text string.
		FString RemainingTimeString = FString::FromInt((int)TimeRemaining);

		//Sets the text.
		CountDownText->SetText(RemainingTimeString);
	}
}

// Display that the guards won.
void ANukeCountdown::DisplayGuardWin()
{
	Countdown = false;
	DisplayRestartingText();

	//Sets up the text string.
	FString GuardsWonText = FString("Guards Won");

	//Sets the text.
	CountDownText->SetText(GuardsWonText);
	CountDownText->SetXScale(0.35f);
	CountDownText->SetYScale(0.35f);
}

// Display that the spy won.
void ANukeCountdown::DisplaySpyWin()
{
	Countdown = false;
	DisplayRestartingText();

	//Sets up the text string.
	FString SpyWinText = FString("Spy Won");

	//Sets the text.
	CountDownText->SetText(SpyWinText);
	CountDownText->SetXScale(0.4f);
	CountDownText->SetYScale(0.4f);
}

