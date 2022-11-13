// Fill out your copyright notice in the Description page of Project Settings.


#include "View/UIFriendsOnlineStatus.h"
#include "View/UIExpandableFriendsList.h"
#include "Components/VerticalBox.h"

void UUIFriendsOnlineStatus::NativeConstruct()
{
	Super::NativeConstruct();
	
	check(OnlineFriendsListClass != nullptr);
	check(OfflineFriendsListClass != nullptr);
	OnlineFriendsList = CreateWidget<UUIExpandableFriendsList>(this, OnlineFriendsListClass);
	OfflineFriendsList = CreateWidget<UUIExpandableFriendsList>(this, OfflineFriendsListClass);
	OnlineFriendsList->Name = "Online";
	OfflineFriendsList->Name = "Offline";

	ListsContainer->AddChild(OnlineFriendsList);
	ListsContainer->AddChild(OfflineFriendsList);
}

void UUIFriendsOnlineStatus::AddOnlinePlayer(UObject* PlayerInfo)
{
	OnlineFriendsList->AddItem(PlayerInfo);
}

void UUIFriendsOnlineStatus::AddOfflinePlayer(UObject* PlayerInfo)
{
	OfflineFriendsList->AddItem(PlayerInfo);
}

void UUIFriendsOnlineStatus::RemoveOnlinePlayer(UObject* PlayerInfo)
{
	OnlineFriendsList->RemoveItem(PlayerInfo);

}

void UUIFriendsOnlineStatus::RemoveOfflinePlayer(UObject* PlayerInfo)
{
	OfflineFriendsList->RemoveItem(PlayerInfo);
}
