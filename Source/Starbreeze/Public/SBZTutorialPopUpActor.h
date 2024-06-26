#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBZControlsReference.h"
#include "SBZOnPopUpWidgetClosedDelegate.h"
#include "SBZSideBarNotificationData.h"
#include "SBZTutorialPopUpActor.generated.h"

class USBZTutorialPopUpDataAsset;

UCLASS(Blueprintable)
class ASBZTutorialPopUpActor : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USBZTutorialPopUpDataAsset*> TutorialPopUpArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSBZSideBarNotificationData> SideBarNotificationArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSBZControlsReference> ControlsReferenceArray;
    
public:
    ASBZTutorialPopUpActor();
    UFUNCTION(BlueprintCallable)
    void ShowTutorialPopUp(const int32 TutorialIndex, FSBZOnPopUpWidgetClosed InTutorialPopUpClosed);
    
    UFUNCTION(BlueprintCallable)
    void ShowSideBarNotification(const int32 NotificationIndex);
    
    UFUNCTION(BlueprintCallable)
    void ShowControlsReference(const int32 ReferenceIndex);
    
protected:
    UFUNCTION(Reliable, Server)
    void Server_CloseTutorialPopUp();
    
    UFUNCTION()
    void OnActionPhaseEntered();
    
    UFUNCTION()
    void CloseTutorialPopUp(FName ClosingActionName);
    
    UFUNCTION(Client, Reliable)
    void Client_ShowTutorialPopUp(const int32 Index);
    
    UFUNCTION(Client, Reliable)
    void Client_ShowSideBarNotification(const int32 Index);
    
    UFUNCTION(Client, Reliable)
    void Client_ShowControlsReference(const int32 Index);
    
};

