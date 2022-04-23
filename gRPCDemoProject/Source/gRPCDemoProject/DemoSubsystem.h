// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DemoSubsystem.generated.h"

/**
 * 
 */
UCLASS()
class GRPCDEMOPROJECT_API UDemoSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void ChangeTexture(int32 width, int32 height, EPixelFormat format, const void* data, SIZE_T dataSize);
};
