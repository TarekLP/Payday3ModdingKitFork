#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SBZDeveloperSettings.h"
#include "SBTutorialCharacterSetting.generated.h"

UCLASS(Blueprintable)
class USBTutorialCharacterSetting : public USBZDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid CharacterGuid;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CharacterSku;
    
    USBTutorialCharacterSetting();
    UFUNCTION(BlueprintPure)
    static FString GetTutorialPlayerSku();
    
    UFUNCTION(BlueprintPure)
    static FGuid GetTutorialPlayerGuid();
    
};

