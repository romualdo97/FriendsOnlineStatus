// Fill out your copyright notice in the Description page of Project Settings.

#include "Model/PlayerInfo.h"
#include "View/UIFriendItem.h"
#include "Components/TextBlock.h"

void UUIFriendItem::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);

	const UPlayerInfo* FriendInfo = Cast<UPlayerInfo>(ListItemObject);
	check(FriendInfo != nullptr);

	UE_LOG(LogTemp, Warning, TEXT("Friend %s, LocalId %i"), *FriendInfo->GetNickname(), FriendInfo->GetLevel());
	NicknameLabel->SetText(FText::FromString(FriendInfo->GetNickname()));
	LevelValueLabel->SetText(FText::FromString(FString::Printf(TEXT("%i"), FriendInfo->GetLevel())));
}
