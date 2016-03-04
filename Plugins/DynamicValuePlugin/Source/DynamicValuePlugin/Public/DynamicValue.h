// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "ActorSet.h"
#include "DynamicStruct.h"
#include "DynamicValue.generated.h"

UENUM(BlueprintType)
enum class EDynamicValueType
{
    None,
    Boolean,
    Integer,
    Float,
    String,
    Vector,
    Rotator,
    Actor,
    ActorSet,
    Object,
    Class,
    Array,
    Struct,
};

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable, Abstract)
class UDynamicValue : public UObject
{
	GENERATED_BODY()

public:
    UDynamicValue();

    UFUNCTION(BlueprintCallable, Category="DynamicValue")
    virtual EDynamicValueType GetType() const
    {
        return EDynamicValueType::None;
    }
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueBoolean : public UDynamicValue
{
    GENERATED_BODY()

public:
    UDynamicValueBoolean() : Value(false) {}

    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Boolean;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueInteger : public UDynamicValue
{
    GENERATED_BODY()
    
public:
    UDynamicValueInteger() : Value(0) {}

    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Integer;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueFloat : public UDynamicValue
{
    GENERATED_BODY()
    
public:
    UDynamicValueFloat() : Value(0.f) {}
    
    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Float;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueString : public UDynamicValue
{
    GENERATED_BODY()
    
public:
    UDynamicValueString() {}

    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::String;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueVector : public UDynamicValue
{
    GENERATED_BODY()
    
public:
    UDynamicValueVector() {}
    
    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Vector;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueRotator : public UDynamicValue
{
    GENERATED_BODY()
    
public:
    UDynamicValueRotator() {}
    
    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Rotator;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FRotator Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueArray : public UDynamicValue
{
    GENERATED_BODY()
    
public:
    UDynamicValueArray() {}
    
    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Array;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<UDynamicValue*> Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueStruct : public UDynamicValue
{
    GENERATED_BODY()
    
public:
    UDynamicValueStruct() : Value( NewObject<UDynamicStruct>() ) {}

    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Struct;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UDynamicStruct* Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueActor : public UDynamicValue
{
    GENERATED_BODY()

public:
    UDynamicValueActor() : Value(nullptr) {}

    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Actor;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class AActor* Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueActorSet : public UDynamicValue
{
    GENERATED_BODY()

public:
    UDynamicValueActorSet() : Value( NewObject<UActorSet>() ) {}

    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::ActorSet;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    class UActorSet* Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueObject : public UDynamicValue
{
    GENERATED_BODY()

public:
    UDynamicValueObject() : Value(nullptr) {}

    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Object;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UObject* Value;
};

UCLASS(BlueprintType, NotBlueprintable)
class UDynamicValueClass : public UDynamicValue
{
    GENERATED_BODY()

public:
    UDynamicValueClass() : Value(nullptr) {}

    EDynamicValueType GetType() const override
    {
        return EDynamicValueType::Class;
    }

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UClass* Value;
};

UCLASS()
class UDynamicValueLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueBoolean* MakeDynamicValueBoolean(bool Value);

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueInteger* MakeDynamicValueInteger(int32 Value);

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueFloat* MakeDynamicValueFloat(float Value);

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueString* MakeDynamicValueString(FString Value);

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueVector* MakeDynamicValueVector(FVector Value);

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueRotator* MakeDynamicValueRotator(FRotator Value);

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueArray* MakeDynamicValueArray();

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueStruct* MakeDynamicValueStruct();

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueActor* MakeDynamicValueActor(class AActor* Value);

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueActorSet* MakeDynamicValueActorSet();

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueObject* MakeDynamicValueObject(UObject* Value);

    UFUNCTION(BlueprintPure, Category="DynamicValue")
    static UDynamicValueClass* MakeDynamicValueClass(UClass* Value);
};

