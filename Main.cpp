// #include order is important
#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

#include "Initialise.h"

Initialise* m_pSetUp;


// Entry point to the program. Initialise everything and goes into a message processing loop. Idle time is used to render the scene
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	m_pSetUp = new Initialise(hInstance, nCmdShow);

	if (FAILED(m_pSetUp->InitialiseGame()))
	{
		DXTRACE_MSG("Failed to create Game");
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
			//m_pObj->RenderFrame();
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE)
		{
			DestroyWindow(hWnd);
			break;
		}

		//if (wParam == 'W')
		//{
		//	m_pPlayer->Forward();
		//}
		//if (wParam == 'S')
		//{
		//	m_pPlayer->Backward();
		//}
		//if (wParam == 'A')
		//{
		//	m_pPlayer->Left();
		//}
		//if (wParam == 'D')
		//{
		//	m_pPlayer->Right();
		//}

		//if (wParam == VK_UP)
		//{
		//	// player look up
		//}
		//if (wParam == VK_DOWN)
		//{
		//	// player look down
		//}
		//if (wParam == VK_LEFT)
		//{
		//	// player look left
		//}
		//if (wParam == VK_RIGHT)
		//{
		//	// player look right
		//}

		return 0;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}
