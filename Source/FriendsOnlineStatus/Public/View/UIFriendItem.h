// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "UIFriendItem.generated.h"

// Forward declared
class UTextBlock;

/**
 * An item for the UListView
 */
UCLASS()
class FRIENDSONLINESTATUS_API UUIFriendItem : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	// Implements IUserObjectListEntry
	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;
	// End implements IUserObjectListEntry

private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* NicknameLabel;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* LevelValueLabel;
};
