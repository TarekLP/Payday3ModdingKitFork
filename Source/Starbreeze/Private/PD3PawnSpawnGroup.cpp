#include "PD3PawnSpawnGroup.h"

void APD3PawnSpawnGroup::SetEnabledForCivilians(bool bInIsEnabledForCivilians) {
}

void APD3PawnSpawnGroup::SetEnabledForAssault(bool bInIsEnabledForAssault) {
}

void APD3PawnSpawnGroup::OnSpawnFinished(const FSBZPawnSpawnRequestHandle& Handle, APawn* Pawn, ASBZPawnSpawnBase* Spawner) {
}

APD3PawnSpawnGroup::APD3PawnSpawnGroup() {
    this->bIsEnabledForAssault = true;
    this->bIsEnabledForCivilians = false;
}

