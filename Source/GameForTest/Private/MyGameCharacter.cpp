// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyPlayerController.h"
#include "CStaticMesh/CustomStaticmesh.h"
#include "Components/GeneratorComponent.h"

// Sets default values
AMyGameCharacter::AMyGameCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());

	Generator = CreateDefaultSubobject<UGeneratorComponent>("Generator");

}

// Called when the game starts or when spawned
void AMyGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}


void AMyGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AMyGameCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyGameCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyGameCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Yaw", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Pitch", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed,this, &ACharacter::Jump);

	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AMyGameCharacter::StartRunning);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AMyGameCharacter::StopRunning);

	PlayerInputComponent->BindAction("Action", IE_Pressed, this, &AMyGameCharacter::MakeTrace);

	PlayerInputComponent->BindAction("TestGenerateButton", IE_Pressed, Generator, &UGeneratorComponent::Generate);

}

void AMyGameCharacter::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(),Value);
}

void AMyGameCharacter::MoveRight(float Value)
{
	AddMovementInput(GetActorRightVector(), Value);
}

void AMyGameCharacter::StartRunning()
{
	CharacterWalkSpeed = GetCharacterMovement()->MaxWalkSpeed;
	GetCharacterMovement()->MaxWalkSpeed=CharacterRunSpeed;

}

void AMyGameCharacter::StopRunning()
{
	GetCharacterMovement()->MaxWalkSpeed = CharacterWalkSpeed;
}

void AMyGameCharacter::MakeTrace()
{
	
	FVector Location;
	FRotator Rotation;
	Controller->GetPlayerViewPoint(Location,Rotation);

	FVector End = Location + (Rotation.Vector() * 250);
	FCollisionQueryParams  CCH;
	CCH.AddIgnoredActor(this);

	if (!GetWorld())return;
	bool IsHit = GetWorld()->LineTraceSingleByChannel(HitResult, Location, End, ECC_Visibility, CCH);

	if (IsHit) {
		UCustomStaticmesh* mesh = Cast<UCustomStaticmesh>(HitResult.GetComponent());

		//if (!mesh||mesh->GetID()==0||!mesh->IsPressed||MachineSettingsString.Len()<4)return;
		if (!mesh || mesh->IsPressed|| mesh->GetID() == 0)return;

		MachineSettingsString.Append(mesh->GetSymbol());
		mesh->IsPressed = true;

	UE_LOG(LogTemp, Error, TEXT("%s"), *MachineSettingsString);
	}

}

