#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SBZBagHandle.h"
#include "SBZBagPersistentData.h"
#include "SBZBagManager.generated.h"

class AActor;
class UObject;
class USBZBagManager;
class USBZBagType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USBZBagManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FSBZBagPersistentData> Bags;
    
public:
    USBZBagManager();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool TryRemoveClaim(FSBZBagHandle Handle, AActor* Actor);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool SecureBag(FSBZBagHandle Handle, bool bClearClaim);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool RemoveClaim(FSBZBagHandle Handle, AActor* Actor);
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_SecureBag(const int32 BagId, const bool bClearClaim);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_RemoveClaim(const int32 BagId);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_RemoveBag(const int32 BagId);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_CreateBagArray(const int32 FirstBagId, const USBZBagType* BagType, const int32 NumberOfBags);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_CreateBag(const int32 BagId, const USBZBagType* BagType);
    
    UFUNCTION(NetMulticast, Reliable)
    void Multicast_ClaimBag(const int32 BagId, AActor* Actor);
    
public:
    UFUNCTION(BlueprintPure)
    bool IsValidHandle(const FSBZBagHandle& Handle) const;
    
    UFUNCTION(BlueprintPure)
    FSBZBagPersistentData GetValidBagData(FSBZBagHandle Handle) const;
    
    UFUNCTION(BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static USBZBagManager* Get(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    FSBZBagHandle CreateBag(const USBZBagType* BagType);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool ClaimBag(FSBZBagHandle Handle, AActor* Actor);
    
};

