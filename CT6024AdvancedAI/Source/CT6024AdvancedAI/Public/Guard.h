////////////////////////////////////////////////////////////
// File: Guard.h
// Author: Morgan Henry James
// Date Created: ‎‎‎‎13 December ‎2019, ‏‎23:54:43
// Brief: Declaration of the guard class.
// Contains all the AI logic declarations for the guard.
//////////////////////////////////////////////////////////// 

#pragma once

#include "CoreMinimal.h"
#include "Humanoid.h"
#include "Guard.generated.h"

UCLASS()
class CT6024ADVANCEDAI_API AGuard : public AHumanoid
{
	GENERATED_BODY()
public:
	// Sets default values for this character's properties.
	AGuard();

	// True when the guard is charging.
	bool charging = false;

	// Returns True when the guard can see the spy.
	bool CanSeeSpy();

protected:
	// Called when the game starts or when spawned.
	virtual void BeginPlay() override;

	// The energy indicator above the guard.
	UPROPERTY(EditAnywhere, Category = "Components")
	class UTextRenderComponent* energyText;

	// All the locations of the health kits.
	UPROPERTY(EditAnywhere, Category = "locations")
	TArray<class AActor*> healthKitLocations;

	// The location of the charging station.
	UPROPERTY(EditAnywhere, Category = "locations")
	class AActor* chargingLocation;

	// The current energy of the guard.
	float energy = 100.0f;

	// The maximum energy a guard can have.
	float maxEnergy = 100.0f;

	// Contains the state machine for the guard AI behavior.
	void UpdateAI();

	// Called every frame.
	virtual void Tick(float a_deltaTime) override;

	// All of the AI states.
	enum States { Wander, Charge, Heal, Attack, AvoidToixc };

	// The current state of the AI.
	States currentState = States::Wander;

	// Checks the transition to wander from charging.
	bool CheckTransitionToWanderFromChargeBehaviour();

	// Checks the transitions to wanter from attacking.
	bool CheckTransitionToWanderFromAttackBehaviour();

	// Checks the transition from wander to healing.
	bool CheckTransitionToWanderFromHealBehaviour();

	// Checks the transition from wander to avoiding toxic waste.
	bool CheckTransitionToWanderFromAvoidToxicBehaviour();

	// Checks the transition to the charging behavior.
	bool CheckTransitionToChargeBehaviour(int a_energyUnder);

	// Checks the transition to the healing behavior.
	bool CheckTransitionToHealBehaviour(int a_healthUnder);

	// Checks the transition to the attack behavior.
	bool CheckTransitionToAttackBehaviour();

	// Checks the transition to the avoiding toxic waste behavior.
	bool CheckTransitionToAvoidToxicBehaviour();

	// What the guard should do whilst wandering.
	void WanderBehaviour();

	// What the guard should do when charging.
	void ChargeBehaviour();

	// What the guard does when healing.
	void HealBehaviour();

	// What the guard does when attacking.
	void AttackBehaviour();

	// What the guard does when avoiding toxic waste.
	void AvoidToxicBehaviour();
};
