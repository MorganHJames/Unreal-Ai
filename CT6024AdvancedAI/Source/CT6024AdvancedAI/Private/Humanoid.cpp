// Fill out your copyright notice in the Description page of Project Settings.

#include "Humanoid.h"
#include "Bullet.h"
#include <Runtime\Engine\Classes\Engine\World.h>
#include "Components/TextRenderComponent.h"
#include "Engine/TriggerBox.h"
#include "DrawDebugHelpers.h"

// Sets default values
AHumanoid::AHumanoid()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//The health text for the humanoid.
	HealthText = CreateDefaultSubobject<UTextRenderComponent>("HealthText"); 

	// The humanoids vision box.
	VisionBox = CreateDefaultSubobject<ATriggerBox>("VisionBox");
}

// Called when the game starts or when spawned.
void AHumanoid::BeginPlay()
{
	// Register Events
	VisionBox->OnActorBeginOverlap.AddDynamic(this, &AHumanoid::OnOverlapBegin);
	VisionBox->OnActorEndOverlap.AddDynamic(this, &AHumanoid::OnOverlapEnd);
	Super::BeginPlay();
}

// Spawns a bullet that moves forward.
void AHumanoid::Shoot()
{
	// If a bullet has been set.
	if (BulletClass && CanShoot)
	{
		CanShoot = false;
		CurrentChargeTimeRemaining = ChargeTime;
		// Set up spawning parameters.
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParameters.bNoFail = true;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = this;

		// Set up bullet transform.
		FTransform BulletSpawnTransform;
		BulletSpawnTransform.SetLocation(GetActorForwardVector() * 50.0f + GetActorLocation() + FVector(0.f,0.f, 75.0f));
		BulletSpawnTransform.SetRotation(GetActorRotation().Quaternion());

		// Spawn the bullet.
		GetWorld()->SpawnActor<ABullet>(BulletClass, BulletSpawnTransform, SpawnParameters);
	}
}

// Called every frame
void AHumanoid::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Stops rapid fire.
	CurrentChargeTimeRemaining -= DeltaTime;

	if (CurrentChargeTimeRemaining < 0.0f)
	{
		CanShoot = true;
	}

	// Update actors in vision.
	for (AActor* Actor : ActorsInVisonBox)
	{
		FHitResult hit;
		AHumanoid::Trace(GetWorld(), this, GetActorLocation(), Actor->GetActorLocation(), hit);
		if (hit.Actor == Actor)
		{
			if (!ActorsInVison.Contains(Actor))
			{
				ActorsInVison.Add(Actor);
			}
		}
		else
		{
			if (ActorsInVison.Contains(Actor))
			{
				ActorsInVison.Remove(Actor);
			}
		}
	}
}

// Called to bind functionality to input
void AHumanoid::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

// Changes the health of the humanoid.
void AHumanoid::ChangeHealth(float HealthChange)
{
	Health += HealthChange;

	if (Health > MaxHealth)
	{
		Health = MaxHealth;
	}

	if (Health <= 0.0f)
	{
		Die();
	}

	//Sets up the text string.
	FString RemainingHealth = FString::FromInt((int)Health);

	//Sets the text.
	HealthText->SetText(RemainingHealth);
}

// Kills the humanoid.
void AHumanoid::Die()
{
	Destroy();
}

// Called when an actor starts overlapping.
void AHumanoid::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it overlaps something.
	if (OtherActor)
	{
		// Add to actors in vision box.
		ActorsInVisonBox.Add(OtherActor);

		// If can see add to actors in vision.
		FHitResult hit;
		AHumanoid::Trace(GetWorld(), this, GetActorLocation(), OtherActor->GetActorLocation(), hit);
		if (hit.Actor == OtherActor)
		{
			ActorsInVison.Add(OtherActor);
		}
	}
}

// Called when an actor stops overlapping.
void AHumanoid::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if it stops overlapping something.
	if (OtherActor)
	{
		// Remove from actors in vision box.
		ActorsInVisonBox.Remove(OtherActor);

		// If in seen actors remove.
		if (ActorsInVison.Contains(OtherActor))
		{
			ActorsInVison.Remove(OtherActor);
		}
	}
}


// Trace functionality found at https://forums.unrealengine.com/development-discussion/c-gameplay-programming/66176-anyone-know-where-i-can-find-a-simple-raycast-with-trace-example-in-c.
// Trace using start point, direction, and length.
bool AHumanoid::Trace(UWorld* world, AActor* actorToIgnore, const FVector& start, const FVector& dir, float length, FHitResult& hit, ECollisionChannel collisionChannel, bool returnPhysMat)
{
	return Trace(world, actorToIgnore, start, start + dir * length, hit, collisionChannel, returnPhysMat);
}

// Trace using start point, and end point.
bool AHumanoid::Trace(UWorld* world, AActor* actorToIgnore, const FVector& start, const FVector& end, FHitResult& hit, ECollisionChannel collisionChannel, bool returnPhysMat)
{
	if (!world)
	{
		return false;
	}

	// Trace params, set the 'false' to 'true' if you want it to trace against the actual meshes instead of their collision boxes.
	FCollisionQueryParams TraceParams(FName(TEXT("VictoreCore Trace")), false, actorToIgnore);
	TraceParams.bReturnPhysicalMaterial = returnPhysMat;

	//Ignore Actors, usually the actor that is calling the trace
	TraceParams.AddIgnoredActor(actorToIgnore);

	//Re-initialize hit info, so you can call the function repeatedly and hit will always be fresh
	hit = FHitResult(ForceInit);

	//Trace!
	bool hitSomething = world->LineTraceSingleByChannel(
		hit,		//result
		start,	//start
		end, //end
		collisionChannel, //collision channel
		TraceParams
	);

	// Draw a square at the impact point.
	if (hitSomething) DrawDebugPoint(world, hit.ImpactPoint, 10, FColor(255, 255, 0), false, -1);

	// Draw the trace line. Red if something was hit, green if nothing was hit.
	DrawDebugLine(world, start, end, (hitSomething ? FColor(255, 0, 0) : FColor(0, 255, 0)), false, -1, 0, 1.5);

	return hitSomething;
}
