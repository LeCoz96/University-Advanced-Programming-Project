// #include order is important
#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

#include "InitialSetUp.h"
#include "Device.h"
#include "Graphics.h"
#include "GameObject.h"

//static ID3D11Device* g_pD3DDevice = NULL;
//static ID3D11DeviceContext* g_pImmediateContext = NULL;
//static IDXGISwapChain* g_pSwapChain = NULL;

InitialSetUp* m_pSetUp;
Device* m_pDevice;
Graphics* m_pGraphics;
GameObject* m_pObj;

// Entry point to the program. Initialise everything and goes into a message processing loop. Idle time is used to render the scene
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	m_pSetUp = new InitialSetUp();
	m_pDevice = new Device(/*g_pD3DDevice, g_pImmediateContext, g_pSwapChain*/);
	m_pGraphics = new Graphics();
	m_pObj = new GameObject(/*g_pImmediateContext, g_pSwapChain*/);

	if (FAILED(m_pSetUp->InitialiseWindow(hInstance, nCmdShow)))
	{
		DXTRACE_MSG("Failed to create Window");
		return 0;
	}

	if (FAILED(m_pDevice->InitialiseD3D()))
	{
		DXTRACE_MSG("Failed to create Device");
		return 0;
	}

	if (FAILED(m_pGraphics->InitialiseGraphics()))
	{
		DXTRACE_MSG("Failed to create Graphics");
		return 0;
	}

	// Main message loop
	MSG msg = { 0 };

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			m_pObj->RenderFrame();
		}
	}

	return (int)msg.wParam;
}

