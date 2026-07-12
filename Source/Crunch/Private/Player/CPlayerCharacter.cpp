// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/CPlayerCharacter.h"
#include "CPlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

ACPlayerCharacter::ACPlayerCharacter()
{

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());

	ViewCam = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCam"));
	ViewCam->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);

}
