#include "Window.h"

Window::Window(HINSTANCE hInstance, int nCmdShow)
	: m_hInst{ hInstance }, m_nCmdShow{ nCmdShow }
{
}

HRESULT Window::InitialiseWindow()
{
	// Give your app your own name
	char Name[100] = "Hello World \0";

	// Register Class
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.hInstance = m_hInst; //m_hInst
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	//  wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1); Needed for non-D3D apps
	wcex.lpszClassName = Name;

	if (!RegisterClassEx(&wcex)) return E_FAIL;

	// Create Window
	//m_hInst = hInstance;
	RECT rc = { 0, 0, 640, 480 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);
	m_hWnd = CreateWindow(Name, m_ProjectTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left,
		rc.bottom - rc.top, NULL, NULL, m_hInst, NULL); //m_hInst

	if (!m_hWnd) return E_FAIL;

	ShowWindow(m_hWnd, m_nCmdShow); //m_nCmdShow

	return S_OK;
}
