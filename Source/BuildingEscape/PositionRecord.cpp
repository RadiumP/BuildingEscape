// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "PositionRecord.h"


// Sets default values for this component's properties
UPositionRecord::UPositionRecord()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...

	
}


// Called when the game starts
void UPositionRecord::BeginPlay()
{
	Super::BeginPlay();

	// ...

	FString name = GetOwner()->GetName();

	//careful: pointer
	UE_LOG(LogTemp, Warning, TEXT("Hello World! This is a %s"), *name);//yellow output https://wiki.unrealengine.com/Logs,_Printing_Messages_To_Yourself_During_Runtime
}


// Called every frame
void UPositionRecord::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

