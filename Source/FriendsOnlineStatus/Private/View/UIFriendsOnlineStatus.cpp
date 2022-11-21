// Fill out your copyright notice in the Description page of Project Settings.


#include "View/UIFriendsOnlineStatus.h"
#include "View/UIExpandableFriendsList.h"
#include "View/UIFriendItemTooltip.h"
#include "View/UIFriendItem.h"
#include "Components/VerticalBox.h"
#include "Components/ListView.h"
#include "Model/PlayerInfo.h"

void UUIFriendsOnlineStatus::NativeConstruct()
{
	Super::NativeConstruct();
	
	check(OnlineFriendsListClass != nullptr);
	check(OfflineFriendsListClass != nullptr);
	OnlineFriendsList = CreateWidget<UUIExpandableFriendsList>(this, OnlineFriendsListClass);
	OfflineFriendsList = CreateWidget<UUIExpandableFriendsList>(this, OfflineFriendsListClass);

	ListsContainer->AddChild(OnlineFriendsList);
	ListsContainer->AddChild(OfflineFriendsList);

	// Add expandable list as payload data
	OnlineFriendsList->GetListView()->OnItemIsHoveredChanged().AddUObject<UUIFriendsOnlineStatus, UUIExpandableFriendsList*>(this, &UUIFriendsOnlineStatus::HandleFriendItemIsHoveredChanged, OnlineFriendsList);
	OfflineFriendsList->GetListView()->OnItemIsHoveredChanged().AddUObject<UUIFriendsOnlineStatus, UUIExpandableFriendsList*>(this, &UUIFriendsOnlineStatus::HandleFriendItemIsHoveredChanged, OfflineFriendsList);
}

void UUIFriendsOnlineStatus::AddOnlinePlayer(UObject* InPlayerInfo)
{
	OnlineFriendsList->AddItem(InPlayerInfo);
}

void UUIFriendsOnlineStatus::AddOfflinePlayer(UObject* InPlayerInfo)
{
	OfflineFriendsList->AddItem(InPlayerInfo);
}

void UUIFriendsOnlineStatus::RemoveOnlinePlayer(UObject* InPlayerInfo)
{
	OnlineFriendsList->RemoveItem(InPlayerInfo);

}

void UUIFriendsOnlineStatus::RemoveOfflinePlayer(UObject* InPlayerInfo)
{
	OfflineFriendsList->RemoveItem(InPlayerInfo);
}

void UUIFriendsOnlineStatus::SetFriendItemTooltip(UUIFriendItemTooltip* InUserWidget)
{
	FriendItemTooltip = InUserWidget;
}

void UUIFriendsOnlineStatus::HandleFriendItemIsHoveredChanged(UObject* ItemObject, bool bIsHovered, UUIExpandableFriendsList* ExpandableFriendsList)
{
	// Only handle if responding to hover
	if (!bIsHovered) return;
	check(FriendItemTooltip != nullptr);

	const UPlayerInfo* FriendInfo = Cast<UPlayerInfo>(ItemObject);
	check(FriendInfo != nullptr);
	
	// Update friend tooltip content (there's only one instance of this widget)
	FriendItemTooltip->UpdateTooltipContent(FriendInfo);

	// Set the friend item tooltip
	UUIFriendItem* FriendItemWidget = ExpandableFriendsList->GetListView()->GetEntryWidgetFromItem<UUIFriendItem>(FriendInfo);
	check(FriendItemWidget != nullptr);
	FriendItemWidget->SetToolTip(FriendItemTooltip);
}
