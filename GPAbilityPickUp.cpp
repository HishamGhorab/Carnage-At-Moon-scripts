#include "GPAbilityPickUp.h"
#include "GPAbility.h"
#include "GPPlayerController.h"
#include "Components/SphereComponent.h"

AGPAbilityPickUp::AGPAbilityPickUp()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->SetupAttachment(Root);
	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AGPAbilityPickUp::HandleOverlap);
}

void AGPAbilityPickUp::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 BodyIndex, bool bFromSweep, const FHitResult& SweepHit)
{
	const int randomIndex = FMath::RandRange(0, AbilityClasses.Num() - 1);
	const auto abilityClass = AbilityClasses[randomIndex];
	
	AGPPlayerController* playerController = Cast<AGPPlayerController>(OtherActor);
	playerController->Ability = NewObject<UGPAbility>(playerController, abilityClass);
	
	Destroy();
}
