#pragma once
#include "CoreMinimal.h"
#include "AccelByteModelsPredefinedEvent.h"
#include "AccelByteModelsPlayerRecordCreatedPayload.generated.h"

USTRUCT(BlueprintType)
struct ACCELBYTEUE4SDK_API FAccelByteModelsPlayerRecordCreatedPayload : public FAccelByteModelsPredefinedEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Key;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UserId;
    
    FAccelByteModelsPlayerRecordCreatedPayload();
};

