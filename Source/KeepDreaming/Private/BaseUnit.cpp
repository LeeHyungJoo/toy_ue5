// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUnit.h"

// Sets default values for this component's properties
UBaseUnit::UBaseUnit()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogInit, Error, TEXT("UBaseUnit Init!"));
	// ...
}


// Called when the game starts
void UBaseUnit::BeginPlay()
{

	Super::BeginPlay();
	UE_LOG(LogInit, Error, TEXT("UBaseUnit BeginPlay!"));
	// ...
	
}


// Called every frame
void UBaseUnit::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	UE_LOG(LogInit, Error, TEXT("U_BASEUNIT_TICK : %f"), DeltaTime);
}

