#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ESBZEquippableLoadoutSlot.h"
#include "ESBZMetaRequestResult.h"
#include "SBZButtonControlReference.h"
#include "SBZMenuStackInventoryBaseScreen.h"
#include "Templates/SubclassOf.h"
#include "SBZMainMenuWeaponInventoryScreen.generated.h"

class UPanelWidget;
class USBZBaseInventoryItemVisualsWidget;
class USBZBlackMarketStoreItemButton;
class USBZInventoryBaseData;
class USBZMainMenuLoadoutWeaponSlotButton;
class USBZMenuButton;

UCLASS(Blueprintable, EditInlineNew)
class USBZMainMenuWeaponInventoryScreen : public USBZMenuStackInventoryBaseScreen {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USBZMainMenuLoadoutWeaponSlotButton> WeaponSlotButtonClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* Panel_WeaponSlotButtons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESBZEquippableLoadoutSlot EquippableSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 CurrentLoadoutIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActiveWeaponSlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 ActiveLoadoutWeaponSlotIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ActiveWeaponSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WeaponSlotCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USBZBlackMarketStoreItemButton* Button_WeaponSlotStoreItem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<USBZBaseInventoryItemVisualsWidget> DiscardWeaponPopUpBodyWidgetClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DiscardWeaponPopUpHeader;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZButtonControlReference DiscardWeaponPopUpAcceptAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSBZButtonControlReference DiscardWeaponPopUpCancelAction;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 WeaponToDiscardIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USBZBaseInventoryItemVisualsWidget* DiscardWeaponPopUpBody;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<USBZMainMenuLoadoutWeaponSlotButton*> WeaponSlotButtonPool;
    
public:
    USBZMainMenuWeaponInventoryScreen();
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void WeaponSlotStoreItemTransactionComplete(ESBZMetaRequestResult MetaResult, const USBZInventoryBaseData* InventoryItemData);
    
    UFUNCTION(BlueprintImplementableEvent)
    void WeaponSlotButtonFocusedChanged(USBZMenuButton* SelectedButton, bool bIsFocused);
    
private:
    UFUNCTION()
    void UpdateWeaponSlotButtons();
    
public:
    UFUNCTION(BlueprintCallable)
    void UpdateActiveWeaponSlotIndex(int32 InNewIndex);
    
protected:
    UFUNCTION(BlueprintCallable)
    bool TryDiscardWeaponInIndex(int32 SlotIndex);
    
    UFUNCTION()
    void TryBuyWeaponSlot(USBZMenuButton* InSelectedButton);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnWeaponSlotScreenDisplayed();
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnWeaponInSlotDiscarded(bool bIsWeaponDiscarded);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnTryBuyWeaponSlot();
    
    UFUNCTION()
    void OnShowBuySlotPopUpClosed(FName InActionName);
    
    UFUNCTION(BlueprintImplementableEvent)
    void OnNewSlotPurchased();
    
private:
    UFUNCTION()
    void OnDiscardWeaponPopUpClosed(FName ClosingActionName);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnBuyWeaponSlotTransactionFailed(ESBZMetaRequestResult Result);
    
private:
    UFUNCTION()
    void OnBuyWeaponSlotItemCompleted(ESBZMetaRequestResult Result, FGuid ItemId);
    
protected:
    UFUNCTION(BlueprintImplementableEvent)
    void OnActiveWeaponChanged();
    
private:
    UFUNCTION()
    void NativeOnWeaponSlotStoreItemTransactionComplete(ESBZMetaRequestResult MetaResult, const USBZInventoryBaseData* InventoryItemData);
    
    UFUNCTION()
    void NativeOnWeaponSlotButtonSelected(USBZMenuButton* InSelectedButton);
    
    UFUNCTION()
    void HandleProgressionSave(ESBZMetaRequestResult Result);
    
public:
    UFUNCTION(BlueprintCallable)
    bool DisplayWeaponInventoryScreen(int32 InLoadoutIndex, ESBZEquippableLoadoutSlot InEquippableSlot);
    
private:
    UFUNCTION()
    void DiscardItemDone(ESBZMetaRequestResult BuyItemResult, FGuid ItemId);
    
protected:
    UFUNCTION(BlueprintPure)
    bool CanDiscardWeaponIndex(int32 InWeaponIndex) const;
    
};

