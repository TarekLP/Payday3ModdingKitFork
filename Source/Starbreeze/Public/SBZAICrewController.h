#pragma once
#include "CoreMinimal.h"
#include "SBZAIController.h"
#include "SBZAICrewController.generated.h"

class AActor;
class ASBZAICrewState;
class ASBZRoomVolume;

UCLASS(Blueprintable)
class ASBZAICrewController : public ASBZAIController {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CrewState, meta=(AllowPrivateAccess=true))
    ASBZAICrewState* CrewState;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    float CustodyDurationArray[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ASBZRoomVolume* LastWardRoom;
    
public:
    ASBZAICrewController();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
private:
    UFUNCTION()
    void OnRep_CrewState();
    
    UFUNCTION()
    void OnCrewStateDestroyed(AActor* DestroyedActor);
    
};

