#pragma once
#include "CoreMinimal.h"
#include "AccelByteModelsGetOnlineUsersResponse.h"
#include "DGetAllFriendsStatusResponseDelegate.generated.h"

UDELEGATE() DECLARE_DYNAMIC_DELEGATE_OneParam(FDGetAllFriendsStatusResponse, FAccelByteModelsGetOnlineUsersResponse, Response);

