#pragma once
#include "CoreMinimal.h"
#include "SBZDamageEvent.h"
#include "CharacterTakenDamageDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCharacterTakenDamage, const FSBZDamageEvent&, DamageEventData);

