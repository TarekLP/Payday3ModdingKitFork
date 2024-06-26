#pragma once
#include "CoreMinimal.h"
#include "ESBZVehicleSpawnResult.h"
#include "SBZSpawnCompletedDelegateBPDelegate.generated.h"

class USBZVehicleSpawnComponent;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSBZSpawnCompletedDelegateBP, USBZVehicleSpawnComponent*, VehicleSpawnComponent, ESBZVehicleSpawnResult, Result);

