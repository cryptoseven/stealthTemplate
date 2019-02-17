// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSOBjectiveActor.generated.h"

class USphereComponent;

UCLASS()
class FPSGAME_API AFPSOBjectiveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSOBjectiveActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* meshComp;
	UPROPERTY(VisibleAnywhere, Category = "Components")
	USphereComponent* sphereComp;
	void playEffects();
	UPROPERTY(EditDefaultsOnly, Category = "FX")
	UParticleSystem* pickupFX;

public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
};
