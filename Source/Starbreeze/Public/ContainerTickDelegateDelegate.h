#pragma once
#include "CoreMinimal.h"
#include "ContainerTickDelegateDelegate.generated.h"

class USBZObjectContainer;

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_TwoParams(FContainerTickDelegate, USBZObjectContainer*, Container, float, DeltaTime);

