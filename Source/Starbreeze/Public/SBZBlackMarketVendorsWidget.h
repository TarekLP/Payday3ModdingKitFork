#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESBZMetaRequestResult.h"
#include "SBZActionControlReference.h"
#include "SBZBlackMarketUIVendorData.h"
#include "SBZButtonControlReference.h"
#include "SBZMenuStackScreenWidgetWithTutorial.h"
#include "SBZStoreItemUIData.h"
#include "SBZUIPopupData.h"
#include "Templates/SubclassOf.h"
#include "SBZBlackMarketVendorsWidget.generated.h"

class UPanelWidget;
class USBZBlackMarketCategoryWidget;
class USBZBlackMarketConfirmationPopupBody;
class USBZBlackMarketStoreItemButton;
class USBZBlackMarketVendorButton;
class USBZControlsReferenceActionWidget;
class USBZInventoryBaseData;
class USBZLocalNavBar;
class USBZMenuButton;
class USBZWidgetBase;

UCLASS(Blueprintable, EditInlineNew)
class USBZBlackMarketVendorsWidget : public USBZMenuStackScreenWidgetWithTutorial {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* Panel_CategoriesList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZLocalNavBar* Navbar_Vendors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USBZBlackMarketCategoryWidget> CategoryButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USBZBlackMarketStoreItemButton> StoreItemButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USBZBlackMarketStoreItemButton> GoldStoreItemButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZActionControlReference PaydayStoreControlsReferenceAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* Panel_VendorList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZControlsReferenceActionWidget* ControlsRefActionWidget_PaydayStore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USBZBlackMarketVendorButton> VendorButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsTransactionInProgress;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActiveVendorIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSBZBlackMarketUIVendorData> VendorsData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USBZBlackMarketStoreItemButton* PurchaseTargetButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSBZStoreItemUIData PurchaseSlotUIData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USBZBlackMarketStoreItemButton*> StoreItemButtonPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USBZBlackMarketStoreItemButton*> GoldStoreItemButtonPool;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USBZBlackMarketConfirmationPopupBody> PurchaseItemPopUpBodyWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USBZWidgetBase> PurchaseItemSlotPopUpBodyWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PurchaseItemPopUpHeader;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZButtonControlReference PurchaseItemPopUpAcceptAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZButtonControlReference PurchaseItemPopUpCancelAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FSBZUIPopupData PopUpData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USBZBlackMarketConfirmationPopupBody* PurchaseItemPopUpBody;
    
public:
    USBZBlackMarketVendorsWidget();
protected:
    UFUNCTION(BlueprintCallable)
    void UpdateActiveVendor(int32 NewActiveVendorIndex);
    
private:
    UFUNCTION()
    void TryBuyItem(FSBZStoreItemUIData StoreItemUIData);
    
    UFUNCTION()
    void SendPurchaseAttemptEvent(const bool bIsAcceptPressed);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnVendorItemTransactionComplete(ESBZMetaRequestResult MetaResult, const USBZInventoryBaseData* InventoryItemData);
    
    UFUNCTION()
    void OnVendorItemButtonSelected(USBZMenuButton* InButton);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnVendorItemButtonFocused(USBZMenuButton* InButton, bool bIsFocused);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnVendorChanged(const FSBZBlackMarketUIVendorData& NewVendor);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnVendorButtonFocused(USBZMenuButton* InButton, bool bIsFocused);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnTransactionProgressChanged(bool bInIsTransactionInProgress, bool bIsTransactionSuccessful);
    
private:
    UFUNCTION()
    void OnRefreshCurrentVendor();
    
    UFUNCTION()
    void OnPurchaseItemPopUpClosed(FName ClosingActionName);
    
    UFUNCTION()
    void OnBuyRealMoneyItemCompleted(ESBZMetaRequestResult Result);
    
    UFUNCTION()
    void OnBuyItemCompleted(ESBZMetaRequestResult Result, FGuid ItemId);
    
    UFUNCTION()
    void NativeOnVendorButtonSelected(USBZMenuButton* InButton);
    
public:
    UFUNCTION(BlueprintCallable)
    void GoToPreviousVendor();
    
    UFUNCTION(BlueprintCallable)
    void GoToNextVendor();
    
protected:
    UFUNCTION(BlueprintPure)
    USBZBlackMarketCategoryWidget* GetFirstCategoryWidget();
    
    UFUNCTION(BlueprintPure)
    USBZBlackMarketVendorButton* GetActiveVendorButton() const;
    
};

