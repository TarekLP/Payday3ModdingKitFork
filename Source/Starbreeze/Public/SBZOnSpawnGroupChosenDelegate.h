#pragma once
#include "CoreMinimal.h"
#include "SBZOnSpawnGroupChosenDelegate.generated.h"

class ASBZPlayerStartGroup;

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSBZOnSpawnGroupChosen, ASBZPlayerStartGroup*, PlayerStartGroup);

