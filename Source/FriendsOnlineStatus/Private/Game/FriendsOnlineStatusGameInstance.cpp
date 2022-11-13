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
	FriendListData->StartService(GetWorld());
	
	// Inject data and view object into the controller
	FriendListController = NewObject<UFriendsListController>();
	FriendListController->SetupController(this, FriendListWidgetClass, FriendListData);
}

void UFriendsOnlineStatusGameInstance::LoadMenu()
{
	// Called from level blueprint when BeginPlay
	FriendListController->Enable();
}