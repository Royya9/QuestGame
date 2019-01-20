// Free to play by SoNa Games

#include "QGPlayerController.h"
#include "QGPawn.h"

void AQGPlayerController::Possess(APawn * aPawn)
{
	Super::Possess(aPawn);

	if (aPawn)
	{
		MyPawn = Cast<AQGPawn>(aPawn);
	}
	if (MyPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Cast Success and Mypawn is %s"), *MyPawn->GetName());
	}

}


void AQGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	this->InputComponent->BindAxis("MoveRight", this, &AQGPlayerController::MoveRight);
	this->InputComponent->BindAxis("MoveForward", this, &AQGPlayerController::MoveForward);
	this->InputComponent->BindAction("Action", IE_Pressed, this, &AQGPlayerController::PerformAction);
}

void AQGPlayerController::MoveForward(float value)
{
	if (!MyPawn) return;

	FVector FForce = value * MyPawn->StaticMesh->GetMass() * FVector(ForwardAcceleration, 0, 0);
	MyPawn->StaticMesh->AddForce(FForce, NAME_None, true);
}

void AQGPlayerController::MoveRight(float value)
{
	if (!MyPawn) return;

	FVector FForce = value * MyPawn->StaticMesh->GetMass() * FVector(0, SideAcceleration, 0);
	MyPawn->StaticMesh->AddForce(FForce, NAME_None, true);
}

void AQGPlayerController::PerformAction()
{
	if (!MyPawn) return;

	UE_LOG(LogTemp, Warning, TEXT("Pressed Action button"));
}