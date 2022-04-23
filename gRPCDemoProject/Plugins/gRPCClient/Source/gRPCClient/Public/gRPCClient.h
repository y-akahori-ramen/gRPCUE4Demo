#pragma once
#include <ClientInterface.h>
#include <ClientFactory.h>

class FGRPCClient : public IServiceClient
{
public:
	explicit FGRPCClient(FString endpont);
	virtual void RequestUnary(FUnaryResponseDelegate responseDelegate) override;
	virtual void RequestServerStreaming(FServerStreamingResponseDelegate responseDelegate, FString imageName) override;
	
private:
	const FString EndPoint;
};

class FGRPCClientFactory : public IServiceClientFactory
{
public:
	virtual TSharedPtr<IServiceClient> CreateServiceClient() override
	{
		return MakeShareable(new FGRPCClient(TEXT("localhost:8000")));
	}
};