// Fill out your copyright notice in the Description page of Project Settings.


#include "Model/FriendsListService.h"
#include "Model/PlayerInfo.h"

UFriendsListService::UFriendsListService(const FObjectInitializer& ObjectInitializer)
{
	FriendList = NewObject<UFriendsListModel>();
}

void UFriendsListService::StartService()
{
	// TODO: Start fetching data
}

void UFriendsListService::LoadFriend(UPlayerInfo* NewPlayer) const
{
	// NOTE: Loading new friends may invalidate the localId of the players
	// so this is only intended to be called when loading the friend list
	// and should be recalled if the list gets modified
	FriendList->AddFriend(NewPlayer);
}

void UFriendsListService::SetOnlineStatusById(const uint32 LocalFriendId, const bool bIsOnline) const
{
	UPlayerInfo* PlayerInfo = GetPlayerInfoById(LocalFriendId);
	check(PlayerInfo != nullptr);

	FriendList->SetOnlineStatus(PlayerInfo, bIsOnline);
	bool Result = OnFriendStatusChanged.ExecuteIfBound(LocalFriendId);
}

UPlayerInfo* UFriendsListService::GetPlayerInfoById(const uint32 LocalFriendId) const
{
	if (FriendList->GetAllFriends().IsValidIndex(LocalFriendId))
	{
		// Returns a copy of the source data to make the model immutable
		return FriendList->GetAllFriends()[LocalFriendId];
	}

	// You shall no pass!!
	check(false);
	return nullptr;
}

const TArray<UPlayerInfo*>& UFriendsListService::GetFriends() const
{
	return FriendList->GetAllFriends();
}


