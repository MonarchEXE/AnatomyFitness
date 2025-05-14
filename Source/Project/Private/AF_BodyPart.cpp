// Fill out your copyright notice in the Description page of Project Settings.


#include "AF_BodyPart.h"

UAF_BodyPart::UAF_BodyPart() {
	nameWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Name card"));
	nameWidget->SetupAttachment(this);
	infoWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Info card"));
	infoWidget->SetupAttachment(this);

	bInfoWidgetExpanded = false;
}

void UAF_BodyPart::BeginPlay() {
	nameWidget->SetVisibility(false);
	nameWidget->SetWindowVisibility(EWindowVisibility::Visible);
	infoWidget->SetVisibility(false);

	this->OnBeginCursorOver.AddDynamic(this, &UAF_BodyPart::ShowObjectTitle);
	this->OnEndCursorOver.AddDynamic(this, &UAF_BodyPart::HideObjectTitle);
	this->OnClicked.AddDynamic(this, &UAF_BodyPart::ExpandWidget);
}

void UAF_BodyPart::ShowObjectTitle(UPrimitiveComponent* component) {
	if (bInfoWidgetExpanded == true) {
		return;
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PlayerController: Mouse cursor detected."));
	nameWidget->SetVisibility(true);
	return;
}

void UAF_BodyPart::HideObjectTitle(UPrimitiveComponent* component) {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PlayerController: Mouse cursor left."));
	nameWidget->SetVisibility(false);
	return;
}

void UAF_BodyPart::ExpandWidget(UPrimitiveComponent* component, FKey key) {
	if (infoWidget->IsWidgetVisible() == false) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PlayerController: Expanded info widget."));
		// no need to check if it's already false shruge
		nameWidget->SetVisibility(false);
		infoWidget->SetVisibility(true);
		bInfoWidgetExpanded = true;
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("PlayerController: Collapsed info widget."));
		infoWidget->SetVisibility(false);
		bInfoWidgetExpanded = false;
	}
}
