#pragma once
#include "CoreMinimal.h"
#include "ESBZStoreItemDefaultUICategory.h"
#include "SBZWidgetBase.h"
#include "SBZBlackMarketCategoryWidget.generated.h"

class UWrapBox;

UCLASS(Blueprintable, EditInlineNew)
class USBZBlackMarketCategoryWidget : public USBZWidgetBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWrapBox* Panel_ButtonList;
    
    USBZBlackMarketCategoryWidget();
    UFUNCTION(BlueprintImplementableEvent)
    void SetStoreCategoryName(const FText& InCategoryName);
    
    UFUNCTION(BlueprintPure)
    static FText GetCategoryStringTextFromCategoryEnum(ESBZStoreItemDefaultUICategory InCategory);
    
};

