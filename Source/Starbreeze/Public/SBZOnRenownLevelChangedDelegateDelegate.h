#pragma once
#include "CoreMinimal.h"
#include "SBZOnRenownLevelChangedDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSBZOnRenownLevelChangedDelegate, int32, NewLevel, int32, PreviousLevel);

