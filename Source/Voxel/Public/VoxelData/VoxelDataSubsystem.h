// Copyright 2020 Phyronnaz

#pragma once

#include "CoreMinimal.h"
#include "VoxelSubsystem.h"
#include "VoxelDataSubsystem.generated.h"

class FVoxelData;

UCLASS()
class VOXEL_API UVoxelDataSubsystemProxy : public UVoxelStaticSubsystemProxy
{
	GENERATED_BODY()
	GENERATED_VOXEL_SUBSYSTEM_PROXY_BODY(FVoxelDataSubsystem);
};

class FVoxelDataSubsystem : public IVoxelSubsystem
{
public:
	GENERATED_VOXEL_SUBSYSTEM_BODY(UVoxelDataSubsystemProxy);

	FVoxelData& GetData() const { return *Data; }
	TVoxelSharedRef<FVoxelData> GetDataPtr() const { return Data.ToSharedRef(); }

	//~ Begin IVoxelSubsystem Interface
	virtual void Create() override;
	//~ End IVoxelSubsystem Interface

private:
	TVoxelSharedPtr<FVoxelData> Data;
};