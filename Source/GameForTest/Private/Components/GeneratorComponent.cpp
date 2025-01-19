

#include "Components/GeneratorComponent.h"


UGeneratorComponent::UGeneratorComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UGeneratorComponent::BeginPlay()
{
	Super::BeginPlay();

	
}



void UGeneratorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}

void UGeneratorComponent::Generate()
{
	//Reset NewSeetings
	NewSettings.Points = 0;
	NewSettings.CurrentSettingsString.Empty();
	TArray<TCHAR>Characters;
	//----------------------

	//Generate new random settings
	int NumberOfCharacters = FMath::RandRange(2, Symbols.Len());

	for (size_t i = 0; i < NumberOfCharacters; i++)
	{
		Characters.Add(Symbols[i]);
	}



	for (size_t i = Characters.Num()-1; i > 0; --i)
	{
		int RandomIndex = FMath::RandRange(0, i);

		Characters.Swap(i, RandomIndex);

	}
	for (TCHAR Char : Characters){

		NewSettings.CurrentSettingsString.AppendChar(Char);
	}
	//----------------------

	//Point counting
	for (TCHAR Char : NewSettings.CurrentSettingsString) {
		if (Char == 'X')
			NewSettings.Points += 5;
		if (Char == 'Y')
			NewSettings.Points += 10;
		if (Char == 'Z')
			NewSettings.Points += 15;
		if (Char == 'O')
			NewSettings.Points += 20;
		if (Char == 'Q')
			NewSettings.Points += 25;
		if (Char == 'T')
			NewSettings.Points += 30;
	}
	//----------------------

	UE_LOG(LogTemp, Error, TEXT("%s"), *NewSettings.CurrentSettingsString);
	UE_LOG(LogTemp, Error, TEXT("%i"), NewSettings.Points);

}

float UGeneratorComponent::GetPercent(FString string)
{
	return 0.0f;
}

FString UGeneratorComponent::MakeHelp(Settings setting)
{
	return FString();
}

