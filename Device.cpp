#include "Device.h"

Device::Device()
{
	g_pD3DDevice = NULL;
	g_pImmediateContext = NULL;
	g_pSwapChain = NULL;
}

HRESULT Device::InitialiseD3D()
{
	HRESULT hr = S_OK;

	RECT rc;
	GetClientRect(m_hWnd, &rc);
	UINT width = rc.right - rc.left;
	UINT height = rc.bottom - rc.top;

	UINT CreateDeviceFlags = 0;

#ifdef _DEBUG

	CreateDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;

#endif

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE, // Comment out this line if you need to test D3D 11.0 functionality on hardware that doesn't support it
		D3D_DRIVER_TYPE_WARP, // Comment this out also to use reference device
		D3D_DRIVER_TYPE_REFERENCE
	};
	UINT numDriversTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevel[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevel);

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));
	sd.BufferCount = 1;
	sd.BufferDesc.Width = width;
	sd.BufferDesc.Height = height;
	sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	sd.BufferDesc.RefreshRate.Numerator = 60;
	sd.BufferDesc.RefreshRate.Denominator = 1;
	sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	sd.OutputWindow = m_hWnd;
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = true;

	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriversTypes; driverTypeIndex++)
	{
		g_driverType = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain(NULL, g_driverType, NULL, CreateDeviceFlags, featureLevel, numFeatureLevels,
			D3D11_SDK_VERSION, &sd, &g_pSwapChain, &g_pD3DDevice, &g_featureLevel, &g_pImmediateContext);

		if (FAILED(hr)) return hr;
		break;
	}
	return S_OK;
}

void Device::ShutDown()
{
}
