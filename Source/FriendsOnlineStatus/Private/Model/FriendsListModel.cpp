// Fill out your copyright notice in the Description page of Project Settings.


#include "Model/FriendsListModel.h"

#include "Model/PlayerInfo.h"

void UFriendsListModel::AddFriend(UPlayerInfo* FriendInfo)
{
	AllFriends.Add(FriendInfo);
}

void UFriendsListModel::SetOnlineStatus(UPlayerInfo* PlayerInfo, bool IsConnected)
{
	PlayerInfo->bIsConnected = IsConnected;
}

void UFriendsListModel::ClearFriends()
{
	AllFriends.Reset();
}
