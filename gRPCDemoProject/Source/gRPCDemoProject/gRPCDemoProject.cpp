// Copyright Epic Games, Inc. All Rights Reserved.

#include "gRPCDemoProject.h"
#include "Modules/ModuleManager.h"
#include "gRPCDemoCommands.h"

class FgRPCDemoProjectModule final : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;
};

void FgRPCDemoProjectModule::StartupModule()
{
	if (!IsRunningCommandlet())
	{
		IConsoleManager::Get().RegisterConsoleCommand(
			TEXT("UnaryDemo"),
			TEXT("UnaryDemo"),
			FConsoleCommandWithArgsDelegate::CreateLambda([](const TArray<FString>& Args)
			{
				FGRPCDemoCommands::UnaryDemo();
			}),
			ECVF_Default
		);
	}
}


IMPLEMENT_PRIMARY_GAME_MODULE(FgRPCDemoProjectModule, gRPCDemoProject, "gRPCDemoProject");
