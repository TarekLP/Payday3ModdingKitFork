#pragma once
#include "CoreMinimal.h"
#include "SBZVehicleOnSplineEnteredDelegate.generated.h"

class ASBZSpline;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FSBZVehicleOnSplineEntered, ASBZSpline*, Spline, bool, bPathEntered, bool, bTeleportToPathStart);

