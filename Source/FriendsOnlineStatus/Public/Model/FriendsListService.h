// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Model/FriendsListModel.h"
#include "FriendsListService.generated.h"

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
	UFriendsListService(const FObjectInitializer& ObjectInitializer);

	// Load initial data
	void LoadFriend(UPlayerInfo* NewPlayer) const;

	// Set the online status of specific local friend id
	void SetOnlineStatusById(const uint32 LocalFriendId, const bool bIsOnline) const;
	
	// Get player info
	UPlayerInfo* GetPlayerInfoById(const uint32 LocalFriendId) const;

	// Dynamic delegate called when the online status of a player changes
	FOnFriendStatusChanged OnFriendStatusChanged;

	// Constant begin iterator
	UFriendsListModel::FFriendsListType::RangedForIteratorType begin();

	// Constant end iterator
	UFriendsListModel::FFriendsListType::RangedForIteratorType end();

private:

	// The friend list
	UPROPERTY()
	UFriendsListModel* FriendList;
};
