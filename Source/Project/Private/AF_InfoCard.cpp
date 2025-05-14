// Fill out your copyright notice in the Description page of Project Settings.

#include "AF_InfoCard.h"

UAF_InfoCard::UAF_InfoCard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){
	cardText = CreateDefaultSubobject<UTextBlock>(TEXT("Card Text"));

	bFilePathIsAbsolute = false;
	return;
}

void UAF_InfoCard::NativeConstruct() {
	Super::NativeConstruct();

	// ensures file path becomes absolute only once
	if (bFilePathIsAbsolute == false) {
		filePath.InsertAt(0, "Content/Assets/Widget_Texts/");
		filePath.InsertAt(0, FPaths::ProjectDir());

		bFilePathIsAbsolute = true;
	}

	ReadFileContent();

	if (cardText) {
		cardText->SetText(FText::FromString(fileContent));
	}
	
	return;
}

void UAF_InfoCard::ReadFileContent() {
	IPlatformFile& FileManager = FPlatformFileManager::Get().GetPlatformFile();

	// FIX: rewrite this condition
	if (filePath != "") {
		FFileHelper::LoadFileToString(fileContent,*filePath,FFileHelper::EHashOptions::None);
		UE_LOG(LogTemp, Log, TEXT("File Manipulation: File content loaded."));

	}
	else {
		UE_LOG(LogTemp, Log, TEXT("File Manipulation: File was not found."));
	}

	return;
} 