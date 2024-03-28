#pragma once
#include "CoreMinimal.h"
#include "SBZControlsReference.h"
#include "SBZHUDWidgetBase.h"
#include "SBZUIStackChangedEvent.h"
#include "SBZActionPhaseBaseWidget.generated.h"

class ASBZPlayerController;
class USBZControlsReferenceWidget;
class USBZWidgetBase;

UCLASS(Blueprintable, EditInlineNew)
class USBZActionPhaseBaseWidget : public USBZHUDWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZWidgetBase* Widget_Playing;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZWidgetBase* Widget_Spectating;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZWidgetBase* Widget_Shared;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZControlsReferenceWidget* Widget_ControlsReference;
    
public:
    USBZActionPhaseBaseWidget();
private:
    UFUNCTION()
    void OnStackStateChanged(FSBZUIStackChangedEvent UIStackStateChangedEvent);
    
    UFUNCTION()
    void OnStackLockChanged(bool bIsStackLocked);
    
    UFUNCTION()
    void OnControllerStateChanged(ASBZPlayerController* PlayerController, const FName& OldStateName, const FName& NewStateName);
    
    UFUNCTION()
    void OnActiveControlsReferenceChanged(const FSBZControlsReference& InControlsReference);
    
    UFUNCTION()
    void HideControlsReference();
    
};

