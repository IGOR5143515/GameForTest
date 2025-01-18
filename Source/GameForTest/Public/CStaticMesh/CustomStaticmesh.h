// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "CustomStaticmesh.generated.h"

/**
 * 
 */
UCLASS()
class GAMEFORTEST_API UCustomStaticmesh : public UStaticMeshComponent
{
	GENERATED_BODY()
	
private:
public:
	bool IsPressed = false;

	UPROPERTY(BlueprintReadWrite,EditDefaultsOnly, Category = "Settings")
	int ID;
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Settings")
	FString Symbol;
	
	FString GetSymbol() { return Symbol; }

	UFUNCTION(BlueprintCallable, Category = "Settings")
	int GetID() const { return ID; }

	UFUNCTION(BlueprintCallable, Category = "Settings")
	void SetID(int Value) {
		ID = Value;
	}
	
};
