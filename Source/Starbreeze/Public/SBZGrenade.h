#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "SBZAIVisibilityLeafNode.h"
#include "SBZExplosionResult.h"
#include "SBZExplosive.h"
#include "SBZThrowable.h"
#include "SBZGrenade.generated.h"

class AActor;
class UNiagaraComponent;
class UPrimitiveComponent;
class USBZAbilitySystemComponent;

UCLASS(Abstract, Blueprintable)
class ASBZGrenade : public ASBZThrowable, public ISBZExplosive {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USBZAbilitySystemComponent* InstigatorAbilitySystemComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSBZAIVisibilityLeafNode AIVisibilityNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSBZExplosionResult PendingDataExplosionResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UNiagaraComponent* DetonationEffect;
    
public:
    ASBZGrenade();
protected:
    UFUNCTION()
    void OnCollisionComponentHit(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnArmed();
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_ReplicateExplosion(const FSBZExplosionResult& Result);
    
    
    // Fix for true pure virtual functions not being implemented
};

