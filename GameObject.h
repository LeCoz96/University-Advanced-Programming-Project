// #include order is important
#pragma once
#define	_XM_NO_INTRINSICS_
#define	XM_NO_ALIGNMENT
#include <DirectXMath.h>

#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

#include "StaticInfo.h"

using namespace DirectX;

class GameObject
{
protected:
	float m_translateX, m_translateY, m_translateZ;

	XMMATRIX projection, world, view;

	//ID3D11DeviceContext* g_pImmediateContext;
	//IDXGISwapChain* g_pSwapChain;

public:
	GameObject(/*ID3D11DeviceContext* context, IDXGISwapChain* swapChain*/);
	virtual void RenderFrame();
	virtual void Shutdown();

};

