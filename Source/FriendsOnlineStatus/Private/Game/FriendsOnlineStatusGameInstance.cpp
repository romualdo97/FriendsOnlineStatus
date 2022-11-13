// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/FriendsOnlineStatusGameInstance.h"

#include "Blueprint/UserWidget.h"
#include "Controller/FriendsListController.h"
#include "Model/FriendsListService.h"
#include "Model/PlayerInfo.h"

UFriendsOnlineStatusGameInstance::UFriendsOnlineStatusGameInstance()
{
	UE_LOG(LogTemp, Warning, TEXT("Created my gameinstance"));
}

void UFriendsOnlineStatusGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("Init my gameinstance"));

	// Create the data object
	FriendListData = NewObject<UFriendsListService>();
	FriendListData->StartService();
	LoadMockedFriendData();
	
	// Inject data and view object into the controller
	FriendListController = NewObject<UFriendsListController>();
	FriendListController->SetupController(this, FriendListWidgetClass, FriendListData);
}

void UFriendsOnlineStatusGameInstance::LoadMenu()
{
	// Called from level blueprint when BeginPlay
	FriendListController->Enable();
}

void UFriendsOnlineStatusGameInstance::LoadMockedFriendData() const
{
	check(FriendListData != nullptr);

	// NOTE: This could be handled better from a loader class or sync class
	// whose only responsibility is to keep model data sync with remote data
	// a subclass of this hypothetical class could simply load the data from a JSON file
	// and perform mocked state updates on the data for testing
	FriendListData->LoadFriend(UPlayerInfo::CreatePlayerInfo(
		"Jay Roe",
		10,
		false
	));
	FriendListData->LoadFriend(UPlayerInfo::CreatePlayerInfo(
		"Foo Ville",
		2,
		true
	));
	FriendListData->LoadFriend(UPlayerInfo::CreatePlayerInfo(
		"Pou Stomp",
		7,
		true
	));
	FriendListData->LoadFriend(UPlayerInfo::CreatePlayerInfo(
		"Zizu Valdivia",
		4,
		true
	));
	FriendListData->LoadFriend(UPlayerInfo::CreatePlayerInfo(
		"Luis Diaz",
		15,
		false
	));
	FriendListData->LoadFriend(UPlayerInfo::CreatePlayerInfo(
		"Andrea Virotelli",
		12,
		false
	));
	FriendListData->LoadFriend(UPlayerInfo::CreatePlayerInfo(
		"Giaccomo Stompson",
		12,
		false
	));
}
