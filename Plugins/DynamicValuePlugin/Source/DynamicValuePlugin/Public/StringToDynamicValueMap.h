// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "StringToDynamicValueMap.generated.h"

class UDynamicValue;

/**
 * 
 */
UCLASS(BlueprintType)
class UStringToDynamicValueMap : public UObject
{
	GENERATED_BODY()

public:
    UStringToDynamicValueMap();

    UFUNCTION(BlueprintCallable, Category="StringToDynamicValueMap")
    UStringToDynamicValueMap* Add(FString Key, UDynamicValue* Value);

    UFUNCTION(BlueprintCallable, Category="StringToDynamicValueMap")
    UStringToDynamicValueMap* Remove(FString Key);

    UFUNCTION(BlueprintCallable, Category="StringToDynamicValueMap")
    UDynamicValue* GetValue(FString Key) const;

    UFUNCTION(BlueprintCallable, Category="StringToDynamicValueMap")
    bool Contains(FString Key) const;

    UFUNCTION(BlueprintCallable, Category="StringToDynamicValueMap")
    TArray<FString> GetKeys() const;

    UFUNCTION(BlueprintCallable, Category="StringToDynamicValueMap")
    TArray<UDynamicValue*> GetValues() const;

    UFUNCTION(BlueprintPure, Category="StringToDynamicValueMap")
    static UStringToDynamicValueMap* MakeStringToDynamicValueMap();

private:
    void RemoveKeyIndex(FString Key, int32 Index);

private:
    TMap<FString, int32> StringToIndexMap;

    TArray<FString> StringKeys;

    UPROPERTY()
    TArray<UDynamicValue*> DynamicValues;
};

