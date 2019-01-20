// Free to play by SoNa Games

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "QGPawn.generated.h"

//Forward Declarations
class UStaticMeshComponent;
class UCameraComponent;
class USpringArmComponent;
class UBoxComponent;

UCLASS()
class QUESTGAME_API AQGPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AQGPawn();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	UStaticMeshComponent * StaticMesh = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	UCameraComponent * Camera = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	USpringArmComponent * SpringArm = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Setup")
	UBoxComponent * BoxComp = nullptr;
	   
	
};
