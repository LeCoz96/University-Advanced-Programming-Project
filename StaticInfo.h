#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

static HINSTANCE g_hInst;
static HWND g_hWnd;

extern ID3D11Device* g_pD3DDevice = NULL;
extern ID3D11DeviceContext* g_pImmediateContext = NULL;
extern IDXGISwapChain* g_pSwapChain = NULL;

extern ID3D11RenderTargetView* g_pBackBufferRTView = NULL;


