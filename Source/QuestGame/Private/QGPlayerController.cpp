// Free to play by SoNa Games

#include "QGPlayerController.h"
#include "QGPawn.h"
#include "Engine/World.h"
#include "Components/BoxComponent.h"

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
	this->InputComponent->BindAction("Jump", IE_Pressed, this, &AQGPlayerController::Jump);

	MyPawn->BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AQGPlayerController::BeginOverlap);

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

void AQGPlayerController::Jump()
{
	if (!MyPawn) return;
	if (bIsInAir) return;
	FVector FForce = MyPawn->StaticMesh->GetMass() * FVector(0, 0, JumpAcceleration);
	MyPawn->StaticMesh->AddForce(FForce, NAME_None, true);
	bIsInAir = true;

	FTimerHandle TimerHandleJump;
	GetWorld()->GetTimerManager().SetTimer(TimerHandleJump, this, &AQGPlayerController::JumpDecelerate, 0.8f, false);
}

void AQGPlayerController::JumpDecelerate()
{
	if (!MyPawn) return;

	FVector FForce = MyPawn->StaticMesh->GetMass() * FVector(0, 0, -JumpDeceleration);
	MyPawn->StaticMesh->AddForce(FForce, NAME_None, true);
}


void AQGPlayerController::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("Overlapped Actor is %s"), *OtherActor->GetName());
		bIsInAir = false;
	}
}