#pragma once
#include "CoreMinimal.h"
#include "SBZWidgetBase.h"
#include "SBZDebugWidget.generated.h"

class UTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class USBZDebugWidget : public USBZWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTextBlock* Text_SubtitleText;
    
public:
    USBZDebugWidget();
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnWatermarkMode();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnMissionSeedSet(int32 MissionSeed);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnFullscreenMode();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnCinematicMode();
    
};

