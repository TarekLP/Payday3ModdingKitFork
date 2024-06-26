#pragma once
#include "CoreMinimal.h"
#include "SBZItemDatabase.h"
#include "SBZSkillLineDatabase.generated.h"

class USBZSkillLineData;

UCLASS(Blueprintable)
class USBZSkillLineDatabase : public USBZItemDatabase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USBZSkillLineData*> SkillLineArray;
    
    USBZSkillLineDatabase();
};

