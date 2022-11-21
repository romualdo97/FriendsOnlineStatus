// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FriendWidgetsProvider.generated.h"

// Forward declared
class UUIFriendItemTooltip;
class UUIFriendsOnlineStatus;

// This class does not need to be modified.
UINTERFACE()
class UFriendWidgetsProvider : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface to expose widgets related to friends online status from a central place,
 * e.g. friend item tooltip, toast
 */
class FRIENDSONLINESTATUS_API IFriendWidgetsProvider
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	// Game instance owning all the not yet created widgets
	virtual UGameInstance* GetWidgetOwner() const = 0;

	// Get the widget class that handles online and offline friends lists
	virtual TSubclassOf<UUIFriendsOnlineStatus> GetFriendsOnlineStatusWidgetClass() const = 0;

	// Get the friend item tooltip widget
	virtual UUIFriendItemTooltip* GetFriendItemTooltip() const = 0;
};
