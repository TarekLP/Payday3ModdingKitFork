#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/OnlineReplStructs.h"
#include "ESBZOnlineCode.h"
#include "OPartyHostUpdatedDelegateDelegate.h"
#include "OnOnlineSessionEventDelegateDelegate.h"
#include "SBZOnlineBeaconHostObject.h"
#include "SBZPartyMemberInfo.h"
#include "SBZPartyBeaconHost.generated.h"

class APlayerState;

UCLASS(Blueprintable, NonTransient)
class STARBREEZE_API ASBZPartyBeaconHost : public ASBZOnlineBeaconHostObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnOnlineSessionEventDelegate OnPartyJoined;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOPartyHostUpdatedDelegate OnPartyUpdated;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSBZPartyMemberInfo> PartyMembers;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PartyTravelTimeout;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PartyDisconnectTimeout;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FUniqueNetIdRepl> TravellingMembers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle TravelTimeoutTimer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FUniqueNetIdRepl> LeavingMembers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTimerHandle LeaveLobbyTimeoutTimer;
    
public:
    ASBZPartyBeaconHost();
    UFUNCTION()
    void NotifyClientLeftLobby(const FUniqueNetIdRepl& PartyMemberId);
    
    UFUNCTION()
    void NotifyClientFailedConnectionToLobby(const FUniqueNetIdRepl& PartyMemberNetId);
    
    UFUNCTION()
    void NotifyClientConnectedToLobby(const FUniqueNetIdRepl& PartyMemberNetId);
    
private:
    UFUNCTION()
    void HandlePartyTravelTimeout();
    
    UFUNCTION()
    void HandlePartyLeaveLobbyTimeout();
    
protected:
    UFUNCTION()
    void FirePartyUpdated(APlayerState* ChangedPlayerState);
    
private:
    UFUNCTION()
    void BroadcastPartyTravelled(ESBZOnlineCode Result);
    
    UFUNCTION()
    void BroadcastPartyLeftLobby(ESBZOnlineCode Result);
    
};

