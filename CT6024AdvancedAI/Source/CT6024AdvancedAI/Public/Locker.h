////////////////////////////////////////////////////////////
// File: Locker.h
// Author: Morgan Henry James
// Date Created: ‎16 December ‎2019, ‏‎04:58:49
// Brief: Declaration of the locker class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Locker.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API ALocker : public AActor
{
	GENERATED_BODY()
public:
	// Turn ticks on.
	ALocker();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// The spy.
	class ASpy* spy;

	// The location of the spy when entering the locker.
	FTransform spyPreviousLocation;

	// True when the spy is in the locker.
	bool lockerFull = false;

	// The area of which the spy can enter the locker.
	UPROPERTY(EditAnywhere, Category = "Reference")
	class ATriggerBox* triggerBox;

	// The mesh of the locker.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UStaticMeshComponent* locker;
	
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
