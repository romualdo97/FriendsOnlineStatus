// Fill out your copyright notice in the Description page of Project Settings.


#include "View/UIExpandableFriendsList.h"

#include "Animation/UMGSequencePlayer.h"
#include "Animation/WidgetAnimation.h"
#include "Components/Button.h"
#include "Components/ListView.h"

void UUIExpandableFriendsList::NativeConstruct()
{
	Super::NativeConstruct();

	for (uint32 i = 0; i < 32; ++i)
	{
		ListView->AddItem(NewObject<UObject>());
	}
	
	ExpandButton->OnClicked.AddDynamic(this, &UUIExpandableFriendsList::OnExpandButtonClicked);
}

void UUIExpandableFriendsList::OnExpandButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("Expand clicked"));

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
