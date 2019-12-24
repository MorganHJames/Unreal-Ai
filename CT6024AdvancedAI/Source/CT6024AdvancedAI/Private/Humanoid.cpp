////////////////////////////////////////////////////////////
// File: Humanoid.cpp
// Author: Morgan Henry James
// Date Created: ‎‎13 December ‎2019, ‏‎22:25:28
// Brief: Controls the functionality of a humanoid.
////////////////////////////////////////////////////////////

#include "Humanoid.h"
#include "Bullet.h"
#include <Runtime\Engine\Classes\Engine\World.h>
#include "Components/TextRenderComponent.h"
#include "Engine/TriggerBox.h"
#include "DrawDebugHelpers.h"
#include "Classes/Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/Controller.h"


// Sets default values.
AHumanoid::AHumanoid()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// The health text for the humanoid.
	healthText = CreateDefaultSubobject<UTextRenderComponent>("healthText"); 

	// The humanoids vision box.
	visionBox = CreateDefaultSubobject<ATriggerBox>("visionBox");
}

// Called when the game starts or when spawned.
void AHumanoid::BeginPlay()
{
	// Register Events
	visionBox->OnActorBeginOverlap.AddDynamic(this, &AHumanoid::OnOverlapBegin);
	visionBox->OnActorEndOverlap.AddDynamic(this, &AHumanoid::OnOverlapEnd);
	Super::BeginPlay();
}

// Spawns a bullet that moves forward.
void AHumanoid::Shoot()
{
	// If a bullet has been set.
	if (bulletClass && canShoot)
	{
		// Indicate that the humanoid can no longer shoot.
		canShoot = false;

		// Set the charge time remaining to the charge time.
		currentChargeTimeRemaining = chargeTime;

		// Set up spawning parameters.
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParameters.bNoFail = true;
		SpawnParameters.Owner = this;
		SpawnParameters.Instigator = this;

		// Set up bullet transform.
		FTransform BulletSpawnTransform;
		BulletSpawnTransform.SetLocation(GetActorForwardVector() * 75.0f + GetActorLocation() + FVector(0.f,0.f, 75.0f));
		BulletSpawnTransform.SetRotation(GetActorRotation().Quaternion());

		// Spawn the bullet.
		GetWorld()->SpawnActor<ABullet>(bulletClass, BulletSpawnTransform, SpawnParameters);
	}
}

// Called every frame.
void AHumanoid::Tick(float a_deltaTime)
{
	Super::Tick(a_deltaTime);

	// Stops rapid fire.
	currentChargeTimeRemaining -= a_deltaTime;

	if (currentChargeTimeRemaining < 0.0f)
	{
		canShoot = true;
	}

	// Update actors in vision.
	for (AActor* Actor : actorsInVisonBox)
	{
		FHitResult hit;

		// Ray cast actor.
		AHumanoid::Trace(GetWorld(), this, GetActorLocation(), Actor->GetActorLocation(), hit);
		
		// If there is a direct hit to the actor.
		if (hit.Actor == Actor)
		{
			// If the actor is not in the actors in vision array.
			if (!actorsInVison.Contains(Actor))
			{
				// Add the actor to the actors in vision array.
				actorsInVison.Add(Actor);

				// If the actor is not in the actors seen array.
				if (!actorsSeen.Contains(Actor))
				{
					// Add the actor to the array of seen actors.
					actorsSeen.Add(Actor);
				}
			}
		}
		// If the ray does not make a direct hit.
		else
		{
			// If the actor it was supposed to hit was in previously in the actors in vision array.
			if (actorsInVison.Contains(Actor))
			{
				// Remove the actor from the actors in vision array.
				actorsInVison.Remove(Actor);
			}
		}
	}
}

// Changes the health of the humanoid.
void AHumanoid::ChangeHealth(float a_healthChange)
{
	// Add the health change to the health.
	health += a_healthChange;

	// Clamp the health.
	if (health > maxHealth)
	{
		health = maxHealth;
	}

	// If the health is 0 or lower.
	if (health <= 0.0f)
	{
		// Kill the humanoid.
		Die();
	}

	// Sets up the text string.
	FString RemainingHealth = FString::FromInt((int)health);

	// Sets the text.
	healthText->SetText(RemainingHealth);
}

// Kills the humanoid.
void AHumanoid::Die()
{
	Destroy();
}

// Moves the humanoid to the specified location.
void AHumanoid::MoveToLocation(FVector a_locationToGoTo)
{
	AController* pController = this->GetController();
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(pController, a_locationToGoTo);
}

// Called when an actor starts overlapping.
void AHumanoid::OnOverlapBegin(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it overlaps something.
	if (a_otherActor)
	{
		// Add to actors in vision box.
		actorsInVisonBox.Add(a_otherActor);

		// If can see add to actors in vision.
		FHitResult hit;
		AHumanoid::Trace(GetWorld(), this, GetActorLocation(), a_otherActor->GetActorLocation(), hit);
		if (hit.Actor == a_otherActor)
		{
			actorsInVison.Add(a_otherActor);
			actorsSeen.Add(a_otherActor);
		}
	}
}

// Called when an actor stops overlapping.
void AHumanoid::OnOverlapEnd(class AActor* a_overlappedActor, class AActor* a_otherActor)
{
	// Check if it stops overlapping something.
	if (a_otherActor)
	{
		// Remove from actors in vision box.
		actorsInVisonBox.Remove(a_otherActor);

		// If in seen actors remove.
		if (actorsInVison.Contains(a_otherActor))
		{
			actorsInVison.Remove(a_otherActor);
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
	if (hitSomething) 
		DrawDebugPoint(world, hit.ImpactPoint, 10, FColor(255, 255, 0), false, -1);

	// Draw the trace line. Red if something was hit, green if nothing was hit.
	DrawDebugLine(world, start, end, (hitSomething ? FColor(255, 0, 0) : FColor(0, 255, 0)), false, -1, 0, 1.5);

	return hitSomething;
}
