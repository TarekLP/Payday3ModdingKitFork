#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SBZSpawnCloset.generated.h"

class APD3PawnSpawnGroup;
class ASBZAICharacter;
class ASBZRoomVolume;

UCLASS(Blueprintable, MinimalAPI)
class ASBZSpawnCloset : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<ASBZRoomVolume> ClosetVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APD3PawnSpawnGroup*> SpawnGroupsInCloset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AActor*> Reactors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStayOpenDuringStealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ReactionDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 NumberOfBlockingActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bActorsInVolume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bIsStealth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ASBZAICharacter*> CiviliansInVolume;
    
public:
    ASBZSpawnCloset();
protected:
    UFUNCTION()
    void OnRoomVolumeEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION()
    void OnRoomVolumeBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
    
    UFUNCTION()
    void OnHeistGoneLoud();
    
    UFUNCTION()
    void BindRoomVolumeOverlaps();
    
};

