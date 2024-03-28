#pragma once
#include "CoreMinimal.h"
#include "ESBZMetaRequestResult.generated.h"

UENUM(BlueprintType)
enum class ESBZMetaRequestResult : uint8 {
    Ok,
    AccelByteHttpClientRequestError,
    AccelByteHttpServerError,
    AccelBytePlatformError,
    AccelByteNamespaceError,
    AccelByteProfileError,
    AccelByteBuildInfoError,
    AccelByteCategoryError,
    AccelByteEntitlementError,
    AccelByteOrderError,
    AccelBytePaymentError,
    AccelByteWalletError,
    AccelByteCurrencyError,
    AccelByteCampaignError,
    AccelByteSocialError,
    AccelByteFavoriteError,
    AccelByteOffenseError,
    AccelByteStatisticError,
    AccelByteLeaderboardError,
    AccelByteCloudSaveError,
    AccelByteDedicatedServerNotFound,
    AccelByteDedicatedServerConfigNotFound,
    AccelByteUnknownError,
    AccelByteJsonDeserializationFailed,
    AccelByteInvalidRequest,
    AccelByteInvalidResponse,
    AccelByteNetworkError,
    AccelByteIsNotLoggedIn,
    AccelByteDsRegistrationConflict,
    AccelBytePartyStorageError,
    AccelByteInsufficientFunds,
    AccelByteBackendFailure,
    AccelByteUnauthorized,
    AccelByteInvalidOrder,
    AccelBytePlayerRecordNotFoundException,
    AccelByteLobbyNotConnectedError,
    AccelByteLobbySetupChallengesError,
    AccelByteFailedToSyncDLC,
    NoAvailableInventorySlot,
    AccelByteSavedDataAfterResetOK,
    AccelByteSavedDataAfterResetFailed,
    LoadoutIndexOutOfRange,
    WeaponSlotIndexOutOfRange,
    InvalidAccelByteOperationForClient,
    SkillNotProgressed,
    SkillAlreadyResearched,
    SkillEquipped,
    SkillNotEquipped,
    MissingLoadoutItem,
    MissingStoreItem,
    InvalidItemTypeInStoreRequest,
    FailedToAddWeaponToInventorySlot,
    InvalidGameConfiguration,
    FailedToDeleteUserAccount,
    MissingEntitlementToConsume,
    ApplyCosmeticsFailed,
    UpgradeSaveDataFailed,
    InvalidState,
    FailedToPurchaseRealMoneyItem,
    FailedToQueryAchievements,
    InventoryItemCannotBeDiscarded,
    FailedToGetReceipts,
    HaveNotReceivedInitialRewards,
    MissingEnitlementPermission,
};

