// Fill out your copyright notice in the Description page of Project Settings.

#include "AF_InfoCard.h"

UAF_InfoCard::UAF_InfoCard(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer){
	cardTitle = CreateDefaultSubobject<UTextBlock>(TEXT("Card Title"));
	cardInfo = CreateDefaultSubobject<UTextBlock>(TEXT("Card Info"));
	return;
}

void UAF_InfoCard::NativeConstruct() {
	Super::NativeConstruct();
	return;
}