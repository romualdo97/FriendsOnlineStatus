// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIExpandableFriendsList.generated.h"

// Forward declared
class UButton;
class UTextBlock;
class UImage;
class USizeBox;
class UListView;
class UWidgetAnimation;

/**
 * Handles the expandable list widget
 */
UCLASS()
class FRIENDSONLINESTATUS_API UUIExpandableFriendsList : public UUserWidget
{
	GENERATED_BODY()

public:
	UListView* GetListView() const { return ListView; }
	void AddItem(UObject* Item);
	void RemoveItem(UObject* Item);

protected:
	virtual void NativeConstruct() override;

private:
	void UpdateCountLabel();

	UFUNCTION()
	void HandleExpandButtonClicked();

private:
	bool bIsExpanded { false };

	UPROPERTY(meta = (BindWidget))
	UButton* ExpandButton;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* CountLabel;

	UPROPERTY(meta = (BindWidget))
	UListView* ListView;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* ExpandPanelAnimation;
};
