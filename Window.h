#pragma once
#include <windows.h>

class Window
{
private:
	HINSTANCE m_hInst;
	int m_nCmdShow;
	HWND m_hWnd;

	char m_ProjectTitle[100] = "AE2 Project\0";

public:
	Window(HINSTANCE hInstance, int nCmdShow);
	HRESULT InitialiseWindow();
	HWND GetHandler() { return m_hWnd; }

};

