#pragma once
#include "CoreMinimal.h"
#include "SBZOnFBIActivationChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZOnFBIActivationChanged, bool, bIsActive);

