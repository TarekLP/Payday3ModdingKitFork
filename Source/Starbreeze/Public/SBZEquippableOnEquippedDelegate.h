#pragma once
#include "CoreMinimal.h"
#include "SBZEquippableOnEquippedDelegate.generated.h"

class ASBZEquippable;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZEquippableOnEquipped, const ASBZEquippable*, Equippable);

