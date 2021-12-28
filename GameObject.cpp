//#include "GameObject.h"
//
//GameObject::GameObject(/*ID3D11DeviceContext* context, IDXGISwapChain* swapChain*/)
//	//: g_pImmediateContext{ context }, g_pSwapChain{ swapChain }
//{
//	m_translateX = m_translateY = m_translateZ = 0.0f;
//}
//
//void GameObject::RenderFrame()
//{
//	// Clear the back buffer - choose a colour you like
//	float rgba_clear_colour[4] = { 0.1f, 0.2f, 0.6f, 1.0f };
//	g_pImmediateContext->ClearRenderTargetView(g_pBackBufferRTView, rgba_clear_colour);
//
//	// RENDER HERE
//
//	// Display what has just been rendered
//	g_pSwapChain->Present(0, 0);
//}
//
//void GameObject::Shutdown()
//{
//}
