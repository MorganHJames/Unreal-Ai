////////////////////////////////////////////////////////////
// File: NukeCountdown.cpp
// Author: Morgan Henry James
// Date Created: ‎‎14 December ‎2019, ‏‎03:19:43
// Brief: Controls the billboard that indicates the nuke launch status.
//////////////////////////////////////////////////////////// 

#include "NukeCountdown.h"
#include "GameController.h"
#include "Components/TextRenderComponent.h"
#include "SpectateAIGameMode.h"

// Sets default values.
ANukeCountdown::ANukeCountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// The background object for the countdown.
	background = CreateDefaultSubobject<UStaticMeshComponent>("Background");

	// The text that counts down.
	countDownText = CreateDefaultSubobject<UTextRenderComponent>("CountDownText");

	// The info text explaining what the timer indicates.
	infoText = CreateDefaultSubobject<UTextRenderComponent>("InfoText");
}

// Called when the game starts or when spawned.
void ANukeCountdown::BeginPlay()
{
	Super::BeginPlay();
}

// Display the restarting soon text.
void ANukeCountdown::DisplayRestartingText()
{
	FString RestartText = FString("Simulation Restarting Soon!");
	infoText->SetText(RestartText);
}

// Called every frame.
void ANukeCountdown::Tick(float a_deltaTime)
{
	Super::Tick(a_deltaTime);

	// If the billboard should be counting down.
	if (countdown)
	{
		// Counts down the timer.
		timeRemaining -= a_deltaTime;

		// Clamp timer.
		if (timeRemaining < 0.0f)
		{
			timeRemaining = 0.0f;
		}

		// If the time is up.
		if (timeRemaining == 0.0f)
		{
			if (ASpectateAIGameMode* GM = Cast<ASpectateAIGameMode>(GetWorld()->GetAuthGameMode()))
			{
				// Indicated for the guards to win.
				GM->GuardsWin();
			}
		}

		// Sets the game controller time to the remaining time.
		AGameController::currentTime = timeRemaining;

		// Sets up the text string.
		FString RemainingTimeString = FString::FromInt((int)timeRemaining);

		// Sets the text.
		countDownText->SetText(RemainingTimeString);
	}
}

// Display that the guards won.
void ANukeCountdown::DisplayGuardWin()
{
	// Stops the count down.
	countdown = false;

	// Shows the text that indicates a reset will take place soon.
	DisplayRestartingText();

	// Sets up the text string.
	FString GuardsWonText = FString("Guards Won");

	// Sets the text.
	countDownText->SetText(GuardsWonText);
	countDownText->SetXScale(0.35f);
	countDownText->SetYScale(0.35f);
}

// Display that the spy won.
void ANukeCountdown::DisplaySpyWin()
{
	// Stops the count down.
	countdown = false;

	// Shows the text that indicates a reset will take place soon.
	DisplayRestartingText();

	// Sets up the text string.
	FString SpyWinText = FString("Spy Won");

	// Sets the text.
	countDownText->SetText(SpyWinText);
	countDownText->SetXScale(0.4f);
	countDownText->SetYScale(0.4f);
}

