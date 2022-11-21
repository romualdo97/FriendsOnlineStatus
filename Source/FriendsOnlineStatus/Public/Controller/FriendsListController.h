// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "View/UIFriendsOnlineStatus.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "FriendsListController.generated.h"

// Forward declared
class UPlayerInfo;
class UFriendsListService;
class UUIFriendsList;
class IFriendWidgetsProvider;

/**
 * Bounds the FriendListWidget with the FriendListModel, i.e. Widget <-> Controller <- Model
 */
UCLASS()
class FRIENDSONLINESTATUS_API UFriendsListController : public UObject
{
	GENERATED_BODY()

public:
	// Binds the controller to a widget and its data source
	void SetupController(const IFriendWidgetsProvider* WidgetsProvider, UFriendsListService* InFriendsListData);

	// Enable view
	void Enable();

	// Disable view
	void Disable();

private:
	void InitializeFriendsLists();

	UFUNCTION()
	void HandleFriendStatusChange(UPlayerInfo* ChangedPlayer);

private:
	bool bIsInitialized{ false };

	UPROPERTY()
	UFriendsListService* FriendsListData;
	
	UPROPERTY()
	UUIFriendsOnlineStatus* FriendsOnlineStatusWidget;
};
