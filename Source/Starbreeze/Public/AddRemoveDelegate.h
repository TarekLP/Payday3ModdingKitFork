#pragma once
#include "CoreMinimal.h"
#include "AddRemoveDelegate.generated.h"

class UObject;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FAddRemove, UObject*, Obj);

