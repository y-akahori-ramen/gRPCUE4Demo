// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DemoActor.generated.h"

UCLASS()
class GRPCDEMOPROJECT_API ADemoActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADemoActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	void ChangeTexture(UTexture2D* texture);

private:
	TWeakObjectPtr<UPrimitiveComponent> Primitive;

	UPROPERTY()
	UMaterialInstanceDynamic* MaterialInstance;
};
