// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	energy_orb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ENERGY_ORB"));

	//Transform 지정.
	RootComponent = body;
	body->SetWorldScale3D(FVector(0.5f));
	energy_orb->SetupAttachment(body);

	energy_orb->SetRelativeLocation(FVector(0, 0, 40.0f));
	energy_orb->SetRelativeScale3D(FVector(0.5f));


	//메시 지정 (레퍼런스 복사 이용)
	ConstructorHelpers::FObjectFinder<UStaticMesh>
		sm_body(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	ConstructorHelpers::FObjectFinder<UStaticMesh>
		sm_energy_orb(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	if (sm_body.Succeeded())
	{
		body->SetStaticMesh(sm_body.Object);
	}
	else
	{
		UE_LOG(LogAssetData, Error, TEXT("body load failed"));
	}

	if (sm_energy_orb.Succeeded())
	{
		energy_orb->SetStaticMesh(sm_energy_orb.Object);
	}
	else
	{
		UE_LOG(LogAssetData, Error, TEXT("sm_energy_orb load failed"));
	}
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

