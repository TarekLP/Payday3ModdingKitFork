#pragma once
#include "CoreMinimal.h"
#include "SBZPlayerPingEvent.h"
#include "SBZOnPlayerPingedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZOnPlayerPinged, const FSBZPlayerPingEvent&, PingEventData);

