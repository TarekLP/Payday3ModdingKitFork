#pragma once
#include "CoreMinimal.h"
#include "SBZVehicleOnSwitchSplineDirectionDelegate.generated.h"

class ASBZSpline;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZVehicleOnSwitchSplineDirection, ASBZSpline*, Spline);

