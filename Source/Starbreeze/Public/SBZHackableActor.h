#pragma once
#include "CoreMinimal.h"
#include "Perception/AISightTargetInterface.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "ESBZHackableActorInterruptReason.h"
#include "ESBZHackableActorState.h"
#include "ESBZHackableActorUnlockMode.h"
#include "SBZAIActionInteractableInterface.h"
#include "SBZAIAttractorInterface.h"
#include "SBZCodeViewerInterface.h"
#include "SBZGameplayEffectData.h"
#include "SBZHackableActorDelegateDelegate.h"
#include "SBZHackableActorInterruptedDelegateDelegate.h"
#include "SBZHackableDisplayText.h"
#include "SBZHackableProgressData.h"
#include "SBZObjectiveInformationInterface.h"
#include "SBZRoomVolumeInterface.h"
#include "SBZHackableActor.generated.h"

class APawn;
class ASBZRoomVolume;
class USBZAIAttractorComponent;
class USBZBaseInteractableComponent;
class USBZGameplayAbilityQuery;
class USBZInteractableComponent;
class USBZInteractorComponent;
class USBZLifeActionComponent;
class USBZLifeActionInstance;
class USBZLifeActionSlot;
class USBZMarkerDataAsset;
class USBZOutlineComponent;
class USBZShoutTargetComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class ASBZHackableActor : public AActor, public ISBZAIActionInteractableInterface, public IAISightTargetInterface, public ISBZRoomVolumeInterface, public ISBZCodeViewerInterface, public ISBZObjectiveInformationInterface, public ISBZAIAttractorInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZHackableActorDelegate OnHackingStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZHackableActorDelegate OnHackingResumed;
    
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZHackableActorDelegate OnHackingUnlocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZHackableActorDelegate OnHackingComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZHackableActorInterruptedDelegate OnHackingInterrupted;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZInteractableComponent* InteractableComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZOutlineComponent* OutlineComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZAIAttractorComponent* AttractorComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZLifeActionComponent* LifeActionComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZLifeActionInstance* LifeActionInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZLifeActionSlot* LifeActionSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* StaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZShoutTargetComponent* ShoutTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZMarkerDataAsset* InteractionMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZMarkerDataAsset* FixMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZMarkerDataAsset* HackingMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESBZHackableActorUnlockMode UnlockMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DurationSeconds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USBZGameplayAbilityQuery* ItemUnlockGameplayInteractionQuery;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZGameplayEffectData GameplayEffectOnInteract;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bWillInterrupt;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval InterruptionTimeInterval;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CustomProcessText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText CustomSuccessText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_CurrentState, meta=(AllowPrivateAccess=true))
    ESBZHackableActorState CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ProgressData, meta=(AllowPrivateAccess=true))
    FSBZHackableProgressData ProgressData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASBZRoomVolume*> RoomVolumes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSBZHackableDisplayText> DisplayTexts;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumberOfCodesToView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CodeEmailIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DisplayTextIndex, meta=(AllowPrivateAccess=true))
    uint8 CurrentDisplayTextIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FText ObjectiveInfo;
    
public:
    ASBZHackableActor();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    bool VisionPredicate(const AActor* Viewer) const;
    
public:
    UFUNCTION(BlueprintCallable)
    void UpdateDisplayTextImportantInformation(const int32 IndexToUpdate, const FText& InText);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetInteractionEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ResetHackableActor(const float InDuration, bool bKeepCustomMessage, ESBZHackableActorState ResetState);
    
protected:
    UFUNCTION()
    void OnRep_ProgressData();
    
    UFUNCTION()
    void OnRep_DisplayTextIndex();
    
    UFUNCTION()
    void OnRep_CurrentState(ESBZHackableActorState OldState);
    
    UFUNCTION()
    void OnInteractionStateChanged(const USBZBaseInteractableComponent* InInteractableComponent, bool bInNewState);
    
    UFUNCTION()
    void OnAckCompleteInteraction(USBZBaseInteractableComponent* Interactable, USBZInteractorComponent* Interactor, bool bIsLocallyControlledInteractor);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetUpdateFrequency(float NewUpdateFrequency);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SetState(ESBZHackableActorState NewState);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_ResetHackableActor(bool bKeepCustomMessage);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void InterruptHacking(ESBZHackableActorInterruptReason InReason);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void BP_UpdateProgressBar(int32 ProgressDone);
    
    UFUNCTION(BlueprintCosmetic, BlueprintImplementableEvent)
    void BP_UpdateCustomSuccessText(const FText& SucessText);
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_OnUnlocked();
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_OnStateChanged(ESBZHackableActorState OldState, ESBZHackableActorState NewState);
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_OnHackingStarted(const FText& ProcessText);
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_GainedAccess();
    
    UFUNCTION(BlueprintCosmetic, BlueprintImplementableEvent)
    void BP_DisplayTextIndexChanged(const int32 NewIndex);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ActivateHackableActor();
    
    
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool SetEnabled(bool bEnabled) override PURE_VIRTUAL(SetEnabled, return false;);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetAttractorInstigator(APawn* NewInstigator) override PURE_VIRTUAL(SetAttractorInstigator,);
    
};

