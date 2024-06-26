#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ESBZFireTokenType.h"
#include "SBZFirePermissionManager.generated.h"

class UObject;

UCLASS(Blueprintable, Deprecated, NotPlaceable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDEPRECATED_SBZFirePermissionManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<ESBZFireTokenType, int32> TokenLimits;
    
    UDEPRECATED_SBZFirePermissionManager();
protected:
    UFUNCTION()
    void OnTargetRemoved(UObject* Obj);
    
    UFUNCTION()
    void OnTargetAdded(UObject* Obj);
    
};

