////////////////////////////////////////////////////////////
// File: ChargingArea.h
// Author: Morgan Henry James
// Date Created: ‎15 December ‎2019, ‏‎19:37:20
// Brief: Declaration of the charging area class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ChargingArea.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AChargingArea : public ATriggerBox
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

public:
	// Constructor sets default values for this actor's properties.
	AChargingArea();

	// Declare overlap begin function.
	UFUNCTION()
	void OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor);

	// Declare overlap end function.
	UFUNCTION()
	void OnOverlapEnd(class AActor* a_overlappedActor, class AActor* a_otherActor);
	
};
