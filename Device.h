#pragma once
#include <d3dx11.h>

#include "Window.h"

class Device
{
private:
	HWND m_hWnd;

	D3D_DRIVER_TYPE	m_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device* m_pD3DDevice = NULL;
	ID3D11DeviceContext* m_pImmediateContext = NULL;
	IDXGISwapChain* m_pSwapChain = NULL;

	ID3D11RenderTargetView* g_pBackBufferRTView = NULL;

public:
	Device(HWND hWnd);
	HRESULT InitialiseD3D();
	ID3D11Device* GetDevice() { return m_pD3DDevice; }
	ID3D11DeviceContext* GetContext() { return m_pImmediateContext; }
	IDXGISwapChain* GetSwapChain() { return m_pSwapChain; }


};

