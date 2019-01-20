// Free to play by SoNa Games

#include "QGPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
AQGPawn::AQGPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Static Mesh"));
	BoxComp = CreateDefaultSubobject<UBoxComponent>(FName("Box Component"));
	Camera = CreateDefaultSubobject<UCameraComponent>(FName("Follow Camera"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(FName("Spring Arm"));

	this->SetRootComponent(StaticMesh);
	StaticMesh->SetSimulatePhysics(true);
	StaticMesh->SetGenerateOverlapEvents(false);
	StaticMesh->SetLinearDamping(5.f);

	BoxComp->SetupAttachment(RootComponent);
	BoxComp->SetGenerateOverlapEvents(true);

	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;

	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void AQGPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

