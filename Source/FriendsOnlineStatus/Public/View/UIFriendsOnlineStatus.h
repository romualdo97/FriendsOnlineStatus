// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIFriendsOnlineStatus.generated.h"

// Forward declared
class UUIExpandableFriendsList;
class UUIFriendItemTooltip;
class UVerticalBox;

/**
 * Widget that handles a expandable list of online and offline players
 */
UCLASS()
class FRIENDSONLINESTATUS_API UUIFriendsOnlineStatus : public UUserWidget
{
	GENERATED_BODY()
public:
	void AddOnlinePlayer(UObject* InPlayerInfo);
	void AddOfflinePlayer(UObject* InPlayerInfo);
	void RemoveOnlinePlayer(UObject* InPlayerInfo);
	void RemoveOfflinePlayer(UObject* InPlayerInfo);
	void SetFriendItemTooltip(UUIFriendItemTooltip* InUserWidget);

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void HandleFriendItemIsHoveredChanged(UObject* ItemObject, bool bIsHovered, UUIExpandableFriendsList* ExpandableFriendsList);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = FriendsOnlineStatusSettings)
	TSubclassOf<UUIExpandableFriendsList> OnlineFriendsListClass;

	UPROPERTY(EditDefaultsOnly, Category = FriendsOnlineStatusSettings)
	TSubclassOf<UUIExpandableFriendsList> OfflineFriendsListClass;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* ListsContainer;

	UPROPERTY()
	UUIExpandableFriendsList* OnlineFriendsList;

	UPROPERTY()
	UUIExpandableFriendsList* OfflineFriendsList;

	UPROPERTY()
	UUIFriendItemTooltip* FriendItemTooltip;
};
