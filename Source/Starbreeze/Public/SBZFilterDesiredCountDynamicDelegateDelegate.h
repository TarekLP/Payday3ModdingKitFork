#pragma once
#include "CoreMinimal.h"
#include "SBZFilterDesiredCountDynamicDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSBZFilterDesiredCountDynamicDelegate, FName, Identifier, bool, bHasDesiredCount);

