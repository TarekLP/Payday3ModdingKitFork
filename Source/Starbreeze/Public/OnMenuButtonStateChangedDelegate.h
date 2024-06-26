#pragma once
#include "CoreMinimal.h"
#include "OnMenuButtonStateChangedDelegate.generated.h"

class USBZMenuButton;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMenuButtonStateChanged, USBZMenuButton*, Button, bool, bIsEnabled);

