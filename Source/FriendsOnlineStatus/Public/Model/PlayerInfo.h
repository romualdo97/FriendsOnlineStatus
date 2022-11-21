// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlayerInfo.generated.h"

// Forward declared
class UFriendsListModel;

/**
 * Holds player info data
 */
UCLASS()
class FRIENDSONLINESTATUS_API UPlayerInfo : public UObject
{
	GENERATED_BODY()

public:
	static UPlayerInfo* CreatePlayerInfo(const FString& InNickname, uint32 InLevel, bool InIsConnected);
	const FString& GetNickname() const { return Nickname; }
	FString GetLevelAsNiceString() const { return FString::Printf(TEXT("Level: %i"), GetLevel()); }
	uint32 GetLevel() const { return Level; }
	bool IsConnected() const { return bIsConnected; }
	
private:
	FString Nickname{ TEXT("Anonymous") };
	uint32 Level{ 0 };
	bool bIsConnected{ false };

	// Mark as friend so the model is responsible of updating local id
	friend UFriendsListModel;
};
