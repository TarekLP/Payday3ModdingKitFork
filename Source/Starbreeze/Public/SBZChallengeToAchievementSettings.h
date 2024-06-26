#pragma once
#include "CoreMinimal.h"
#include "SBZDeveloperSettings.h"
#include "SBZChallengeToAchievementSettings.generated.h"

UCLASS(Blueprintable)
class USBZChallengeToAchievementSettings : public USBZDeveloperSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> ChallengeToAchievementMap;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AchievementObjectiveStatCodeArray;
    
    USBZChallengeToAchievementSettings();
    UFUNCTION(BlueprintPure)
    static TMap<FName, FName> GetChallengeToAchievementSettings();
    
    UFUNCTION(BlueprintPure)
    static TArray<FName> GetAchievementObjectiveStatCodeArray();
    
};

