// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimInstance/CharacterAnimInstanc.h"
#include "Expeditionist/ExpeditionistCharacter.h"
#include "Components/CustomMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCharacterAnimInstanc::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	ExpeditionistCharacter = Cast<AExpeditionistCharacter>(TryGetPawnOwner());
	if (ExpeditionistCharacter)
	{
		CustomMovementComponent= ExpeditionistCharacter->GetCustomMovementComponent();
	}
}

void UCharacterAnimInstanc::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if(!ExpeditionistCharacter || !CustomMovementComponent) return;
	GetGroundSpeed();
	GetAirSpeed();
	GetShouldMove();
	GetIsFalling();
	GetIsClimbing();
}

void UCharacterAnimInstanc::GetGroundSpeed()
{
	GroundSpeed = UKismetMathLibrary::VSizeXY(ExpeditionistCharacter->GetVelocity());
	
}

void UCharacterAnimInstanc::GetAirSpeed()
{
	AirSpeed= ExpeditionistCharacter->GetVelocity().Z;
}

void UCharacterAnimInstanc::GetShouldMove()
{
	bShouldMove=
	CustomMovementComponent->GetCurrentAcceleration().Size()>0&&
	GroundSpeed > 5.f &&
	!bIsFalling;
}

void UCharacterAnimInstanc::GetIsFalling()
{
	bIsFalling= CustomMovementComponent->IsFalling();
}

void UCharacterAnimInstanc::GetIsClimbing()
{
	bIsClimbing = CustomMovementComponent->IsClimbing();
}
