#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

class InitialSetUp
{
private:
	HINSTANCE m_hInst;
	HWND m_hWnd;

	char m_ProjectTitle[100] = "AE2 Project\0";

	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	InitialSetUp();
	HRESULT InitialiseWindow(HINSTANCE hInstance, int nCmdShow);

};

