// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"

// Sets default values
AMyGameCharacter::AMyGameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());


}

// Called when the game starts or when spawned
void AMyGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyGameCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &ACharacter::Jump);
}

void AMyGameCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
}

void AMyGameCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

