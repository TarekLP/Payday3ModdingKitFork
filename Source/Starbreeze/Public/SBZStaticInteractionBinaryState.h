#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBZOnInteractionBinaryStateDelegateDelegate.h"
#include "SBZStaticInteractionBinaryState.generated.h"

class USBZBaseInteractableComponent;
class USBZInteractableComponent;
class USBZInteractorComponent;

UCLASS(Blueprintable)
class ASBZStaticInteractionBinaryState : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZOnInteractionBinaryStateDelegate OnStateChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentState, meta=(AllowPrivateAccess=true))
    bool bState;
    
public:
    ASBZStaticInteractionBinaryState();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetInteractionEnabled(bool bEnabled);
    
protected:
    UFUNCTION()
    void OnRep_CurrentState();
    
    UFUNCTION()
    void OnAckCompleteInteraction(USBZBaseInteractableComponent* Interactable, USBZInteractorComponent* Interactor, bool bIsLocallyControlledInteractor);
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_OnStateChanged(bool bNewState, bool bDoCosmentics);
    
};

