// Copyright Epic Games, Inc. All Rights Reserved.

#include "gRPCClientModule.h"
#include <ClientFactory.h>
#include "gRPCClient.h"

#define LOCTEXT_NAMESPACE "FgRPCClientModule"

void FgRPCClientModule::StartupModule()
{
	FServiceClientFactory::AddFactory(TEXT("gRPCClient"), MakeShareable(new FGRPCClientFactory()));
}

void FgRPCClientModule::ShutdownModule()
{
	FServiceClientFactory::RemoveFactory(TEXT("gRPCClient"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FgRPCClientModule, gRPCClient)