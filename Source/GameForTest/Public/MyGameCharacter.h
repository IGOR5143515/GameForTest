

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyGameCharacter.generated.h"


class UCameraComponent;
UCLASS()
class GAMEFORTEST_API AMyGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	AMyGameCharacter();

protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

public:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Settings")
	float CharacterRunSpeed = 1000.0f;
	//Functions
	float CharacterWalkSpeed;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void StartRunning();
	void StopRunning();

};
