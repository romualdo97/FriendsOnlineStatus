// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Model/FriendsListModel.h"
#include "FriendsListService.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnFriendStatusChanged, UPlayerInfo*, ChangedPlayer);

/**
 * Holds and mutates the "friends" data (so it keeps sync with remote) while emitting data changes.
 */
UCLASS()
class FRIENDSONLINESTATUS_API UFriendsListService : public UObject
{
	GENERATED_BODY()

public:
	// Default constructor
	UFriendsListService(const FObjectInitializer& ObjectInitializer);

	// Start fetching data from remote
	void StartService(UWorld* InWorld);

	// Array listing all the friends
	const TArray<UPlayerInfo*>& GetFriends() const;

private:
	// Load initial data
	void LoadMockedData() const;

	// Update the connection status
	void UpdateRandomPlayerStatus();

	// Do a fake player status sync
	UFUNCTION()
	void DoFakeSync();

public:
	// Dynamic delegate called when the online status of a player changes
	FOnFriendStatusChanged OnFriendStatusChanged;
	
private:
	// The friend list
	UPROPERTY()
	UFriendsListModel* FriendList;

	UPROPERTY()
	UWorld* World;

	UPROPERTY()
	FTimerHandle TimerHandle; // Used to mimic user connection/disconnection

	uint32 SyncCount{ 0 };
};
