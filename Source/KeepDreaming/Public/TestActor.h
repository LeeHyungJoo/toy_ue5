// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActor.generated.h"

UCLASS()
class KEEPDREAMING_API ATestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* body;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* energy_orb;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* orb_aura;
	

	UPROPERTY(EditAnyWhere, Category="default_orb_radius")
	int32 default_orb_radius = 120;

	double degree = 90.0;
};
