// Free to play by SoNa Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "QGPawn.generated.h"

UCLASS()
class QUESTGAME_API AQGPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AQGPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
