#pragma once
#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "SBZOnPlayerStartTravelEventDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZOnPlayerStartTravelEvent, const FUniqueNetIdRepl&, InPlayerId);

