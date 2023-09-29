// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterAnimInstanc.generated.h"

class AExpeditionistCharacter;
class UCustomMovementComponent;
/**
 * 
 */
UCLASS()
class EXPEDITIONIST_API UCharacterAnimInstanc : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY()
	AExpeditionistCharacter* ExpeditionistCharacter;

	UPROPERTY()
	UCustomMovementComponent* CustomMovementComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Reference", meta = (AllowPrivateAccess = "true"))
	float GroundSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Reference", meta= (AllowPrivateAccess = "true"))
	float AirSpeed;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Reference", meta= (AllowPrivateAccess = "true"))
	bool bShouldMove;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Reference", meta= (AllowPrivateAccess = "true"))
	bool bIsFalling;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Reference", meta= (AllowPrivateAccess = "true"))
	bool bIsClimbing;
	
	void GetGroundSpeed();
	void GetAirSpeed();
	void GetShouldMove();
	void GetIsFalling();
	void GetIsClimbing();
};
