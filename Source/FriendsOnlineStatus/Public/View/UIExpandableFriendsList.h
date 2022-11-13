// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIExpandableFriendsList.generated.h"

// Forward declared
class UButton;
class UTextBlock;
class UImage;
class UListView;
class UWidgetAnimation;

/**
 * Handles the expandable list widget
 */
UCLASS()
class FRIENDSONLINESTATUS_API UUIExpandableFriendsList : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void OnExpandButtonClicked();

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
