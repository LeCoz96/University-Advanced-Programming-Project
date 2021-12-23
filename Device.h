#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

#include "InitialSetUp.h"
#include "StaticInfo.h"

class Device
{
protected:
	D3D_DRIVER_TYPE	m_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;

	//ID3D11Device* g_pD3DDevice;
	//ID3D11DeviceContext* g_pImmediateContext;
	//IDXGISwapChain* g_pSwapChain;

public:
	Device(/*ID3D11Device* device, ID3D11DeviceContext* context, IDXGISwapChain* swapChain*/);
	HRESULT InitialiseD3D();
	void ShutDown();

};

