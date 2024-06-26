#pragma once
#include "CoreMinimal.h"
#include "SBZMenuMouseButton.h"
#include "SBZMenuTutorialMouseButton.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USBZMenuTutorialMouseButton : public USBZMenuMouseButton {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsShowing;
    
public:
    USBZMenuTutorialMouseButton();
    UFUNCTION(BlueprintCallable)
    void SetTutorialShowing(bool bInIsShowing);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnShowingTutorialChanged();
    
    UFUNCTION(BlueprintPure)
    bool IsShowingTutorial() const;
    
};

