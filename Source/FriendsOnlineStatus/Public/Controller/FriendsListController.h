// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "FriendsListController.generated.h"

// Forward declared
class UFriendsListService;
class UFriendsListWidget;

/**
 * Bounds the FriendListWidget with the FriendListModel, i.e. Widget <-> Controller <- Model
 */
UCLASS()
class FRIENDSONLINESTATUS_API UFriendsListController : public UObject
{
	GENERATED_BODY()

public:
	// Binds the controller to a widget and its data source
	template<class WidgetOwnerT>
	void SetupController(WidgetOwnerT* InWidgetOwner, const TSubclassOf<UUserWidget>& InFriendListWidgetClass, UFriendsListService* InFriendsListData)
	{
		check(InWidgetOwner != nullptr);
		check(InFriendListWidgetClass != nullptr);
		check(InFriendsListData != nullptr);
		FriendListWidget = CreateWidget(InWidgetOwner, InFriendListWidgetClass);
		FriendsListData = InFriendsListData;
	}

	// Enable view
	void Enable() const;

	// Disable view
	void Disable() const;

private:
	UPROPERTY()
	UFriendsListService* FriendsListData;
	
	UPROPERTY()
	UUserWidget* FriendListWidget;
};
