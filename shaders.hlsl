cbuffer CBuffer0
{
	matrix WVPMatrix; // 64 bytes
	float red_fraction; // 4 bytes
	float scale;		// 4 bytes
	float2 packing; // 2*4 bytes = 8 bytes;
}

struct VOut
{
	float4 position : SV_POSITION;
	float4 color : COLOR; // Not the spelling of theis and all instances below
};

VOut VShader(float4 position : POSITION, float4 color : COLOR)
{
	VOut output;

	output.position = mul(WVPMatrix, position);
	output.color = color;

	return output;
}

float4 PShader(float4 position : SV_POSITION, float4 color : COLOR) : SV_TARGET
{
	return color;
}