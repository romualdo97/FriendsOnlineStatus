// Fill out your copyright notice in the Description page of Project Settings.


#include "View/UIExpandableFriendsList.h"

#include "Animation/UMGSequencePlayer.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UUIExpandableFriendsList::NativeConstruct()
{
	Super::NativeConstruct();

	ExpandButton->OnClicked.AddDynamic(this, &UUIExpandableFriendsList::OnExpandButtonClicked);
}

void UUIExpandableFriendsList::AddItem(UObject* Item)
{
	ListView->AddItem(Item);
	UpdateCountLabel();
}

void UUIExpandableFriendsList::RemoveItem(UObject* Item)
{
	ListView->RemoveItem(Item);
	UpdateCountLabel();
}

void UUIExpandableFriendsList::UpdateCountLabel()
{
	CountLabel->SetText(FText::FromString(FString::Printf(TEXT("%i"), ListView->GetNumItems())));
}

void UUIExpandableFriendsList::OnExpandButtonClicked()
{
	if (bIsExpanded)
	{
		// Collapse
		UUserWidget::PlayAnimationReverse(ExpandPanelAnimation);
	}
	else
	{
		// Expands
		UUserWidget::PlayAnimation(ExpandPanelAnimation);
	}

	bIsExpanded = !bIsExpanded;
}
