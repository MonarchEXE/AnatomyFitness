// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"

#include "AF_Pawn.h"

#include "AF_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API AAF_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AAF_GameMode();
	virtual ~AAF_GameMode() = default;

protected:
	virtual void StartPlay() override;

private:
	AAF_Pawn* localPawn;
	APlayerController* localController;
};