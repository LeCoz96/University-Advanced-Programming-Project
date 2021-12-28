#pragma once
#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

#include "Window.h"
#include "Device.h"
#include "Graphics.h"

class Initialise
{
private:
	Window* m_pWindow = NULL;
	Device* m_pDevice = NULL;
	Graphics* m_pGraphics = NULL;

	HINSTANCE m_hInstance;
	int m_nCmdShow;

public:
	Initialise(HINSTANCE hInstance, int nCmdShow);
	bool InitialiseGame();

};

