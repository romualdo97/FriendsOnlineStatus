// Fill out your copyright notice in the Description page of Project Settings.


#include "Model/FriendsListService.h"
#include "Model/PlayerInfo.h"
#include "Kismet/KismetSystemLibrary.h"

UFriendsListService::UFriendsListService(const FObjectInitializer& ObjectInitializer)
{
	FriendList = NewObject<UFriendsListModel>();
}

void UFriendsListService::StartService(UWorld* InWorld)
{
	check(InWorld != nullptr);
	World = InWorld;
	LoadMockedData();
	DoFakeSync();
}

const TArray<UPlayerInfo*>& UFriendsListService::GetFriends() const
{
	return FriendList->GetAllFriends();
}

void UFriendsListService::LoadMockedData() const
{
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Jay Roe",
		1,
		true
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Foo Ville",
		2,
		false
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Pou Stomp",
		7,
		true
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Zizu Valdivia",
		4,
		true
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Luis Diaz",
		15,
		false
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Andrea Virotelli",
		12,
		false
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Giaccomo Stompson",
		12,
		false
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Pluto Johnson",
		12,
		false
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Pirotecnio Star",
		12,
		false
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Captain RJ",
		12,
		false
	));
	FriendList->AddFriend(UPlayerInfo::CreatePlayerInfo(
		"Commander JR",
		12,
		false
	));
}

void UFriendsListService::UpdateRandomPlayerStatus()
{
	if (SyncCount > 0)
	{
		const TArray<UPlayerInfo*>& AllFriends = FriendList->GetAllFriends();
		UPlayerInfo* Friend = AllFriends[FMath::RandRange(0, AllFriends.Num() - 1)];
		FriendList->SetOnlineStatus(Friend, !Friend->IsConnected());
		OnFriendStatusChanged.ExecuteIfBound(Friend);
	}
	++SyncCount;
}

void UFriendsListService::DoFakeSync()
{
	check(World != nullptr);

	World->GetTimerManager().SetTimer(TimerHandle, this, &UFriendsListService::DoFakeSync, FMath::RandRange(0.5f, 5.0f), true);
	
	UpdateRandomPlayerStatus();
}

