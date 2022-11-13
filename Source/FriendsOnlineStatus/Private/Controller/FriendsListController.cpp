// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/FriendsListController.h"
#include "Model/FriendsListService.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

void UFriendsListController::Enable() const
{
	check(FriendListWidget != nullptr);
	FriendListWidget->AddToViewport(0);

	const UWorld* World = FriendListWidget->GetWorld();
	check(World != nullptr);
	
	APlayerController* PlayerController = World->GetFirstPlayerController();
	check(PlayerController != nullptr);

	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(FriendListWidget->TakeWidget());
	InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = true;
}

void UFriendsListController::Disable() const
{
	FriendListWidget->RemoveFromViewport();
}
