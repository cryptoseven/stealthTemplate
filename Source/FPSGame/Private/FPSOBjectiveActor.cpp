// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSOBjectiveActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "FPSCharacter.h"

// Sets default values
AFPSOBjectiveActor::AFPSOBjectiveActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(meshComp);
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	sphereComp->SetupAttachment(meshComp);
	sphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	sphereComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	sphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
}

// Called when the game starts or when spawned
void AFPSOBjectiveActor::BeginPlay()
{
	Super::BeginPlay();
	playEffects();
	
}

void AFPSOBjectiveActor::playEffects()
{
	UGameplayStatics::SpawnEmitterAtLocation(this,pickupFX, GetActorLocation());
}

// Called every frame
//void AFPSOBjectiveActor::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void AFPSOBjectiveActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	AFPSCharacter* myChar = Cast<AFPSCharacter>(OtherActor);
	if (myChar) {
		playEffects();

		myChar->isCarryingObjective = true;

		Destroy();
	}
}

