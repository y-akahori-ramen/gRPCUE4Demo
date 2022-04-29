#pragma once

#include "CoreMinimal.h"

class UDemoSubsystem;

class FGRPCDemoCommands final
{
public:
	static void UnaryDemo();
	static void ServerStreamingDemo(FString imageName);
	static void ClientStreamingDemo();

private:
	static UWorld* GetAnyGameWorld();
	static UDemoSubsystem* GetDemoSubSystem();
	static void OnScreenshotCaptured(int32 width, int32 height, const TArray<FColor>& colors);
	static TOptional<FDelegateHandle> ScreenShotCapturedDelegateHandle;
};

