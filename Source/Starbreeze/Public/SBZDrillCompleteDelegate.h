#pragma once
#include "CoreMinimal.h"
#include "SBZDrillCompleteDelegate.generated.h"

class ASBZDrill;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZDrillComplete, ASBZDrill*, Drill);

