#include "gRPCClient.h"

THIRD_PARTY_INCLUDES_START
#pragma warning (disable : 4005)
#include <grpcpp/grpcpp.h>
THIRD_PARTY_INCLUDES_END
#include "proto/unaryDemo.grpc.pb.h"
#include "proto/serverStreamingDemo.grpc.pb.h"
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
	TArray<uint8> responseData;
	if (status.ok())
	{
		responseData.AddUninitialized(recieveData.length());
		FMemory::Memcpy(responseData.GetData(), recieveData.c_str(), recieveData.length());
	}
	else
	{
		reulst.SetMessage(status.error_message().c_str());
	}

	responseDelegate.ExecuteIfBound(reulst, responseData);
}
