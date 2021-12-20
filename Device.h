#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

class Device
{
private:
	D3D_DRIVER_TYPE	g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device* g_pD3DDevice;
	ID3D11DeviceContext* g_pImmediateContext;
	IDXGISwapChain* g_pSwapChain;

	HWND m_hWnd;

public:
	Device();
	HRESULT InitialiseD3D();
	void ShutDown();

};

