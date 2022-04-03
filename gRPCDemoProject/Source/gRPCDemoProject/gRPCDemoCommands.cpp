#include "gRPCDemoCommands.h"

THIRD_PARTY_INCLUDES_START
#pragma warning (disable : 4005)
#include <grpcpp/grpcpp.h>
THIRD_PARTY_INCLUDES_END
#include "proto/unaryDemo.grpc.pb.h"

void FGRPCDemoCommands::UnaryDemo()
{
	const std::shared_ptr<grpc::Channel> channel = grpc::CreateChannel("localhost:8000", grpc::InsecureChannelCredentials());
	const std::unique_ptr<grpcDemo::UnaryDemoService::Stub> stub(grpcDemo::UnaryDemoService::NewStub(channel));

	grpcDemo::UnaryDemoRequest request;
	request.set_name("UnaryDemo");

	grpcDemo::UnaryDemoResponse response;
	grpc::ClientContext context;
	const grpc::Status status = stub->Request(&context, request, &response);


	FString result;
	if (status.ok())
	{
		result = response.message().c_str();
	}
	else
	{
		result = TEXT("RPC failed");
	}


	GEngine->AddOnScreenDebugMessage(0, 5, FColor::Yellow, result);
}
