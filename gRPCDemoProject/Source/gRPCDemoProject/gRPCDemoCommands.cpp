#include "gRPCDemoCommands.h"

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"
#include "Kismet/GameplayStatics.h"
#include "DemoSubsystem.h"
#include <ClientFactory.h>

#include "ImageUtils.h"

TOptional<FDelegateHandle> FGRPCDemoCommands::ScreenShotCapturedDelegateHandle;

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
		[](FResponseResult result, TArray<uint8> pngData)
		{
			if (result.IsSuccess())
			{
				TSharedPtr<IImageWrapper> imageWrappger = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper")).CreateImageWrapper(EImageFormat::PNG);
				imageWrappger->SetCompressed(pngData.GetData(), pngData.Num());

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

void FGRPCDemoCommands::ClientStreamingDemo()
{
	if (!ScreenShotCapturedDelegateHandle.IsSet())
	{
		ScreenShotCapturedDelegateHandle = UGameViewportClient::OnScreenshotCaptured().AddStatic(&FGRPCDemoCommands::OnScreenshotCaptured);
	}
	FScreenshotRequest::RequestScreenshot(false);
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

void FGRPCDemoCommands::OnScreenshotCaptured(int32 width, int32 height, const TArray<FColor>& colors)
{
	TSharedPtr<TArray64<uint8>> pngData = MakeShareable(new TArray64<uint8>);
	FImageUtils::PNGCompressImageArray(width, height, colors, *pngData);

	FString imageName;
	FFileHelper::GenerateDateTimeBasedBitmapFilename(TEXT("ClientStreamingDemo"), TEXT(".png"), imageName);

	FClientStreamingResponseDelegate responseDelegate;
	responseDelegate.BindLambda(
		[](FResponseResult result, uint32 size)
		{
			if(result.IsSuccess())
			{
				const FString message = FString::Printf(TEXT("Sent screenshot to server. size:%d"), size);
				GEngine->AddOnScreenDebugMessage(0, 5, FColor::Yellow, *message);
			}
			else
			{
				GEngine->AddOnScreenDebugMessage(0, 5, FColor::Red, *FString::Printf(TEXT("Failed. %s"), *result.GetMessage()));
			}
		});

	TSharedPtr<IServiceClient> client = FServiceClientFactory::CreateServiceClient(TEXT("gRPCClient"));
	client->RequestClientStreaming(responseDelegate, imageName, pngData);
}
