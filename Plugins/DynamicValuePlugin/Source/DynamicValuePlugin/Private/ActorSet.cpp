// Fill out your copyright notice in the Description page of Project Settings.

#include "DynamicValuePluginPrivatePCH.h"
#include "ActorSet.h"

UActorSet::UActorSet()
{

}

bool UActorSet::Add(AActor* Actor)
{
    int32* Index = ActorMap.Find(Actor);
    if (!Index)
    {
        Actors.Push(Actor);
        ActorMap.Emplace(Actor, Actors.Num()-1);
        return true;
    }
    return false;
}

bool UActorSet::Remove(AActor* Actor)
{
    int32* Index = ActorMap.Find(Actor);
    if (Index)
    {
        Actors.Swap(*Index, Actors.Num()-1);
        ActorMap[Actors[*Index]] = *Index;
        Actors.Pop();
        ActorMap.Remove(Actor);
        return true;
    }
    return false;
}

TArray<AActor*> UActorSet::GetActors() const
{
    return Actors;
}

bool UActorSet::Contains(AActor* Actor) const
{
    return ActorMap.Contains(Actor);
}

UActorSet* UActorSet::MakeActorSet()
{
    return NewObject<UActorSet>();
}

