// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicValuePluginPrivatePCH.h"
#include "DynamicValue.h"
#include "DynamicStruct.h"

UDynamicValue::UDynamicValue()
{
    
}

UDynamicValueBoolean* UDynamicValueLibrary::MakeDynamicValueBoolean(bool Value)
{
    auto Result = NewObject<UDynamicValueBoolean>();
    Result->Value = Value;
    return Result;
}

UDynamicValueInteger* UDynamicValueLibrary::MakeDynamicValueInteger(int32 Value)
{
    auto Result = NewObject<UDynamicValueInteger>();
    Result->Value = Value;
    return Result;
}

UDynamicValueFloat* UDynamicValueLibrary::MakeDynamicValueFloat(float Value)
{
    auto Result = NewObject<UDynamicValueFloat>();
    Result->Value = Value;
    return Result;
}

UDynamicValueString* UDynamicValueLibrary::MakeDynamicValueString(FString Value)
{
    auto Result = NewObject<UDynamicValueString>();
    Result->Value = Value;
    return Result;
}

UDynamicValueVector* UDynamicValueLibrary::MakeDynamicValueVector(FVector Value)
{
    auto Result = NewObject<UDynamicValueVector>();
    Result->Value = Value;
    return Result;
}

UDynamicValueRotator* UDynamicValueLibrary::MakeDynamicValueRotator(FRotator Value)
{
    auto Result = NewObject<UDynamicValueRotator>();
    Result->Value = Value;
    return Result;
}

UDynamicValueArray* UDynamicValueLibrary::MakeDynamicValueArray()
{
    return NewObject<UDynamicValueArray>();
}

UDynamicValueStruct* UDynamicValueLibrary::MakeDynamicValueStruct()
{
    return NewObject<UDynamicValueStruct>();
}

UDynamicValueActor* UDynamicValueLibrary::MakeDynamicValueActor(class AActor* Value)
{
    auto Result = NewObject<UDynamicValueActor>();
    Result->Value = Value;
    return Result;
}

UDynamicValueActorSet* UDynamicValueLibrary::MakeDynamicValueActorSet()
{
    return NewObject<UDynamicValueActorSet>();
}

UDynamicValueObject* UDynamicValueLibrary::MakeDynamicValueObject(UObject* Value)
{
    auto Result = NewObject<UDynamicValueObject>();
    Result->Value = Value;
    return Result;
}

UDynamicValueClass* UDynamicValueLibrary::MakeDynamicValueClass(UClass* Value)
{
    auto Result = NewObject<UDynamicValueClass>();
    Result->Value = Value;
    return Result;
}

