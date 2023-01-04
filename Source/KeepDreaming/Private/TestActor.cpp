// Fill out your copyright notice in the Description page of Project Settings.


#include "TestActor.h"

// Sets default values
ATestActor::ATestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	energy_orb = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ENERGY_ORB"));
	orb_aura = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ORB_PARTICLE"));

	//Transform
	RootComponent = body;
	body->SetWorldScale3D(FVector(0.5f));

	energy_orb->SetupAttachment(body);
	orb_aura->SetupAttachment(energy_orb);
	energy_orb->SetRelativeLocation(FVector(default_orb_radius, 0, 15.0f));
	
	//
	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		sm_body(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		sm_energy_orb(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));

	static ConstructorHelpers::FObjectFinder<UParticleSystem>
		p_orb_aura(TEXT("/Script/Engine.ParticleSystem'/Game/StarterContent/Particles/P_Smoke.P_Smoke'"));

	if (sm_body.Succeeded())
	{
		body->SetStaticMesh(sm_body.Object);
	}

	if (sm_energy_orb.Succeeded())
	{
		energy_orb->SetStaticMesh(sm_energy_orb.Object);
	}

	if (p_orb_aura.Succeeded())
	{
		orb_aura->SetTemplate(p_orb_aura.Object);
	}
}

// Called when the game starts or when spawned
void ATestActor::BeginPlay()
{
	Super::BeginPlay();

	FVector root_location = RootComponent->GetComponentTransform().GetLocation();
	HJ_LOG(Log, TEXT("root world pos : (%f, %f, %f)"), root_location.X, root_location.Y, root_location.Z);
}

void ATestActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	HJ_CALL_LOG(Log);
}

void ATestActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	HJ_CALL_LOG(Log);
}

// Called every frame
void ATestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector loc = energy_orb->GetRelativeLocation();

	degree += (double)DeltaTime;
	if (degree > 360)
		degree = 0;
	
	loc.X = cos(degree) * default_orb_radius;
	loc.Y = sin(degree) * default_orb_radius;

	energy_orb->SetRelativeLocation(loc);
}

