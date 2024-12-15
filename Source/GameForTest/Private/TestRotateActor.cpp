// Fill out your copyright notice in the Description page of Project Settings.


#include "TestRotateActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ATestRotateActor::ATestRotateActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}

// Called when the game starts or when spawned
void ATestRotateActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestRotateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator RotationDelta(0.0f, DeltaTime * 60.0f, 0.0f); 
	Mesh->AddLocalRotation(RotationDelta);

}

