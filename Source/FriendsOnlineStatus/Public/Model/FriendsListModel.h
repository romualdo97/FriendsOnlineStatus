// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FriendsListModel.generated.h"

// Forward declared
class UPlayerInfo;

/**
 * Holds info of the player friends.
 */
UCLASS()
class FRIENDSONLINESTATUS_API UFriendsListModel : public UObject
{
	GENERATED_BODY()
		
public:
	using FFriendsListType = TArray<UPlayerInfo*>;

	// Get all friends
	const FFriendsListType& GetAllFriends() const { return AllFriends; }

	// These methods can modify the model
	static void SetOnlineStatus(UPlayerInfo* PlayerInfo, bool IsConnected);
	void AddFriend(UPlayerInfo* FriendInfo);
	void ClearFriends();

private:
	FFriendsListType AllFriends;
};
