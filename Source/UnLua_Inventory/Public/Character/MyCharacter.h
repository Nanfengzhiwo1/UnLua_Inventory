// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/InteractionInterface.h"
#include "UnLua_Inventory/UnLua_InventoryCharacter.h"
#include "MyCharacter.generated.h"

USTRUCT()
struct FInteractionData
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	AActor* CurrentInteractable;
	UPROPERTY()
	float LastInteractionCheckTime;

	FInteractionData():
	CurrentInteractable(nullptr),
	LastInteractionCheckTime(0.0f)
	{
		
	};
};


UCLASS()
class UNLUA_INVENTORY_API AMyCharacter : public AUnLua_InventoryCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FORCEINLINE bool IsInteracting() const{return GetWorldTimerManager().IsTimerActive(TimerHandle_Interaction);};
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere,Category="Character|Interaction")
	TScriptInterface<IInteractionInterface> TargetInteractable;

	float InteractionCheckFrequency;

	float InteractionCheckDistance;

	FTimerHandle TimerHandle_Interaction;

	FInteractionData InteractionData;

	void PerformInteractionCheck();
	void FoundInteractable(AActor* NewInteractable);
	void NoInteractableFound();
	void BeginInteract();
	void EndInteract();
	void Interact();
	

};