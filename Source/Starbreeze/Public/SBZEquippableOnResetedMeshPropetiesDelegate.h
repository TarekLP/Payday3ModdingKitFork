#pragma once
#include "CoreMinimal.h"
#include "SBZEquippableOnResetedMeshPropetiesDelegate.generated.h"

class UMeshComponent;
class USBZOutlineComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSBZEquippableOnResetedMeshPropeties, const UMeshComponent*, Reference, USBZOutlineComponent*, OutlineComponent);

