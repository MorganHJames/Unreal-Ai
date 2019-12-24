////////////////////////////////////////////////////////////
// File: Bullet.cpp
// Author: Morgan Henry James
// Date Created: ‎14 December ‎2019, ‏‎18:24:06
// Brief: Controls what a bullet does.
//////////////////////////////////////////////////////////// 

#include "Bullet.h"
#include "Classes/GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h" 
#include "Humanoid.h"

// Sets default values.
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// The bullets model.
	bulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("bulletMesh");

	// Set the root.
	SetRootComponent(bulletMesh);

	// Setup the projectile values.
	bulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>("bulletMovement");
	bulletMovement->InitialSpeed = 2000.f;
	bulletMovement->MaxSpeed = 2000.f;
}

// Called when the game starts or when spawned.
void ABullet::BeginPlay()
{
	// Add the bullet on hit to the bullet.
	OnActorHit.AddDynamic(this, &ABullet::OnBulletHit);
	Super::BeginPlay();
}

// Called every frame.
void ABullet::Tick(float a_deltaTime)
{
	Super::Tick(a_deltaTime);

	//Decreases bullets lifetime.
	lifeTime -= a_deltaTime;

	//If the bullet is out of lifetime.
	if (lifeTime < 0.0f)
	{
		//Destroy the bullet.
		Destroy();
	}
}

// If the bullet hit something call this.
void ABullet::OnBulletHit(AActor* a_selfActor, AActor* a_otherActor, FVector a_normalImpulse, const FHitResult& a_hit)
{
	// Check if it hits something.
	if (a_otherActor)
	{
		// Check if it hits a human.
		AHumanoid* humanoid = Cast<AHumanoid>(a_otherActor);

		// If the actor is a human.
		if (humanoid)
		{
			// Decrease the hit humans health.
			humanoid->ChangeHealth(-25.0f);
		}
	}

	// Destroy the bullet.
	Destroy();
} 

