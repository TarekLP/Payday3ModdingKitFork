#pragma once
#include "CoreMinimal.h"
#include "SBZEquippableOnUnequippedDelegate.generated.h"

class ASBZEquippable;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZEquippableOnUnequipped, const ASBZEquippable*, Equippable);

