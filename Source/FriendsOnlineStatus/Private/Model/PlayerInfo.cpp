// Fill out your copyright notice in the Description page of Project Settings.


#include "Model/PlayerInfo.h"

UPlayerInfo* UPlayerInfo::CreatePlayerInfo(const FString& InNickname, uint32 InLevel, bool InIsConnected)
{
	UPlayerInfo* NewPlayerInfo = NewObject<UPlayerInfo>();
	NewPlayerInfo->Nickname = InNickname;
	NewPlayerInfo->Level = InLevel;
	NewPlayerInfo->bIsConnected = InIsConnected;
	return NewPlayerInfo;
}
