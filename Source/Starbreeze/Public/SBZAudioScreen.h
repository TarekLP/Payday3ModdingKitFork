#pragma once
#include "CoreMinimal.h"
#include "EAkCallbackType.h"
#include "GameFramework/Actor.h"
#include "ESBZEventReactorState.h"
#include "SBZRoomVolumeInterface.h"
#include "SBZAudioScreen.generated.h"

class ASBZRoomVolume;
class UAkCallbackInfo;
class UAkComponent;

UCLASS(Blueprintable)
class ASBZAudioScreen : public AActor, public ISBZRoomVolumeInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAkComponent* AkComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZRoomVolume* CurrentRoom;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESBZEventReactorState CurrentReactorState;
    
public:
    ASBZAudioScreen();
protected:
    UFUNCTION()
    void OnAudioEventComplete(EAkCallbackType Type, UAkCallbackInfo* CallbackInfo);
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_OnReactorStateChanged(ESBZEventReactorState NewState, bool bDoCosmetics);
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_Deactivate();
    
    UFUNCTION(BlueprintImplementableEvent)
    void BP_Activate();
    
    
    // Fix for true pure virtual functions not being implemented
};

