#include "Device.h"

Device::Device(HWND hWnd)
	: m_hWnd{ hWnd }
{
}

HRESULT Device::InitialiseD3D()
{
	HRESULT hr = S_OK;

	RECT rc;
	GetClientRect(m_hWnd, &rc); //m_hWnd
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
	sd.OutputWindow = m_hWnd; //m_hWnd
	sd.SampleDesc.Count = 1;
	sd.SampleDesc.Quality = 0;
	sd.Windowed = true;

	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriversTypes; driverTypeIndex++)
	{
		m_driverType = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain(NULL, m_driverType, NULL, CreateDeviceFlags, featureLevel, numFeatureLevels,
			D3D11_SDK_VERSION, &sd, &m_pSwapChain, &m_pD3DDevice, &m_featureLevel, &m_pImmediateContext);

		if (FAILED(hr)) return hr;
		break;
	}


	// Get pointer to back buffer texture
	ID3D11Texture2D* pBackBufferTexture;
	hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBufferTexture);

	if (FAILED(hr)) return hr;

	// use the back buffer texture pointer to creaete the render target view
	hr = m_pD3DDevice->CreateRenderTargetView(pBackBufferTexture, NULL, &g_pBackBufferRTView);

	pBackBufferTexture->Release();

	if (FAILED(hr)) return hr;

	// Set the render target view
	m_pImmediateContext->OMSetRenderTargets(1, &g_pBackBufferRTView, NULL);

	// Set the viewport
	D3D11_VIEWPORT	viewport;

	viewport.TopLeftX = 0;
	viewport.TopLeftY = 0;
	viewport.Width = (FLOAT)width;
	viewport.Height = (FLOAT)height;
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;

	m_pImmediateContext->RSSetViewports(1, &viewport);

	return S_OK;
}
