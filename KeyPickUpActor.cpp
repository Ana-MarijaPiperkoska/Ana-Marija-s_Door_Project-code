// Fill out your copyright notice in the Description page of Project Settings.

#include "KeyPickUpActor.h"
#include "Components/BoxComponent.h"
#include "AnaMarijas_ProjectCharacter.h"

// Sets default values
AKeyPickUpActor::AKeyPickUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	KeyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMesh"));
	RootComponent = KeyMesh;

	UBoxComponent* CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AKeyPickupActor::OnOverlapBegin);

}

// Called when the game starts or when spawned
void AKeyPickUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKeyPickUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AKeyPickupActor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AAnaMarijas_ProjectCharacter* Character = Cast<AAnaMarijas_ProjectCharacter>(OtherActor);
	if (Character)
	{
		Character->PickupKey();
		Destroy(); // Destroy the key actor once picked up
	}
}
