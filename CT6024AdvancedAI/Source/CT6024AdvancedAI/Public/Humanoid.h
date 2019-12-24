////////////////////////////////////////////////////////////
// File: Humanoid.h
// Author: Morgan Henry James
// Date Created: ‎‎13 December ‎2019, ‏‎22:25:28
// Brief: Declaration of the humanoid kit class.
////////////////////////////////////////////////////////////

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include <list>
#include "Humanoid.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AHumanoid : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties.
	AHumanoid();
protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override; 

	// Spawns a bullet in front of the humanoid.
	void Shoot();

	// The bullet to spawn in front of the humanoid.
	UPROPERTY(EditAnywhere, Category = "Shooting")
	TSubclassOf<class ABullet> bulletClass;

	// The actors that the humanoid has seen.
	UPROPERTY(EditAnywhere, Category = "References")
	TArray<class AActor*> actorsSeen;

	// The text that indicates the humanoids current health above it's head.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* healthText;

	// The locations that the humanoid can wander to.
	UPROPERTY(EditAnywhere, Category = "locations")
	TArray<class AActor*> locations;

	// The current position that the humanoid is headed to.
	FVector currentPositionHeadingTo;

	// A reference to the vision box that humanoid should use for it's vision.
	UPROPERTY(EditAnywhere, Category = "References")
	class ATriggerBox* visionBox;

	// All of the actors that are within the vision box of the humanoid.
	TArray<class AActor*> actorsInVisonBox;

	// All of the actors in the humanoids vision.
	TArray<class AActor*> actorsInVison;

	// The current health of the humanoid.
	float health = 100.0f;

	// The max health of the humanoid.
	float maxHealth = 100.0f;

	// The time remaining before the humanoid can shoot.
	float currentChargeTimeRemaining = 0.0f;

	// The time the humanoid must wait in between shooting bullets.
	float chargeTime = 2.0f;

	// True when the humanoid can shoot a bullet.
	bool canShoot = true;

public:	
	// Called every frame.
	virtual void Tick(float a_deltaTime) override;

	// Changes the health of the humanoid by the value passed in.
	void ChangeHealth(float a_healthChange);

	// Kills the humanoid.
	virtual void Die();

	// Moves the humanoid to the specified location.
	void MoveToLocation(FVector a_locationToGoTo);

	// Declare overlap begin function.
	UFUNCTION()
	void OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor);

	// Declare overlap end function.
	UFUNCTION()
	void OnOverlapEnd(class AActor* a_overlappedActor, class AActor* a_otherActor);

	static bool Trace(UWorld* a_world, AActor* a_actorToIgnore, const FVector& a_start, const FVector& a_dir, float a_length, FHitResult& a_hit, ECollisionChannel a_collisionChannel = ECC_Pawn, bool a_returnPhysMat = false);
	static bool Trace(UWorld* a_world, AActor* a_actorToIgnore, const FVector& a_start, const FVector& a_end, FHitResult& a_hit, ECollisionChannel a_collisionChannel = ECC_Pawn, bool a_returnPhysMat = false);
};
