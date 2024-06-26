#pragma once
#include "CoreMinimal.h"
#include "SBZWheeledVehicleOnBeginObstacleDelegate.generated.h"

class AActor;
class ASBZWheeledVehicle;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSBZWheeledVehicleOnBeginObstacle, ASBZWheeledVehicle*, Vehicle, AActor*, Actor);

