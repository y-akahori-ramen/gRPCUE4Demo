#pragma once
#include <CoreMinimal.h>

class CLIENTINTERFACE_API FResponseResult
{
public:
	FResponseResult(bool bSuccess, FString message)
		: bSuccess(bSuccess), Message(message)
	{
	}

	explicit FResponseResult(bool bStatus)
		: bSuccess(bStatus)
	{
	}

	void SetMessage(FString message) { Message = message; }

	bool IsSuccess() const { return bSuccess; }
	const FString& GetMessage() const { return Message; }

private:
	bool bSuccess;
	FString Message;
};

DECLARE_DELEGATE_TwoParams(FUnaryResponseDelegate, FResponseResult, FString);
DECLARE_DELEGATE_TwoParams(FServerStreamingResponseDelegate, FResponseResult, TArray<uint8>);
DECLARE_DELEGATE_TwoParams(FClientStreamingResponseDelegate, FResponseResult, uint32);

class CLIENTINTERFACE_API IServiceClient
{
public:
	virtual ~IServiceClient() = default;
	virtual void RequestUnary(FUnaryResponseDelegate responseDelegate) = 0;
	virtual void RequestServerStreaming(FServerStreamingResponseDelegate responseDelegate, FString imageName) = 0;
	virtual void RequestClientStreaming(FClientStreamingResponseDelegate responseDelegate, FString imageName, TSharedPtr<TArray64<uint8>> imageData) = 0;
};
