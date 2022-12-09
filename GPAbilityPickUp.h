#pragma once
#include "Components/SphereComponent.h"
#include "GPAbilityPickUp.generated.h"

class UGPAbility;

UCLASS()
class AGPAbilityPickUp : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComponent;
	
	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGPAbility>> AbilityClasses;
	
public:
	AGPAbilityPickUp();

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor, UPrimitiveComponent* OtherComponent,
		int32 BodyIndex, bool bFromSweep, const FHitResult& SweepHit);
};
