// Fill out your copyright notice in the Description page of Project Settings.


#include "AF_Pawn.h"

// Sets default values
AAF_Pawn::AAF_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	modelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	modelMesh->SetupAttachment(RootComponent);
	cameraArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Arm"));
	cameraArm->SetupAttachment(modelMesh);
	userCam = CreateDefaultSubobject<UCameraComponent>(TEXT("User Camera"));
	userCam->SetupAttachment(cameraArm);

}

// Called when the game starts or when spawned
void AAF_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAF_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAF_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	PlayerInputComponent->BindAxis(TEXT("PanXAxis"), this, &AAF_Pawn::PanXAxis);
	PlayerInputComponent->BindAxis(TEXT("PanYAxis"), this, &AAF_Pawn::PanYAxis);
	PlayerInputComponent->BindAxis(TEXT("ChangeZoom"), this, &AAF_Pawn::ChangeZoom);

}

void AAF_Pawn::PanXAxis(float axisValue) {
	cameraArm->AddRelativeRotation(FRotator(0.0f, axisValue, 0.0f));
	return;
}

void AAF_Pawn::PanYAxis(float axisValue) {
	GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("YAxis input : %f"), axisValue * 10));
	cameraArm->AddRelativeRotation(FRotator(axisValue, 0.0f, 0.0f));
	return;
}

void AAF_Pawn::ChangeZoom(float increment) {
	

	//if (!(cameraArm->TargetArmLength >= 300.f && cameraArm->TargetArmLength <= 5000.f)) {
	//	return;
	//}

	if (increment == 0) {
		//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, TEXT("Scroll input detected"));
		//GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Yellow, FString::Printf(TEXT("Scroll input : %f"), increment*10));
	}

	// sign flip to scroll-up = zoom in w/o it's a zoom out
	cameraArm->TargetArmLength += increment * -10;
	return;
}