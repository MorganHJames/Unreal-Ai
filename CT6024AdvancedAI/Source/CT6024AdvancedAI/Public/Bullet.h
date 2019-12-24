////////////////////////////////////////////////////////////
// File: Bullet.h
// Author: Morgan Henry James
// Date Created: ‎14 December ‎2019, ‏‎18:24:06
// Brief: Declaration of the Bullet class.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The bullets model.
	UPROPERTY(EditAnywhere, Category = "Components")
	UStaticMeshComponent* bulletMesh;

	// What makes the bullet move.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UProjectileMovementComponent* bulletMovement;

	// How long the bullet should remain in the world until it gets destroyed.
	float lifeTime = 10.0f;

public:	
	// Called every frame.
	virtual void Tick(float a_deltaTime) override;

	// Called when the bullet hits an actor.
	UFUNCTION()
	void OnBulletHit(AActor* a_selfActor, AActor* a_otherActor, FVector a_normalImpulse, const FHitResult& a_hit);
};
