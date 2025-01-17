// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"
#include "Public/HJ_Utill.h"

DECLARE_LOG_CATEGORY_CLASS(HJ, Log, All);
#define _HJ_INFO (FString(__FUNCTION__) + TEXT("- [") + FString::FromInt(__LINE__)+ TEXT("]"))
#define HJ_CALL_LOG(Verbosity) UE_LOG(HJ, Verbosity, TEXT("%s"), *_HJ_INFO)
#define HJ_LOG(Verbosity,Format, ...) UE_LOG(HJ, Verbosity, TEXT("%s - %s"), *_HJ_INFO, *FString::Printf(Format, ##__VA_ARGS__))
