
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GeneratorComponent.generated.h"

enum class LvlHelpMachine {
	ONE,
	TWO,
	THREE,
	FOR
};

struct Settings {
	FString CurrentSettingsString;
	int Points;
	LvlHelpMachine HelpMachine = LvlHelpMachine::ONE;
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEFORTEST_API UGeneratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	

	UGeneratorComponent();
protected:
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:	
	void Generate();
	float GetPercent(FString string);
	FString MakeHelp(Settings setting);


	Settings GetSettings() { return NewSettings; }
private:
	Settings NewSettings;
	FString Symbols = "XYZOQT";
	
};
