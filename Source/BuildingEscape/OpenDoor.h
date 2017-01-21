// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	//make private visable etc in Unreal: like in Unity public
	UPROPERTY(VisibleAnywhere)
	float OpenAngle = 0.0f;
	
	//relate to TriggerVolume to trigger events		
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	UPROPERTY(EditAnywhere)
		float DoorCloseDelay = 0.5f;
	float LastDoorOpenTime;

	//pawn inherits from Actor
	AActor* ActorThatOpens;
	AActor* Owner = GetOwner();
};
