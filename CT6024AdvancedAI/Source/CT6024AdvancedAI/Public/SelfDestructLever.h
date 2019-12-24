////////////////////////////////////////////////////////////
// File: SelfDestructLever.h
// Author: Morgan Henry James
// Date Created: ‎‎‎15 December ‎2019, ‏‎22:36:28
// Brief: Declaration of the self destruct lever class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "SelfDestructLever.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API ASelfDestructLever : public AActor
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// The base of the lever.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* leverBase;

	// The trigger box for the lever activation.
	UPROPERTY(EditAnywhere, Category = "Reference")
	class ATriggerBox* triggerBox;

public:

	// Constructor sets default values for this actor's properties.
	ASelfDestructLever();

	// Declare overlap begin function.
	UFUNCTION()
	void OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor);
};
