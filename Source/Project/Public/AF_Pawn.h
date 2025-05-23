// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/ChildActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraComponent.h"

#include "AF_InfoCard.h"
#include "AF_BodyPart.h"

#include "AF_Pawn.generated.h"

UCLASS()
class PROJECT_API AAF_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAF_Pawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	bool bInfoWidgetExpanded;

	UPROPERTY(EditDefaultsOnly, Category = "Model")
	UStaticMeshComponent* modelMesh;
	UPROPERTY(EditDefaultsOnly, Category = "Body Parts")
	UAF_BodyPart* bodyPart_test;
	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	USpringArmComponent* cameraArm;
	UPROPERTY(EditDefaultsOnly, Category = "Camera")
	UCameraComponent* userCam;

	void PanXAxis(float axisValue);
	void PanYAxis(float axisValue);
	void ChangeZoom(float increment);
};
