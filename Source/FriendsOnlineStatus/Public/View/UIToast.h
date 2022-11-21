// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UIToast.generated.h"

// Forward declared
class UTextBlock;
class UWidgetAnimation;

/**
 * Handles the toast UI
 */
UCLASS()
class FRIENDSONLINESTATUS_API UUIToast : public UUserWidget
{
	GENERATED_BODY()
public:
	void Show(const FText& InMessage);
	
private:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ToastMessageLabel;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	UWidgetAnimation* ShowToastAnimation;
};
