#pragma once
// #include order is important
#define	_XM_NO_INTRINSICS_
#define	XM_NO_ALIGNMENT
#include <DirectXMath.h>

#include <d3d11.h>
#include <dxgi.h>
#include <d3dx11.h>
#include <windows.h>
#include <dxerr.h>

#include "StaticInfo.h"

using namespace DirectX;

// Define vertex structure
struct POS_COL_VERTEX
{
	XMFLOAT3 pos;
	XMFLOAT4 col;
};

struct CONSTANT_BUFFER0
{
	XMMATRIX WorldViewProjection;	// 64 bytes (4 floating variables x 4 (x, y, z, w) = 16 floats x 4 (4 rows make a world matrix)
	float RedAmount;	// 4 bytes
	float scale;		// 4 bytes
	XMFLOAT2 packing_bytes_scale;	// 8 extra bytes
	// Total 80 bytes = multiple of 16
};

class Graphics
{
private:
	ID3D11Buffer* g_pVertexBuffer;
	ID3D11VertexShader* g_pVertexShader;
	ID3D11PixelShader* g_pPixelShader;
	ID3D11InputLayout* g_pInputLayout;

	ID3D11Buffer* g_pConstantBuffer0;

	CONSTANT_BUFFER0 g_cb0_values;

public:
	Graphics();
	HRESULT InitialiseGraphics();

};

