#pragma once
#include <CoreMinimal.h>
#include "ClientInterface.h"


class CLIENTINTERFACE_API IServiceClientFactory
{
public:
	virtual ~IServiceClientFactory() = default;
	virtual TSharedPtr<IServiceClient> CreateServiceClient() = 0;
};


class CLIENTINTERFACE_API FServiceClientFactory final
{
public:
	static void AddFactory(FName factoryName, TSharedPtr<IServiceClientFactory> factory);
	static void RemoveFactory(FName factoryName);
	static TSharedPtr<IServiceClient> CreateServiceClient(FName factoryName);

private:
	static TMap<FName, TSharedPtr<IServiceClientFactory>> FactoryMap;
};