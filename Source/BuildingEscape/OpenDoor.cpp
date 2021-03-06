// Fill out your copyright notice in the Description page of Project Settings.

#include "BuildingEscape.h"
#include "OpenDoor.h"


// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();//pawn is a actor

	
}

void UOpenDoor::OpenDoor()
{
	// Find the door
	

	//Create rotator
	FRotator NewRotation = FRotator(0.0f, 0.0f, 0.0f);//pitch yaw roll

	Owner->SetActorRotation(NewRotation);
}

void UOpenDoor::CloseDoor()
{
	// Find the door
	

	//Create rotator
	FRotator NewRotation = FRotator(0.0f, -90.0f, 0.0f);//pitch yaw roll

	Owner->SetActorRotation(NewRotation);
}


// Called every frame
void UOpenDoor::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// Poll the Trigger Volume: check every frame
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	
	//Check if its time to close
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime > DoorCloseDelay)
	{
		CloseDoor();
		LastDoorOpenTime = 0.f;
	}

}

