#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/TimelineComponent.h"
#include "Components/BoxComponent.h"
#include "DoorActor.generated.h"

UCLASS()
class ANAMARIJAS_PROJECT_API ADoorActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void HandleDoor();

private:
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* DoorFrame;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* Door;

	UPROPERTY(VisibleAnywhere, Category = "Collision")
	UBoxComponent* CollisionBox;

	UPROPERTY(EditAnywhere)
	UCurveFloat* CurveFloat;

	UPROPERTY(EditAnywhere)
	float DoorRotateAngle = 90.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool bHasKey = false;

	bool bIsDoorClosed = true;

	FTimeline Timeline;

	UFUNCTION()
	void OpenDoorTimeline(float Value);

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	UFUNCTION(BlueprintCallable, Category = "Door")
	void SetHasKey(bool NewHasKey);
};
