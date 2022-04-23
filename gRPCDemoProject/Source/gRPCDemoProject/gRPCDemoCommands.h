#pragma once

#include "CoreMinimal.h"

class UDemoSubsystem;

class FGRPCDemoCommands final
{
public:
	static void UnaryDemo();
	static void ServerStreamingDemo(FString imageName);

private:
	static UWorld* GetAnyGameWorld();
	static UDemoSubsystem* GetDemoSubSystem();
};

