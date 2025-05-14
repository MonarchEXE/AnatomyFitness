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
	bool bFilePathIsAbsolute;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Card Info")
	UTextBlock* cardText;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget), Category = "Card Info")
	UBorder* cardBox;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Card Info")
	FString filePath;
	FString fileContent;
	
	UAF_InfoCard(const FObjectInitializer& ObjectInitializer);



protected:
	virtual void NativeConstruct() override;

private:
	void ReadFileContent();

	//UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Card Info")
	//UTextBlock* cardTitle;
	//UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Card Info")
	//UTextBlock* cardInfo;
	//UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Category = "Card Info")
	//UBorder* cardBox;

};
