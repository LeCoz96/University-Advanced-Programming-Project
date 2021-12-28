#include "Initialise.h"

Initialise::Initialise(HINSTANCE hInstance, int nCmdShow)
	: m_hInstance{ hInstance }, m_nCmdShow{ nCmdShow }
{
	m_pWindow = new Window(m_hInstance, m_nCmdShow);
	m_pDevice = new Device(m_pWindow->GetHandler());
	m_pGraphics = new Graphics(m_pDevice->GetDevice(), m_pDevice->GetContext());
}

bool Initialise::InitialiseGame()
{
	if (FAILED(m_pWindow->InitialiseWindow()))
	{
		DXTRACE_MSG("Failed to create Window");
		return false;
	}

	if (FAILED(m_pDevice->InitialiseD3D()))
	{
		DXTRACE_MSG("Failed to create Device");
		return false;
	}

	if (FAILED(m_pGraphics->InitialiseGraphics()))
	{
		DXTRACE_MSG("Failed to create Grapics");
		return false;
	}

	return true;
}
