// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/FriendsListController.h"
#include "Model/FriendsListService.h"
#include "Model/PlayerInfo.h"
#include "View/UIFriendsOnlineStatus.h"
#include "View/UIExpandableFriendsList.h"
#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"

void UFriendsListController::Enable()
{
	check(FriendsOnlineStatusWidget != nullptr);
	FriendsOnlineStatusWidget->AddToViewport(0);

	const UWorld* World = FriendsOnlineStatusWidget->GetWorld();
	check(World != nullptr);
	
	APlayerController* PlayerController = World->GetFirstPlayerController();
	check(PlayerController != nullptr);

	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(FriendsOnlineStatusWidget->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = true;

	InitializeFriendsLists();
}

void UFriendsListController::Disable()
{
	FriendsOnlineStatusWidget->RemoveFromViewport();
}

void UFriendsListController::InitializeFriendsLists()
{
	if (bIsInitialized) return;
	check(FriendsListData != nullptr);
	check(FriendsOnlineStatusWidget != nullptr);

	for (UPlayerInfo* Friend : FriendsListData->GetFriends())
	{
		if (Friend->IsConnected())
		{
			FriendsOnlineStatusWidget->AddOnlinePlayer(Friend);
		}
		else
		{
			FriendsOnlineStatusWidget->AddOfflinePlayer(Friend);
		}
	}

	FriendsListData->OnFriendStatusChanged.BindDynamic(this, &UFriendsListController::HandleFriendStatusChange);

	bIsInitialized = true;
}

void UFriendsListController::HandleFriendStatusChange(UPlayerInfo* ChangedPlayer)
{
	if (ChangedPlayer->IsConnected())
	{
		// If changed from offline to online...
		FriendsOnlineStatusWidget->RemoveOfflinePlayer(ChangedPlayer);
		FriendsOnlineStatusWidget->AddOnlinePlayer(ChangedPlayer);
	}
	else
	{
		// If changed from online to offline
		FriendsOnlineStatusWidget->RemoveOnlinePlayer(ChangedPlayer);
		FriendsOnlineStatusWidget->AddOfflinePlayer(ChangedPlayer);
	}
}
