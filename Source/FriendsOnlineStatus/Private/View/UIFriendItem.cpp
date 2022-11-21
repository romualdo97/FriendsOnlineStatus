// Fill out your copyright notice in the Description page of Project Settings.

#include "View/UIFriendItem.h"


#include "SPinValueInspector.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Model/PlayerInfo.h"
#include "View/UIFriendItemTooltip.h"

void UUIFriendItem::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	const UPlayerInfo* FriendInfo = Cast<UPlayerInfo>(ListItemObject);
	check(FriendInfo != nullptr);

	NicknameLabel->SetText(FText::FromString(FriendInfo->GetNickname()));
	LevelValueLabel->SetText(FText::FromString(FriendInfo->GetLevelAsNiceString()));
}
