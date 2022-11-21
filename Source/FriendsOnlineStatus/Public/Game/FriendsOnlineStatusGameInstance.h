// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controller/Interfaces/FriendWidgetsProvider.h"
#include "Engine/GameInstance.h"
#include "FriendsOnlineStatusGameInstance.generated.h"

// Forward declared
class UFriendsListService;
class UFriendsListController;
class UUIFriendsOnlineStatus;
class UUIFriendItemTooltip;

/**
 * The main game instance... here we will populate the data and initialize controllers
 */
UCLASS()
class FRIENDSONLINESTATUS_API UFriendsOnlineStatusGameInstance : public UGameInstance, public IFriendWidgetsProvider
{
	GENERATED_BODY()

public:
	UFriendsOnlineStatusGameInstance();
	virtual void Init() override;

	// Start IFriendWidgetsProvider
	virtual UGameInstance* GetWidgetOwner() const override;
	virtual TSubclassOf<UUIFriendsOnlineStatus> GetFriendsOnlineStatusWidgetClass() const override;
	virtual UUIFriendItemTooltip* GetFriendItemTooltip() const override;
	// End IFriendWidgetsProvider
	
	UFUNCTION(BlueprintCallable)
	void LoadMenu();

private:
	UPROPERTY(EditDefaultsOnly, Category=FriendsListWidgets)
	TSubclassOf<UUIFriendsOnlineStatus> FriendListWidgetClass;
	
	UPROPERTY(EditDefaultsOnly, Category=FriendsListWidgets)
	TSubclassOf<UUIFriendItemTooltip> FriendItemTooltipWidgetClass;
	
	UPROPERTY()
	UUIFriendItemTooltip* FriendItemTooltipWidget;
	
	UPROPERTY()
	UFriendsListService* FriendListData;

	UPROPERTY()
	UFriendsListController* FriendListController;
};
