// Fill out your copyright notice in the Description page of Project Settings.


#include "DemoActor.h"

// Sets default values
ADemoActor::ADemoActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ADemoActor::BeginPlay()
{
	Super::BeginPlay();

	Primitive = FindComponentByClass<UPrimitiveComponent>();

	UMaterial* baseMaterial = Cast<UMaterial>(StaticLoadObject(UMaterial::StaticClass(), this, TEXT("/Game/UnlitMat")));
	if(ensureMsgf(baseMaterial != nullptr, TEXT("Fail to load material. ")))
	{
		MaterialInstance = Primitive->CreateAndSetMaterialInstanceDynamicFromMaterial(0, baseMaterial);
	}
}

void ADemoActor::ChangeTexture(UTexture2D* texture)
{
	if(ensureMsgf(Primitive.IsValid(), TEXT("Invalid primitive.")))
	{
		MaterialInstance->SetTextureParameterValue("Texture", texture);
	}
}
