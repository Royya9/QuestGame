// Free to play by SoNa Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "QGPlayerController.generated.h"

//Forward Declarations

class AQGPawn;

/**
 * 
 */
UCLASS()
class QUESTGAME_API AQGPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void Possess(APawn* aPawn) override;
	virtual void BeginPlay() override;
//	virtual void Tick(float DeltaSeconds) override;

	void MoveRight(float value);
	void MoveForward(float value);

	void PerformAction();

	AQGPawn * MyPawn = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Setup")
	float ForwardAcceleration = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Setup")
	float SideAcceleration = 10.f;

};
