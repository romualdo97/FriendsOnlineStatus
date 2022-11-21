// Fill out your copyright notice in the Description page of Project Settings.


#include "View/UIFriendItemTooltip.h"
#include "Components/TextBlock.h"
#include "Model/PlayerInfo.h"

void UUIFriendItemTooltip::UpdateTooltipContent(const UPlayerInfo* PlayerInfo) const
{
	check(PlayerInfo != nullptr);
	
	const TCHAR& FirstLetter = PlayerInfo->GetNickname()[0];
	BigLetterLabel->SetText(FText::FromString(FString::Printf(TEXT("%c"), FirstLetter)));
	NicknameLabel->SetText(FText::FromString(PlayerInfo->GetNickname()));
	LevelValueLabel->SetText(FText::FromString(PlayerInfo->GetLevelAsNiceString()));
}
