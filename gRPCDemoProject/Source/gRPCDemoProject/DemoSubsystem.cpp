// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoSubsystem.h"

#include "Kismet/GameplayStatics.h"

#include "DemoActor.h"


void UDemoSubsystem::ChangeTexture(int32 width, int32 height, EPixelFormat format, const void* data, SIZE_T dataSize)
{
	ADemoActor* demoActor = Cast<ADemoActor>(UGameplayStatics::GetActorOfClass(this, ADemoActor::StaticClass()));
	if (demoActor == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Fail to find demo actor."))
		return;
	}

	UTexture2D* newTexture = UTexture2D::CreateTransient(width, height, format);
	void* textureData = newTexture->GetPlatformData()->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
	FMemory::Memcpy(textureData, data, dataSize);
	newTexture->GetPlatformData()->Mips[0].BulkData.Unlock();
	newTexture->UpdateResource();

	demoActor->ChangeTexture(newTexture);
}
