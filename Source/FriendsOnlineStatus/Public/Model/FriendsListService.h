// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Model/FriendsListModel.h"
#include "FriendsListService.generated.h"

DECLARE_DELEGATE_RetVal_OneParam(bool /*Should load more?*/, FLoaderFunctionDelegate, FPlayerInfo&/*InOut Initialize the data*/);
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFriendStatusChanged, uint32, LocalFriendId);

/**
 * Holds and mutates the "friends" data while emitting data changes. 
 */
UCLASS()
class FRIENDSONLINESTATUS_API UFriendsListService : public UObject
{
	GENERATED_BODY()

public:
	// Default constructor
	UFriendsListService();

	// Load initial data
	void LoadFriend(FPlayerInfo* NewPlayer) const;

	// Set the online status of specific local friend id
	void SetOnlineStatusById(const uint32 LocalFriendId, const bool bIsOnline) const;

	// Given a nickname returns the local friend id
	uint32 GetLocalFriendIdByNickname(const FString& Nickname) const;

	// Get a player info copy
	FPlayerInfo GetPlayerInfoById(const uint32 LocalFriendId) const;

	// Dynamic delegate called when the online status of a player changes
	FOnFriendStatusChanged OnFriendStatusChanged;

private:
	// The friend list
	TUniquePtr<FFriendsListModel> FriendList;
};
