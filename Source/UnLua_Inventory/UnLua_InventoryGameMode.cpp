// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnLua_InventoryGameMode.h"
#include "UnLua_InventoryCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUnLua_InventoryGameMode::AUnLua_InventoryGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
