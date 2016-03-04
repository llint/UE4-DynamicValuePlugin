// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "DynamicStruct.generated.h"

class UDynamicValue;

/**
 * 
 */
UCLASS(BlueprintType)
class UDynamicStruct : public UObject
{
	GENERATED_BODY()

public:
    UDynamicStruct();

    UFUNCTION(BlueprintCallable, Category="DynamicStruct")
    UDynamicValue* GetField(FName FieldName);
    
    UFUNCTION(BlueprintCallable, Category="DynamicStruct")
    void SetField(FName FieldName, UDynamicValue* Value);

private:
    UPROPERTY()
    TMap<FName, UDynamicValue*> Fields;
};

UCLASS()
class UDynamicStructLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="DynamicStruct")
    static UDynamicStruct* MakeDynamicStruct();

    UFUNCTION(BlueprintPure, Category="DynamicStruct")
    static UDynamicStruct* ParseJsonString(FString JsonString);
};

