////////////////////////////////////////////////////////////
// File: ToxicSpill.h
// Author: Morgan Henry James
// Date Created: ‎‎‎16 December ‎2019, ‏‎18:22:52
// Brief: Declaration of the toxic spill class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ToxicSpill.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AToxicSpill : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AToxicSpill();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// The area of effect for the spillage.
	UPROPERTY(EditAnywhere, Category = "References")
	class ATriggerBox* triggerBox;

	// The green mesh that indicates a spill damages.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* toxicSpill;

	// The barrel of toxic waste that falls over.
	UPROPERTY(EditAnywhere, Category = "References")
	class AStaticMeshActor* barrelOfToxicWaste;

	// All of the humanoids within the trigger box of the toxic spill.
	TArray<class AHumanoid*> humanoids;

	// True when the toxic waste is damaging.
	bool isSpilled = false;

	// The time left that the spillage remains.
	float remainingSpilledTime;

	// The time remaining until the next spill.
	float remainingTimeBetweenSpills;

public:	
	// Called every frame.
	virtual void Tick(float a_deltaTime) override;

	// Declare overlap begin function.
	UFUNCTION()
	void OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor);

	// Declare overlap end function.
	UFUNCTION()
	void OnOverlapEnd(class AActor* a_overlappedActor, class AActor* a_otherActor);
};
