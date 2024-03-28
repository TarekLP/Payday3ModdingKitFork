#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBZActorOnInteractionDelegate.h"
#include "SBZInteractionActor.generated.h"

class USBZBaseInteractableComponent;
class USBZInteractableComponent;
class USBZInteractorComponent;

UCLASS(Blueprintable)
class ASBZInteractionActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZInteractableComponent* Interactable;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZActorOnInteraction OnAckCompleteInteraction;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZActorOnInteraction OnServerCompleteInteraction;
    
    ASBZInteractionActor();
protected:
    UFUNCTION()
    void HandleServerComplete(USBZBaseInteractableComponent* InteractableComp, USBZInteractorComponent* Interactor, bool bInIsLocallyControlled);
    
    UFUNCTION()
    void HandleAckComplete(USBZBaseInteractableComponent* InteractableComp, USBZInteractorComponent* Interactor, bool bInIsLocallyControlled);
    
};

