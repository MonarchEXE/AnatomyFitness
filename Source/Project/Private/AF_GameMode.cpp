// Fill out your copyright notice in the Description page of Project Settings.


#include "AF_GameMode.h"

AAF_GameMode::AAF_GameMode() {
	/*DefaultPawnClass = AAF_Pawn::StaticClass();*/
	return;
}

void AAF_GameMode::StartPlay() {
	Super::StartPlay();
	
	localController = GetWorld()->GetFirstPlayerController();
	// Gets first AF_Pawn instances
	localPawn = Cast<AAF_Pawn>(UGameplayStatics::GetActorOfClass(GetWorld(), AAF_Pawn::StaticClass()));
	if (localPawn) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Existing pawn instance found."));
	}
	else {
		// some code to explicitly spawn AF_Pawn instance.
	}
	localController->Possess(localPawn);

	// persistent mouse cursor
	localController->bShowMouseCursor = 1;

	// enables mouse events
	localController->bEnableMouseOverEvents = true;
	if (localController->bEnableMouseOverEvents) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("PlayerController: Cursor detection enabled"));
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("PlayerController: Cursor detection not enabled"));
	}
	
}