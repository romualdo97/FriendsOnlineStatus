// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIFriendItemTooltip.generated.h"

// Forward declared
class UTextBlock;
class UPlayerInfo;

/**
 *  Handles the friend item tooltip
 */
UCLASS()
class FRIENDSONLINESTATUS_API UUIFriendItemTooltip : public UUserWidget
{
	GENERATED_BODY()

public:
	void UpdateTooltipContent(const UPlayerInfo* PlayerInfo) const;
	
private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* BigLetterLabel;
	
	UPROPERTY(meta = (BindWidget))
	UTextBlock* NicknameLabel;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* LevelValueLabel;
};
