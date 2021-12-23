#include "InitialSetUp.h"
#include "StaticInfo.h"

InitialSetUp::InitialSetUp()
{
	m_pPlayer = new Player();
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

		if (wParam == 'W')
		{
			m_pPlayer->Forward();
		}
		if (wParam == 'S')
		{
			m_pPlayer->Backward();
		}
		if (wParam == 'A')
		{
			m_pPlayer->Left();
		}
		if (wParam == 'D')
		{
			m_pPlayer->Right();
		}

		if (wParam == VK_UP)
		{
			// player look up
		}
		if (wParam == VK_DOWN)
		{
			// player look down
		}
		if (wParam == VK_LEFT)
		{
			// player look left
		}
		if (wParam == VK_RIGHT)
		{
			// player look right
		}

		return 0;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

HRESULT InitialSetUp::InitialiseWindow(HINSTANCE hInstance, int nCmdShow)
{
	// Give your app your own name
	char Name[100] = "Hello World \0";

	// Register Class
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = hInstance;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	//  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); Needed for non-D3D apps
	wcex.lpszClassName = Name;

	if (!RegisterClassEx(&wcex)) return E_FAIL;

	// Create Window
	g_hInst = hInstance;
	RECT rc = { 0, 0, 640, 480 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	g_hWnd = CreateWindow(Name, m_ProjectTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left,
		rc.bottom - rc.top, NULL, NULL, hInstance, NULL);

	if (!g_hWnd) return E_FAIL;

	ShowWindow(g_hWnd, nCmdShow);

	return S_OK;
}


