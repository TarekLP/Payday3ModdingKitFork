#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "Components/SceneComponent.h"
#include "GameplayTagContainer.h"
#include "GameplayTagContainer.h"
#include "ESBZLifeActionState.h"
#include "SBZLifeActionActorTagEvent.h"
#include "SBZLifeActionRandomAnimationTagsPicker.h"
#include "SBZLifeActionRequest.h"
#include "SBZLifeActionSlot.generated.h"

class ASBZCharacter;
class UAnimMontage;
class USBZLifeActionDialogPlayer;
class USBZLifeActionInstance;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USBZLifeActionSlot : public USceneComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag Tag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer GrantedTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ConsumedTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer NeededTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagContainer ExcludedByTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMustBeOccupied;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedOtherSlotsReadyToBeReserved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOpenForRandomReservation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAcceptableRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AcceptableRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAcceptableAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AcceptableAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseCoolDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolDown;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseRandomDuration;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval RandomDesiredDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DesiredDuration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZLifeActionDialogPlayer* DialogPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZLifeActionRandomAnimationTagsPicker RandomAnimationTagsPicker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseEnterAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector EnterLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSnapEnterPointToGround: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag EnterAnimationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseExitAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector ExitLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 bSnapExitPointToGround: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTag ExitAnimationTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bExitOnlyIfActionAnimationIsPlaying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSBZLifeActionActorTagEvent> ActorEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* PlayingActionMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* PlayingEnterMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimMontage* PlayingExitMontage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZCharacter* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsReady;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ESBZLifeActionState State;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 CurrentReservationID;
    
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int16 CurrentMontageIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USBZLifeActionInstance* OwningLifeActionInstance;
    
public:
    USBZLifeActionSlot();
    UFUNCTION(BlueprintCallable)
    void SwitchMontageSection(const FName& SectionName);
    
    UFUNCTION(BlueprintCallable)
    void SwitchMontageNextSection(const FName& SectionName);
    
    UFUNCTION(BlueprintCallable)
    void StopDialog(bool bReset);
    
    UFUNCTION(BlueprintCallable)
    void StartDialog();
    
protected:
    UFUNCTION()
    void OnMontageEnded(UAnimMontage* Montage, bool bInterrupted);
    
    UFUNCTION()
    void OnMontageBlendOut(UAnimMontage* Montage, bool bInterrupted);
    
    UFUNCTION()
    void OnEnterAnimationShouldEnd();
    
    UFUNCTION()
    void OnDesiredDurationReached();
    
    UFUNCTION()
    void OnCharacterAnimEvent(const FGameplayTag& EventTag, bool bActive);
    
public:
    UFUNCTION(BlueprintPure)
    bool MustBeOccupied() const;
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_OnSlotStart(ASBZCharacter* InCharacter);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_OnSlotFreed(ASBZCharacter* InCharacter);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsUsingAnExitAnimation() const;
    
    UFUNCTION(BlueprintPure)
    bool IsUsingAnEnterAnimation() const;
    
    UFUNCTION(BlueprintPure)
    bool IsReservedBy(const ASBZCharacter* InCharacter) const;
    
    UFUNCTION(BlueprintPure)
    bool IsReadyToStart() const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingExitMontage(const ASBZCharacter* InCharacter) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingEnterMontage(const ASBZCharacter* InCharacter) const;
    
    UFUNCTION(BlueprintPure)
    bool IsPlayingActionMontage(const ASBZCharacter* InCharacter) const;
    
    UFUNCTION(BlueprintPure)
    bool IsFree() const;
    
    UFUNCTION(BlueprintPure)
    FGameplayTag GetTag() const;
    
    UFUNCTION(BlueprintPure)
    ESBZLifeActionState GetState() const;
    
    UFUNCTION(BlueprintPure)
    UAnimMontage* GetPlayingActionMontage() const;
    
    UFUNCTION(BlueprintPure)
    FTransform GetMoveToTransform() const;
    
    UFUNCTION(BlueprintPure)
    FRotator GetMoveToRotation() const;
    
    UFUNCTION(BlueprintPure)
    FVector GetMoveToLocation() const;
    
    UFUNCTION(BlueprintPure)
    int32 GetCurrentReservationID() const;
    
    UFUNCTION(BlueprintPure)
    UAnimMontage* GetCurrentExitMontage(const ASBZCharacter* InCharacter) const;
    
    UFUNCTION(BlueprintPure)
    UAnimMontage* GetCurrentEnterMontage(const ASBZCharacter* InCharacter) const;
    
    UFUNCTION(BlueprintPure)
    UAnimMontage* GetCurrentActionMontage(const ASBZCharacter* InCharacter) const;
    
    UFUNCTION(BlueprintPure)
    ASBZCharacter* GetCharacter() const;
    
    UFUNCTION(BlueprintPure)
    float GetAcceptableRadius() const;
    
    UFUNCTION(BlueprintPure)
    float GetAcceptableAngle() const;
    
    UFUNCTION(BlueprintPure)
    bool CanBeReservedBy(const ASBZCharacter* InCharacter, const FSBZLifeActionRequest& Request, bool bLogErrors) const;
    
};

