// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/FriendsOnlineStatusGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "Controller/FriendsListController.h"
#include "Model/FriendsListService.h"
#include "View/UIFriendItemTooltip.h"

UFriendsOnlineStatusGameInstance::UFriendsOnlineStatusGameInstance()
{
	UE_LOG(LogTemp, Warning, TEXT("Created my gameinstance"));
}

void UFriendsOnlineStatusGameInstance::Init()
{
	Super::Init();

	// Create the FriendItem tooltip instance (Will be shared)
	check(FriendItemTooltipWidgetClass != nullptr);
	FriendItemTooltipWidget = CreateWidget<UUIFriendItemTooltip>(this, FriendItemTooltipWidgetClass);
	check(FriendItemTooltipWidget != nullptr);
	
	// Create the data object
	FriendListData = NewObject<UFriendsListService>();
	FriendListData->StartService(GetWorld());
	
	// Inject data and view object into the controller
	FriendListController = NewObject<UFriendsListController>();
	FriendListController->SetupController(this, FriendListData);
}

void UFriendsOnlineStatusGameInstance::LoadMenu()
{	
	// Called from level blueprint when BeginPlay
	FriendListController->Enable();
}

UGameInstance* UFriendsOnlineStatusGameInstance::GetWidgetOwner() const
{
	return Cast<UGameInstance>(const_cast<UFriendsOnlineStatusGameInstance*>(this));
}

TSubclassOf<UUIFriendsOnlineStatus> UFriendsOnlineStatusGameInstance::GetFriendsOnlineStatusWidgetClass() const
{
	return FriendListWidgetClass;
}

UUIFriendItemTooltip* UFriendsOnlineStatusGameInstance::GetFriendItemTooltip() const
{
	return FriendItemTooltipWidget;
}
