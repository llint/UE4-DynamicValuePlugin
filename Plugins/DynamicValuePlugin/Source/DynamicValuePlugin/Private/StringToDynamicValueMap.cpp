// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicValuePluginPrivatePCH.h"
#include "DynamicValue.h"
#include "StringToDynamicValueMap.h"

UStringToDynamicValueMap::UStringToDynamicValueMap()
{

}

void UStringToDynamicValueMap::RemoveKeyIndex(FString Key, int32 Index)
{
    StringKeys.Swap(Index, StringKeys.Num()-1);
    StringKeys.Pop();
    DynamicValues.Swap(Index, DynamicValues.Num()-1);
    DynamicValues.Pop();
    StringToIndexMap.Remove(Key);
}

UStringToDynamicValueMap* UStringToDynamicValueMap::Add(FString Key, UDynamicValue* Value)
{
    check(StringKeys.Num() == DynamicValues.Num());
    int32* Index = StringToIndexMap.Find(Key);
    if (Index)
    {
        if (Value)
        {
            DynamicValues[*Index] = Value;
        }
        else
        {
            RemoveKeyIndex(Key, *Index);
        }
    }
    else if (Value)
    {
        StringKeys.Push(Key);
        DynamicValues.Push(Value);
        StringToIndexMap.Emplace(Key, StringKeys.Num()-1);
    }
    check(StringKeys.Num() == DynamicValues.Num());
    return this;
}

UStringToDynamicValueMap* UStringToDynamicValueMap::Remove(FString Key)
{
    check(StringKeys.Num() == DynamicValues.Num());
    int32* Index = StringToIndexMap.Find(Key);
    if (Index)
    {
        RemoveKeyIndex(Key, *Index);
    }
    check(StringKeys.Num() == DynamicValues.Num());
    return this;
}

UDynamicValue* UStringToDynamicValueMap::GetValue(FString Key) const
{
    auto Index = StringToIndexMap.Find(Key);
    return Index ? DynamicValues[*Index] : nullptr;
}

bool UStringToDynamicValueMap::Contains(FString Key) const
{
    return StringToIndexMap.Contains(Key);
}

TArray<FString> UStringToDynamicValueMap::GetKeys() const
{
    return StringKeys;
}

TArray<UDynamicValue*> UStringToDynamicValueMap::GetValues() const
{
    return DynamicValues;
}

UStringToDynamicValueMap* UStringToDynamicValueMap::MakeStringToDynamicValueMap()
{
    return NewObject<UStringToDynamicValueMap>();
}

