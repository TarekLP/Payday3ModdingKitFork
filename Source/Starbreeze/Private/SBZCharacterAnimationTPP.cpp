#include "SBZCharacterAnimationTPP.h"

USBZCharacterAnimationTPP::USBZCharacterAnimationTPP() {
    this->bMoving = false;
    this->bInStartMovingState = false;
    this->bInMovingState = false;
    this->bInStopMovingState = false;
    this->bStopMovingStateUsesOrientationWarping = false;
    this->bInAir = false;
    this->bMeshInAir = false;
    this->bStartJumping = false;
    this->bJumping = false;
    this->bJumpingMoving = false;
    this->bTurning = false;
    this->bStartMoving = false;
    this->bStartMovingCrouch = false;
    this->bStartMovingHasATurn = false;
    this->bCrouching = false;
    this->bAccelerating = false;
    this->bSliding = false;
    this->bWasRunningBeforeStopTransition = false;
    this->bUseAimOffsetAllUpperBody = false;
    this->bUseCrouchIdleAimOffsetAllUpperBody = false;
    this->bReloading = false;
    this->bHasLeftFootForward = false;
    this->bActivateInertialization = false;
    this->bEnableLeaning = false;
    this->bEnableFootPlacement = false;
    this->bFullBodyAction = false;
    this->bIsInLinkedFullBodyAction = false;
    this->bLinkedFullBodyActionNodeIsPlaying = false;
    this->bAimOffsetHandledInFullBodyAction = false;
    this->bEnableFootLocking = false;
    this->bEnableHeadLeading = false;
    this->bEnableWeaponRotationOverride = false;
    this->bEnableFullBodyAimOffset = false;
    this->bEnableAimOffset = false;
    this->bEnableAimOffsetUpperBodyStand = false;
    this->bEnableAimOffsetHead = false;
    this->bEnableAimOffsetHeadLeading = false;
    this->bEnableAimOffsetUpperBodyCrouchIdle = false;
    this->bEnableAimOffsetUpperBodyCrouch = false;
    this->bEnableAimOffsetFullBody = false;
    this->bRightFootStop = false;
    this->bIsTraversing = false;
    this->bIsPlayingFullBodyAnimation = false;
    this->bIsAttached = false;
    this->bIsHumanShieldVictimGrabbed = false;
    this->bEnableHipsOffset = false;
    this->bEnableRootOffset = false;
    this->bStopAnimationFinished = false;
    this->bHasStopCrouchAnimations = false;
    this->bHasStopStandAnimations = false;
    this->bTransitFromPivotSwitchToNotMoving = false;
    this->bTransitFromPivotSwitchToMoving = false;
    this->bTransitFromNotMovingToMoving = false;
    this->bTransitFromMovingToNotMoving = false;
    this->bTransitFromStartMovingToMoving = false;
    this->bTransitFromStartMovingToNotMoving = false;
    this->bTransitFromNotMovingToStartMoving = false;
    this->bTransitFromMovingToStopMoving = false;
    this->bTransitFromStopMovingToMoving = false;
    this->bTransitFromStartMovingToStopMoving = false;
    this->bTransitFromStopMovingToStartMoving = false;
    this->bTransitFromStopMovingToNotMoving = false;
    this->bTransitFromUpperBodyIdleToMoving = false;
    this->bTransitFromUpperBodyMovingToIdle = false;
    this->bTransitFromTraverseToFall = false;
    this->bTransitFromFallToStand = false;
    this->bTransitFromFallToCrouch = false;
    this->bEnableUpperBodySyncGroup = false;
    this->bNewRendered = false;
    this->bEnableFacial = false;
    this->bEnableRigidBody = false;
    this->bStartHipsZBlending = false;
    this->CurrentDialogStartTime = 0.00f;
    this->LipSyncBlendWeight = 0.00f;
    this->FullBodyActionBlendTime = 0.25f;
    this->FullBodyBlendAlpha = 0.00f;
    this->AnimLODType = ESBZAnimLODType::Full;
    this->PoseType = ESBZPoseType::FullBody;
    this->StartMovingPoseType = ESBZPoseType::FullBody;
    this->AimOffsetType = ESBZAimOffsetType::UpperBody;
    this->CoveredDistSinceStartMoving = 0.00f;
    this->DistToPredictedStopLocation = 0.00f;
    this->StopPlayRate = 1.00f;
    this->SpeedWarpingScaling = 0.00f;
    this->SpeedWarpingAlpha = 0.00f;
    this->DiffYawBetweenCapsuleRotationAndDesiredVelocity = 0.00f;
    this->DiffYawBetweenMeshRotationAndVelocity = 0.00f;
    this->DiffYawBetweenRotationAndAim = 0.00f;
    this->AdditiveRotationYaw = 0.00f;
    this->DiffPitchBetweenRotationAndAim = 0.00f;
    this->FootRotationDeltaYaw = 0.00f;
    this->LeanXValue = 0.00f;
    this->LeanYValue = 0.00f;
    this->SpineAdjustmentAlpha = 0.00f;
    this->AnkleAdjustmentAlpha = 0.00f;
    this->Speed = 0.00f;
    this->SpeedAlpha = 0.00f;
    this->HumanShieldAngularSpeed = 0.00f;
    this->HSVictimRotateAroundAlpha = 0.00f;
    this->CoveredDistanceSinceStartJumping = 0.00f;
    this->StopMoveAngle = 0.00f;
    this->StopMoveGaitValue = 0.00f;
    this->StartMoveAngle = 0.00f;
    this->StartMoveGaitValue = 0.00f;
    this->StartMoveMovementDirection = ESBZMovementDirection::Forward;
    this->ActionUpperBodyLayeredBlendWeight = 0.00f;
    this->RootYawOffset = 0.00f;
    this->ViewYawOffset = 0.00f;
    this->TurnRemainingYaw = 0.00f;
    this->OrientationAngle = 0.00f;
    this->AlphaMovingOnGround = 0.00f;
    this->AlphaOnGround = 0.00f;
    this->AlphaSpeedWarping = 0.00f;
    this->AlphaSpeedWarpingMoving = 0.00f;
    this->FeetPositionX = 0.00f;
    this->FeetPositionY = 0.00f;
    this->AimingAlpha = 0.00f;
    this->BSWalkRunPlayRate = 1.00f;
    this->BSWalkRunGaitValue = 1.00f;
    this->BSWalkRunYaw = 1.00f;
    this->CrouchBlendingAlpha = 0.00f;
    this->CrouchBlendingAlphaOnlyLoco = 0.00f;
    this->UpperbodyAlpha = 0.00f;
    this->FixUpperbodyAlpha = 0.00f;
    this->HigherLowerBodyAlpha = 0.00f;
    this->AimOffsetMaxLODUpperbody = 3;
    this->AimOffsetMaxLODHead = 2;
    this->AimOffsetMaxLODHeadLeading = 2;
    this->AimOffsetMaxLODFullBody = 3;
    this->AimOffsetMaxLODUpperBodyCrouchIdle = 3;
    this->AimOffsetMaxLODUpperBodyCrouchMoving = 3;
    this->LeftHandAttachmentWorldRotationMode = BMM_Replace;
    this->RightHandAttachmentWorldRotationMode = BMM_Replace;
    this->LeftHandIKAlpha = 0.00f;
    this->LeftHandLocalIKAlpha = 0.00f;
    this->LeftHandWorldIKAlpha = 0.00f;
    this->RightHandWorldIKAlpha = 0.00f;
    this->RightHandLocalIKAlpha = 0.00f;
    this->RightHandIKAlpha = 0.00f;
    this->RightHandGripAlpha = 0.00f;
    this->LeftHandGripAlpha = 0.00f;
    this->HandIKRetargetingAlpha = 0.00f;
    this->CurrentTurnAnimationMontage = NULL;
    this->SubAnimationGraph = NULL;
    this->CurrentTurnAnimation = NULL;
    this->AnimationCollection = NULL;
    this->CurrentStanceTransitionMontage = NULL;
    this->CurrentCrouchTransitionMontage = NULL;
    this->StanceTransitionLFRFMontage = NULL;
    this->StanceTransitionRFLFMontage = NULL;
    this->CrouchTransitionMontage = NULL;
    this->UncrouchTransitionMontage = NULL;
    this->CrouchMoveTransitionMontage = NULL;
    this->UncrouchMoveTransitionMontage = NULL;
    this->CrouchMontage = NULL;
    this->UncrouchMontage = NULL;
    this->AimOffsetSliding = NULL;
    this->AimOffsetVaulting = NULL;
    this->AimOffsetMantling = NULL;
    this->AimOffsetZiplining = NULL;
    this->MoveStandBS = NULL;
    this->MoveCrouchBS = NULL;
    this->StartMoveStandTurnBS = NULL;
    this->StartMoveStandBS = NULL;
    this->StartMoveCrouchBS = NULL;
    this->StartMoveCrouchTurnBS = NULL;
    this->MovePivotSwitchBS = NULL;
    this->StopStandLFoot = NULL;
    this->StopStandRFoot = NULL;
    this->LeanBS = NULL;
    this->AimOffsetOnlyHeadBS = NULL;
    this->AimOffsetAllUpperBodyBS = NULL;
    this->AimOffsetAllUpperBodyCrouchedBS = NULL;
    this->AimOffsetAllUpperBodyCrouchedIdleBS = NULL;
    this->AimOffsetFullBody = NULL;
    this->UpperBodyUnequippedStdBS = NULL;
    this->UpperBodyUnequippedCrhBS = NULL;
    this->UpperBodyEquippedStdBS = NULL;
    this->UpperBodyEquippedCrhBS = NULL;
    this->UpperBodyEquippedReadyStdBS = NULL;
    this->UpperBodyEquippedReadyCrhBS = NULL;
    this->UpperBodyEquippedRelaxedStdBS = NULL;
    this->UpperBodyEquippedRelaxedCrhBS = NULL;
    this->UpperBodyEquippedUsingStdBS = NULL;
    this->UpperBodyEquippedUsingCrhBS = NULL;
    this->UpperBodyLeftHandEquippedStdBS = NULL;
    this->UpperBodyLeftHandEquippedCrhBS = NULL;
    this->UpperBodyLeftHandEquippedUsingStdBS = NULL;
    this->UpperBodyLeftHandEquippedUsingCrhBS = NULL;
    this->UpperBodyUnequippedIdleBS = NULL;
    this->UpperBodyEquippedIdleBS = NULL;
    this->UpperBodyEquippedReadyIdleBS = NULL;
    this->UpperBodyEquippedRelaxedIdleBS = NULL;
    this->UpperBodyEquippedUsingIdleBS = NULL;
    this->UpperBodyLeftHandEquippedIdleBS = NULL;
    this->UpperBodyLeftHandEquippedUsingIdleBS = NULL;
    this->VaultSlowStartBS = NULL;
    this->VaultFastStartBS = NULL;
    this->VaultExitTraverseBS = NULL;
    this->VaultLandBS = NULL;
    this->MantleSlowBS = NULL;
    this->MantleFastBS = NULL;
    this->Idle = NULL;
    this->IdleCrouch = NULL;
    this->StopCrouchLFoot = NULL;
    this->StopCrouchRFoot = NULL;
    this->JumpStart = NULL;
    this->JumpStartStatic = NULL;
    this->JumpStartMoving = NULL;
    this->Fall = NULL;
    this->HSVictimRotateAroundBS = NULL;
    this->EquippableLeftGripPose = NULL;
    this->EquippableRightGripPose = NULL;
    this->CurrentStopAnimation = NULL;
    this->CurrentBodyGestureMontage = NULL;
    this->CurrentTarget = NULL;
    this->CurrentFullBodyMontage = NULL;
}

