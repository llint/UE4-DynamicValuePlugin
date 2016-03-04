// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicValuePluginPrivatePCH.h"
#include "DynamicValue.h"
#include "DynamicStruct.h"

UDynamicStruct::UDynamicStruct()
{
    
}

UDynamicValue* UDynamicStruct::GetField(FName FieldName)
{
    UDynamicValue** Value = Fields.Find(FieldName);
    return Value ? *Value : nullptr;
}

void UDynamicStruct::SetField(FName FieldName, UDynamicValue* Value)
{
    if (!Value)
    {
        Fields.Remove(FieldName);
    }
    else
    {
        Fields.Emplace(FieldName, Value);
    }
}

#include "Json.h"

static UDynamicStruct* ConvertJsonObjectToDynamicStruct(FJsonObject* JsonObject);
static UDynamicValue* ConvertJsonValueToDynamicValue(FJsonValue* JsonValue)
{
    UDynamicValue* DynamicValue = nullptr;
    
    switch (JsonValue->Type)
    {
        case EJson::None:
        case EJson::Null:
            break;
            
        case EJson::Boolean:
        {
            auto Value = NewObject<UDynamicValueBoolean>();
            Value->Value = JsonValue->AsBool();
            DynamicValue = Value;
            break;
        }
            
        case EJson::Number:
        {
            auto Value = NewObject<UDynamicValueFloat>();
            Value->Value = (float)JsonValue->AsNumber();
            DynamicValue = Value;
            break;
        }
            
        case EJson::String:
        {
            auto Value = NewObject<UDynamicValueString>();
            Value->Value = JsonValue->AsString();
            DynamicValue = Value;
            break;
        }
            
        case EJson::Array:
        {
            auto Value = NewObject<UDynamicValueArray>();
            const auto& Array = JsonValue->AsArray();
            for (const auto& Element : Array)
            {
                UDynamicValue* DynamicValue = ConvertJsonValueToDynamicValue(Element.Get());
                if (DynamicValue)
                {
                    Value->Value.Add(DynamicValue);
                }
            }
            DynamicValue = Value;
            break;
        }
            
        case EJson::Object:
        {
            auto Value = NewObject<UDynamicValueStruct>();
            Value->Value = ConvertJsonObjectToDynamicStruct( JsonValue->AsObject().Get() ); // Value is a UPROPERTY, so the default one should be GC'ed!
            DynamicValue = Value;
            break;
        }
            
        default:
            break;
    }
    
    return DynamicValue;
}

static UDynamicStruct* ConvertJsonObjectToDynamicStruct(FJsonObject* JsonObject)
{
    auto Result = NewObject<UDynamicStruct>();
    for (const auto& Each : JsonObject->Values)
    {
        UDynamicValue* DynamicValue = ConvertJsonValueToDynamicValue(Each.Value.Get());
        if (DynamicValue)
        {
            Result->SetField(*Each.Key, DynamicValue);
        }
    }
    return Result;
}

UDynamicStruct* UDynamicStructLibrary::MakeDynamicStruct()
{
    return NewObject<UDynamicStruct>();
}

UDynamicStruct* UDynamicStructLibrary::ParseJsonString(FString JsonString)
{
    TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
    TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(JsonString);
    if ( FJsonSerializer::Deserialize(Reader, JsonObject) )
    {
        return ConvertJsonObjectToDynamicStruct(JsonObject.Get());
    }
    
    return nullptr;
}

