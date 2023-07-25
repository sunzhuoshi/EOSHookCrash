// Copyright Epic Games, Inc. All Rights Reserved.

#include "EOSHookCrash.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Engine/Engine.h"
#include "D3D12RHIPrivate.h"
#include "Test.h"

#define LOCTEXT_NAMESPACE "FEOSHookCrashModule"
DEFINE_LOG_CATEGORY_STATIC(LogEOSHookCrash, Log, All);

void FEOSHookCrashModule::StartupModule()
{
    FD3D12DynamicRHI* D3D12RHI = static_cast<FD3D12DynamicRHI*>(GDynamicRHI);
    const TCHAR* VendorName = GetDeviceVendorName(D3D12RHI->GetAdapter(0).GetD3DDevice());
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
    UE_LOG(LogEOSHookCrash, Log, TEXT("Vendor: %s"), VendorName);
}

void FEOSHookCrashModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEOSHookCrashModule, EOSHookCrash)
