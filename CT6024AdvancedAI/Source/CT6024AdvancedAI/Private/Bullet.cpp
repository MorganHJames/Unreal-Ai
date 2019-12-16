// Fill out your copyright notice in the Description page of Project Settings.

#include "Bullet.h"
#include "Classes/GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h" 
#include "Humanoid.h"

// Sets default values
ABullet::ABullet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>("BulletMesh");

	// Set the root.
	SetRootComponent(BulletMesh);

	// Setup the projectile values.
	BulletMovement = CreateDefaultSubobject<UProjectileMovementComponent>("BulletMovement");
	BulletMovement->InitialSpeed = 2000.f;
	BulletMovement->MaxSpeed = 2000.f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	OnActorHit.AddDynamic(this, &ABullet::OnBulletHit);
	Super::BeginPlay();
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Decreases bullets lifetime.
	lifeTime -= DeltaTime;

	//If the bullet is out of lifetime.
	if (lifeTime < 0.0f)
	{
		//Destroy the bullet.
		Destroy();
	}
}

// If the bullet hit something call this.
void ABullet::OnBulletHit(AActor* SelfActor, AActor* OtherActor, FVector NormalImpulse, const FHitResult& Hit)
{
	// Check if it hits something.
	if (OtherActor)
	{
		// Check if it hits a human.
		AHumanoid* humanoid = Cast<AHumanoid>(OtherActor);
		if (humanoid)
		{
			// Decrease the hit humans health.
			humanoid->ChangeHealth(-25.0f);
		}
	}

	// Destroy the bullet.
	Destroy();
} 

