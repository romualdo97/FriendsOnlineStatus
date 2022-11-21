// Fill out your copyright notice in the Description page of Project Settings.


#include "View/UIToast.h"
#include "Components/TextBlock.h"
#include "Animation/WidgetAnimation.h"

void UUIToast::Show(const FText& InMessage)
{
	ToastMessageLabel->SetText(InMessage);
	if (UUserWidget::IsAnimationPlaying(ShowToastAnimation))
	{
		UUserWidget::StopAnimation(ShowToastAnimation);
	}
	UUserWidget::PlayAnimation(ShowToastAnimation);
}
