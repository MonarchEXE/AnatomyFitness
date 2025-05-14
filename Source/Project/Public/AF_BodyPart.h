// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"

#include "AF_InfoCard.h"

#include "AF_BodyPart.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_API UAF_BodyPart : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UAF_BodyPart();

protected:
	virtual void BeginPlay() override;

private:
	bool bInfoWidgetExpanded;

	UPROPERTY(EditInstanceOnly)
	UWidgetComponent* nameWidget;
	UPROPERTY(EditInstanceOnly)
	UWidgetComponent* infoWidget;


	UFUNCTION()
	void ShowObjectTitle(UPrimitiveComponent* component);
	UFUNCTION()
	void HideObjectTitle(UPrimitiveComponent* component);
	UFUNCTION()
	void ExpandWidget(UPrimitiveComponent* component, FKey key);
};
