#include "Test.h"

#include <stdexcept>

#include "Windows/AllowWindowsPlatformTypes.h"
#include "Windows/AllowWindowsPlatformAtomics.h"
#include <windows.h>
#include <d3d12.h>
#include <dxgi1_4.h>
#pragma warning(push)
#pragma warning(disable:4265)
#define sealed final 
#include <wrl.h>
#undef sealed
#pragma warning(pop)
#include "Windows/HideWindowsPlatformAtomics.h"
#include "Windows/HideWindowsPlatformTypes.h"

using namespace Microsoft::WRL;

DXGI_ADAPTER_DESC1 GetDeviceAdapterDescriptor(ID3D12Device* device)
{
    ComPtr<IDXGIFactory4> dxgiFactory;
    ComPtr<IDXGIAdapter1> dxgiAdapter;
    HRESULT hr = CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory));
    if (FAILED(hr))
    {
        throw std::runtime_error("Failed to create DXGI factory.");
    }
    LUID luid = device->GetAdapterLuid();
    hr = dxgiFactory->EnumAdapterByLuid(luid, IID_PPV_ARGS(dxgiAdapter.ReleaseAndGetAddressOf()));
    if (FAILED(hr))
    {
        throw std::runtime_error("Cannot enumerate graphics adapter");
    }
    DXGI_ADAPTER_DESC1 adapterDesc;
    hr = dxgiAdapter->GetDesc1(&adapterDesc);
    if (FAILED(hr))
    {
        throw std::runtime_error("Cannot get adapter descriptor");
    }
    return adapterDesc;
}

unsigned int GetDeviceVendorId(ID3D12Device* device)
{
    auto adapterDesc = GetDeviceAdapterDescriptor(device);
    return adapterDesc.VendorId;
}

const TCHAR* GetDeviceVendorName(ID3D12Device* device)
{
    unsigned int VendorId = GetDeviceVendorId(device);
    const TCHAR* VendorName = TEXT("Unknown");
    switch (VendorId)
    {
        case 0x8086:
            VendorName = TEXT("Intel");
            break;
        case 0x1002:
            VendorName = TEXT("AMD");
            break;
        case 0x10DE:
            VendorName = TEXT("NVidia");
            break;
        default:
            break;
    }
    return VendorName;
}
