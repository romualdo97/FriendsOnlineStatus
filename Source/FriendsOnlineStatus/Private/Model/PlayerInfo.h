// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * Represents info about a player
 */
struct FPlayerInfo
{
	FString Nickname;
	uint32 Level;
	bool bIsConnected;
};
