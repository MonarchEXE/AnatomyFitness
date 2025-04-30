// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Border.h"

#include "AF_InfoCard.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UAF_InfoCard : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UAF_InfoCard(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY( EditInstanceOnly, Category = "Card Info")
	UTextBlock* cardTitle;
	UPROPERTY( EditInstanceOnly, Category = "Card Info")
	UTextBlock* cardInfo;
	UPROPERTY( EditInstanceOnly, Category = "Card Style")
	UBorder* cardBox;
};
