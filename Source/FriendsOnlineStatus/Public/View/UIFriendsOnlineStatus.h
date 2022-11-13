// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIFriendsOnlineStatus.generated.h"

// Forward declared
class UUIExpandableFriendsList;
class UVerticalBox;

/**
 * Widget that handles a expandable list of online and offline players
 */
UCLASS()
class FRIENDSONLINESTATUS_API UUIFriendsOnlineStatus : public UUserWidget
{
	GENERATED_BODY()
public:
	void AddOnlinePlayer(UObject* PlayerInfo);
	void AddOfflinePlayer(UObject* PlayerInfo);
	void RemoveOnlinePlayer(UObject* PlayerInfo);
	void RemoveOfflinePlayer(UObject* PlayerInfo);

protected:
	virtual void NativeConstruct() override;

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
};
