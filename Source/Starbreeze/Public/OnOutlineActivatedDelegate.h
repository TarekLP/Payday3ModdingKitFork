#pragma once
#include "CoreMinimal.h"
#include "OnOutlineActivatedDelegate.generated.h"

class USBZOutlineComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOutlineActivated, USBZOutlineComponent*, Outline);

