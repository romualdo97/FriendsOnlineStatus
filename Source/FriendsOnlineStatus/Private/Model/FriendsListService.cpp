// Fill out your copyright notice in the Description page of Project Settings.


#include "Model/FriendsListService.h"

UFriendsListService::UFriendsListService()
{
	FriendList.Reset(new FFriendsListModel);
}

void UFriendsListService::LoadFriend(FPlayerInfo* NewPlayer) const
{
	FriendList->AllFriends.Add(TUniquePtr<FPlayerInfo>(NewPlayer));
}

uint32 UFriendsListService::GetLocalFriendIdByNickname(const FString& Nickname) const
{
	// TODO: Implement
	return 1;
}

void UFriendsListService::SetOnlineStatusById(const uint32 LocalFriendId, const bool bIsOnline) const
{
	if (FriendList->AllFriends.IsValidIndex(LocalFriendId))
	{
		FriendList->AllFriends[LocalFriendId]->bIsConnected = bIsOnline;
		bool Result = OnFriendStatusChanged.ExecuteIfBound(LocalFriendId);
	}
}

FPlayerInfo UFriendsListService::GetPlayerInfoById(const uint32 LocalFriendId) const
{
	if (FriendList->AllFriends.IsValidIndex(LocalFriendId))
	{
		// Returns a copy of the source data so the model is immutable
		return *FriendList->AllFriends[LocalFriendId];
	}

	// You shall no pass!!
	check(false);
	return FPlayerInfo();
}


