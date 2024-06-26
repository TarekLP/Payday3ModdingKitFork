#pragma once
#include "CoreMinimal.h"
#include "ESBZEquippableLoadoutSlot.h"
#include "OnActiveWeaponSlotChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnActiveWeaponSlotChanged, ESBZEquippableLoadoutSlot, EquippableSlot, int32, EquippableSlotIndex);

