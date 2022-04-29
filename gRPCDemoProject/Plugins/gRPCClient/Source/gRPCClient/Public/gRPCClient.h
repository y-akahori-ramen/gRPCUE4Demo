#pragma once
#include <ClientInterface.h>
#include <ClientFactory.h>
#include "gRPCClient.generated.h"

class FGRPCClient : public IServiceClient
{
public:
	explicit FGRPCClient(FString endpont);
	virtual void RequestUnary(FUnaryResponseDelegate responseDelegate) override;
	virtual void RequestServerStreaming(FServerStreamingResponseDelegate responseDelegate, FString imageName) override;
	virtual void RequestClientStreaming(FClientStreamingResponseDelegate responseDelegate, FString imageName, TSharedPtr<TArray64<uint8>> imageData) override;
private:
	const FString EndPoint;
};

UCLASS(config=gRPCClientConfig,defaultconfig)
class UGRPCClientConfig : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	virtual FName GetCategoryName() const override;

#if WITH_EDITOR
	virtual FText GetSectionText() const override;
#endif

	UPROPERTY(EditAnywhere, Config)
	FString Endpoint;
};

class FGRPCClientFactory : public IServiceClientFactory
{
public:
	virtual TSharedPtr<IServiceClient> CreateServiceClient() override;
};