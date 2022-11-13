// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FriendsOnlineStatusGameInstance.generated.h"

// Forward declared
class UFriendsListService;
class UFriendsListController;

/**
 * The main game instance... here we will populate the data and initialize controllers
 */
UCLASS()
class FRIENDSONLINESTATUS_API UFriendsOnlineStatusGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFriendsOnlineStatusGameInstance();
	virtual void Init() override;

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

private:
	void LoadMockedFriendData() const;

private:
	UPROPERTY()
	UFriendsListService* FriendListData;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> FriendListWidgetClass;

	UPROPERTY()
	UFriendsListController* FriendListController;
};
