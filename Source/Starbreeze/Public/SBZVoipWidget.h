#pragma once
#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "SBZWidgetBase.h"
#include "SBZVoipWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USBZVoipWidget : public USBZWidgetBase {
    GENERATED_BODY()
public:
    USBZVoipWidget();
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnPlayerTalkingChangedEvent(const FString& PlayerName, bool bPlayerTalking);
    
private:
    UFUNCTION()
    void OnPlayerTalkingChanged(FUniqueNetIdRepl PlayerId, bool IsTalking);
    
};

