#pragma once
#include "CoreMinimal.h"
#include "OnOutroSequenceStartedDelegateDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOutroSequenceStartedDelegate, const int32, OutroVersion);

