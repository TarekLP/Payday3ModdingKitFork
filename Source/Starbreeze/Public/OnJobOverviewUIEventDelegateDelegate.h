#pragma once
#include "CoreMinimal.h"
#include "EBlackScreenTransitionType.h"
#include "OnJobOverviewUIEventDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnJobOverviewUIEventDelegate, EBlackScreenTransitionType, BlackScreenTransitionType);

