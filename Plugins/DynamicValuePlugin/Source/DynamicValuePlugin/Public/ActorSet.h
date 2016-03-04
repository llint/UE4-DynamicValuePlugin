// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "ActorSet.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UActorSet : public UObject
{
	GENERATED_BODY()

public:
    UActorSet();

    UFUNCTION(BlueprintCallable, Category="ActorSet")
    bool Add(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category="ActorSet")
    bool Remove(AActor* Actor);

    UFUNCTION(BlueprintCallable, Category="ActorSet")
    TArray<AActor*> GetActors() const;

    UFUNCTION(BlueprintCallable, Category="ActorSet")
    bool Contains(AActor* Actor) const;

    UFUNCTION(BlueprintPure, Category="ActorSet")
    static UActorSet* MakeActorSet();

private:
    UPROPERTY()
    TMap<AActor*, int32> ActorMap;

    UPROPERTY()
    TArray<AActor*> Actors;
};

