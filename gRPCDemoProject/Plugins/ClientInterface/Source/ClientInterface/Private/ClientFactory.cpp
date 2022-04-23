#include "ClientFactory.h"


TMap<FName, TSharedPtr<IServiceClientFactory>> FServiceClientFactory::FactoryMap;

void FServiceClientFactory::AddFactory(FName factoryName, TSharedPtr<IServiceClientFactory> factory)
{
	checkf(!FactoryMap.Contains(factoryName), TEXT("Factory name \"%s\" already exists."), *factoryName.ToString());
	FactoryMap.Add(factoryName, factory);
	UE_LOG(LogTemp, Log, TEXT("Add service client factory. \"%s\""), *factoryName.ToString());
}

void FServiceClientFactory::RemoveFactory(FName factoryName)
{
	ensureAlwaysMsgf(FactoryMap.Contains(factoryName), TEXT("Factory not found. \"%s\""));
	FactoryMap.Remove(factoryName);
	UE_LOG(LogTemp, Log, TEXT("Remove service client factory. \"%s\""), *factoryName.ToString());
}

TSharedPtr<IServiceClient> FServiceClientFactory::CreateServiceClient(FName factoryName)
{
	if (ensureAlwaysMsgf(FactoryMap.Contains(factoryName), TEXT("Factory not found. \"%s\"")))
	{
		if(ensureAlwaysMsgf(FactoryMap[factoryName].IsValid(), TEXT("Factory is invalid. \"%s\" ")))
		{
			return FactoryMap[factoryName]->CreateServiceClient();
		}
		else
		{
			return nullptr;
		}
	}
	else
	{
		return nullptr;
	}
}
