#include "gRPCClient.h"

THIRD_PARTY_INCLUDES_START
#pragma warning (disable : 4005)
#include <grpcpp/grpcpp.h>
THIRD_PARTY_INCLUDES_END
#include "proto/unaryDemo.grpc.pb.h"
#include "proto/serverStreamingDemo.grpc.pb.h"
#include "proto/clientStreamingDemo.grpc.pb.h"
#include <array>

FGRPCClient::FGRPCClient(FString endpont)
	: EndPoint(endpont)
{
}

void FGRPCClient::RequestUnary(FUnaryResponseDelegate responseDelegate)
{
	const std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(TCHAR_TO_UTF8(*EndPoint), grpc::InsecureChannelCredentials());
	const std::unique_ptr<grpcDemo::UnaryDemoService::Stub> stub(grpcDemo::UnaryDemoService::NewStub(channel));

	grpcDemo::UnaryDemoRequest request;
	request.set_name("UnaryDemo");

	grpcDemo::UnaryDemoResponse response;
	grpc::ClientContext context;
	const grpc::Status status = stub->Request(&context, request, &response);


	FResponseResult reulst(status.ok());
	FString responseMessage;
	if (status.ok())
	{
		responseMessage = response.message().c_str();
	}
	else
	{
		reulst.SetMessage(status.error_message().c_str());
	}

	responseDelegate.ExecuteIfBound(reulst, responseMessage);
}

void FGRPCClient::RequestServerStreaming(FServerStreamingResponseDelegate responseDelegate, FString imageName)
{
	const std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(TCHAR_TO_UTF8(*EndPoint), grpc::InsecureChannelCredentials());
	const std::unique_ptr<grpcDemo::ServerStreamingDemoService::Stub> stub(grpcDemo::ServerStreamingDemoService::NewStub(channel));

	grpc::ClientContext context;
	grpcDemo::GetServerStreamingTextureRequest request;
	request.set_imagename(TCHAR_TO_UTF8(*imageName));

	std::unique_ptr<grpc::ClientReader<grpcDemo::GetServerStreamingTextureResponse>> reader = stub->GetTexture(&context, request);
	std::string recieveData;
	grpcDemo::GetServerStreamingTextureResponse response;
	while (reader->Read(&response))
	{
		recieveData.append(response.chunk());
		UE_LOG(LogTemp, Log, TEXT("ReceiveData:%dByte\n"), response.chunk().length());
	}

	const grpc::Status status = reader->Finish();
	FResponseResult reulst(status.ok());
	TSharedPtr<TArray<uint8>> responseData = MakeShareable(new TArray<uint8>);
	if (status.ok())
	{
		responseData->AddUninitialized(recieveData.length());
		FMemory::Memcpy(responseData->GetData(), recieveData.c_str(), recieveData.length());
	}
	else
	{
		reulst.SetMessage(status.error_message().c_str());
	}

	responseDelegate.ExecuteIfBound(reulst, responseData);
}

void FGRPCClient::RequestClientStreaming(FClientStreamingResponseDelegate responseDelegate, FString imageName, TSharedPtr<TArray64<uint8>> imageData)
{
	const std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel(TCHAR_TO_UTF8(*EndPoint), grpc::InsecureChannelCredentials());
	const std::unique_ptr<grpcDemo::ClinentStreamingDemoService::Stub> stub(grpcDemo::ClinentStreamingDemoService::NewStub(channel));

	grpc::ClientContext context;
	grpcDemo::UploadClientTextureResponse response;
	std::unique_ptr<grpc::ClientWriter<grpcDemo::UploadClientTextureRequest>> writer = stub->UploadTexture(&context, &response);

	grpcDemo::UploadClientTextureRequest request;
	request.set_imagename(TCHAR_TO_UTF8(*imageName));

	if (writer->Write(request))
	{
		int32 totalSentDataSize = 0;
		std::string chunkData;
		const int32 totalDataSize = imageData->Num();
		do
		{
			constexpr int32 sendDataSizePerRequest = 1024;
			const int32 sendSize = FMath::Min(totalDataSize - totalSentDataSize, sendDataSizePerRequest);
			if (chunkData.size() != sendSize)
			{
				chunkData.resize(sendSize);
			}

			FMemory::Memcpy(chunkData.data(), imageData->GetData() + totalSentDataSize, sendSize);
			request.set_chunk(chunkData);
			if(!writer->Write(request))
			{
				break;
			}

			totalSentDataSize += sendSize;
			UE_LOG(LogTemp, Log, TEXT("Sent texture data (%d/%d)"), totalSentDataSize, totalDataSize);
		}
		while (totalSentDataSize < totalDataSize);
	}

	writer->WritesDone();
	const grpc::Status status = writer->Finish();

	FResponseResult reulst(status.ok());
	TArray<uint8> responseData;
	reulst.SetMessage(status.error_message().c_str());
	responseDelegate.ExecuteIfBound(reulst, response.size());
}

FName UGRPCClientConfig::GetCategoryName() const
{
	return TEXT("DemoClient");
}

#if WITH_EDITOR
FText UGRPCClientConfig::GetSectionText() const
{
	return FText::FromString(TEXT("gRPC client config"));
}
#endif

TSharedPtr<IServiceClient> FGRPCClientFactory::CreateServiceClient()
{
	return MakeShareable(new FGRPCClient(GetDefault<UGRPCClientConfig>()->Endpoint));
}
