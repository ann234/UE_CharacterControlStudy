// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateMachineCharacter.h"
#include "PlayerCharacter.generated.h"

UENUM(BlueprintType)
enum class ECharStateEnum : uint8
{
	CSE_IDLE	UMETA(DisplayName = "Idle"),
	CSE_RUN		UMETA(DisplayName = "Run"),
	CSE_DODGE	UMETA(DisplayName = "Dodge"),
	CSE_START_ATTACK	UMETA(DisplayName = "Start attack"),
	CSE_END_ATTACK	UMETA(DisplayName = "End attack")
};

/**
 * 
 */
UCLASS()
class STATEMACHINE_API APlayerCharacter : public AStateMachineCharacter
{
	GENERATED_BODY()

public:

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
		ECharStateEnum current_state;
	
protected:
	//	Only editable in blueprint
	UFUNCTION(BlueprintImplementableEvent, Category = "Character")
		void DoAttack();
	UFUNCTION(BlueprintImplementableEvent, Category = "Character")
		void DoRun();
	UFUNCTION(BlueprintImplementableEvent, Category = "Character")
		void DoDodge();
};
