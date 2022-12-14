// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/FriendsListController.h"
#include "Controller/Interfaces/FriendWidgetsProvider.h"
#include "Model/FriendsListService.h"
#include "Model/PlayerInfo.h"
#include "View/UIFriendsOnlineStatus.h"
#include "View/UIToast.h"
#include "Blueprint/UserWidget.h"
#include "Components/ListView.h"
#include "Kismet/GameplayStatics.h"

void UFriendsListController::SetupController(IFriendWidgetsProvider* InWidgetsProvider, UFriendsListService* InFriendsListData)
{
	check(InWidgetsProvider->GetWidgetOwner() != nullptr);
	check(InWidgetsProvider->GetFriendsOnlineStatusWidgetClass() != nullptr);
	check(InWidgetsProvider->GetFriendItemTooltip() != nullptr);
	check(InWidgetsProvider->GetToast() != nullptr);
	check(InFriendsListData != nullptr);

	// Set the widgets provider and data service
	WidgetsProvider = InWidgetsProvider;
	FriendsListData = InFriendsListData;

	// Instance the main widget
	FriendsOnlineStatusWidget = CreateWidget<UUIFriendsOnlineStatus>(
		InWidgetsProvider->GetWidgetOwner(),
		InWidgetsProvider->GetFriendsOnlineStatusWidgetClass());

	// Set tooltip of the friend items
	FriendsOnlineStatusWidget->SetFriendItemTooltip(InWidgetsProvider->GetFriendItemTooltip());
}

void UFriendsListController::Enable()
{
	check(FriendsOnlineStatusWidget != nullptr);
	FriendsOnlineStatusWidget->AddToViewport(0);

	check(WidgetsProvider != nullptr);
	check(WidgetsProvider->GetToast() != nullptr)
	WidgetsProvider->GetToast()->AddToViewport(1);
	
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
	check(FriendsOnlineStatusWidget != nullptr);
	FriendsOnlineStatusWidget->RemoveFromParent();
	
	check(WidgetsProvider != nullptr);
	check(WidgetsProvider->GetToast() != nullptr)
	WidgetsProvider->GetToast()->RemoveFromParent();
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
	
	check(WidgetsProvider != nullptr);
	check(WidgetsProvider->GetToast() != nullptr)
	if (ChangedPlayer->IsConnected())
	{
		// If changed from offline to online...
		FriendsOnlineStatusWidget->RemoveOfflinePlayer(ChangedPlayer);
		FriendsOnlineStatusWidget->AddOnlinePlayer(ChangedPlayer);

		// Show connected message
		WidgetsProvider->GetToast()->Show(FText::FromString(
			FString::Printf(TEXT("%s connected!"),
			*ChangedPlayer->GetNickname())));
	}
	else
	{
		// If changed from online to offline
		FriendsOnlineStatusWidget->RemoveOnlinePlayer(ChangedPlayer);
		FriendsOnlineStatusWidget->AddOfflinePlayer(ChangedPlayer);

		// Show disconnected message
		WidgetsProvider->GetToast()->Show(FText::FromString(
			FString::Printf(TEXT("%s disconnected!"),
			*ChangedPlayer->GetNickname())));
	}
}
