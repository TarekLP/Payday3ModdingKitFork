#pragma once
#include "CoreMinimal.h"
#include "SBZGameDifficultyChangedEvent.h"
#include "SBZGameDifficultyChangedDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZGameDifficultyChanged, const FSBZGameDifficultyChangedEvent&, GameDifficultyData);

