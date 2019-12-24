////////////////////////////////////////////////////////////
// File: GameManager.cpp
// Author: Morgan Henry James
// Date Created: ‎‎‎14 December ‎2019, ‏‎17:27:18
// Brief: Doesn't really do anything I just needed a manager.
//////////////////////////////////////////////////////////// 

#include "GameManager.h"

// Sets default values.
AGameManager::AGameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned.
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame.
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

