#include "gRPCDemoCommands.h"

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Kismet/GameplayStatics.h"
#include "DemoSubsystem.h"
#include <ClientFactory.h>

void FGRPCDemoCommands::UnaryDemo()
{
	TSharedPtr<IServiceClient> client = FServiceClientFactory::CreateServiceClient(TEXT("gRPCClient"));

	FUnaryResponseDelegate unaryDelegate;
	unaryDelegate.BindLambda(
		[](FResponseResult result, FString message) {
			UE_LOG(LogTemp, Log, TEXT("result:%d message:%s"), result.IsSuccess(), *message);
			if(result.IsSuccess())
			{
				GEngine->AddOnScreenDebugMessage(0, 5, FColor::Yellow, *message);
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, *FString::Printf(TEXT("Failed. %s"), *result.GetMessage()));
			}
		});

	client->RequestUnary(unaryDelegate);
}

void FGRPCDemoCommands::ServerStreamingDemo(FString imageName)
{
	TSharedPtr<IServiceClient> client = FServiceClientFactory::CreateServiceClient(TEXT("gRPCClient"));

	FServerStreamingResponseDelegate responseDelegate;
	responseDelegate.BindLambda(
		[](FResponseResult result, TArray<uint8> bmpData)
		{
			if (result.IsSuccess())
			{
				TSharedPtr<IImageWrapper> imageWrappger = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper")).CreateImageWrapper(EImageFormat::PNG);
				imageWrappger->SetCompressed(bmpData.GetData(), bmpData.Num());

				TArray<uint8> rgbaData;
				imageWrappger->GetRaw(ERGBFormat::RGBA, 8, rgbaData);

				if (UDemoSubsystem* demoSystem = GetDemoSubSystem(); demoSystem != nullptr)
				{
					demoSystem->ChangeTexture(imageWrappger->GetWidth(), imageWrappger->GetHeight(), PF_R8G8B8A8, rgbaData.GetData(), rgbaData.Num());
					GEngine->AddOnScreenDebugMessage(0, 5, FColor::Yellow, TEXT("ChangeTexture"));
				}
				else
				{
					GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, TEXT("Fail to get demo system."));
				}
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, *FString::Printf(TEXT("Failed. %s"), *result.GetMessage()));
			}
		});

	client->RequestServerStreaming(responseDelegate, imageName);
}

UWorld* FGRPCDemoCommands::GetAnyGameWorld()
{
	UWorld* world = nullptr;
	const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
	for (const FWorldContext& WorldContext : WorldContexts)
	{
		const bool bIsValid = WorldContext.World() != nullptr
			&& (WorldContext.WorldType == EWorldType::PIE || WorldContext.WorldType == EWorldType::Game);

		if (bIsValid)
		{
			world = WorldContext.World();
			break;
		}
	}

	return world;
}

UDemoSubsystem* FGRPCDemoCommands::GetDemoSubSystem()
{
	if(UWorld* world = GetAnyGameWorld(); world != nullptr)
	{
		return world->GetGameInstance()->GetSubsystem<UDemoSubsystem>();
	}
	else
	{
		return nullptr;
	}
}
