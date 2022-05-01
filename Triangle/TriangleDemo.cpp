#include"TriangleDemo.h"
#include<xnamath.h>

struct VertexPos
{
	XMFLOAT3 pos;
};

TriangleDemo::TriangleDemo() : solidColorVS_(0), solidColorPS_(0), inputLayout_(0), vertexBuffer_(0)
{

}

TriangleDemo::~TriangleDemo()
{

}

bool TriangleDemo::LoadContent()
{
	ID3DBlob* vsBuffer = 0;

	bool compileResult = CompileD3DShader(L"SolidGreenColor.fx", "VS_Main", "vs_4_0", &vsBuffer);

	if (compileResult == false)
	{
		MessageBox(0, L"Error loading vertex shader!", L"Compile Error", MB_OK);
		return false;
	}

	HRESULT d3dResult;

	d3dResult = d3dDevice_->CreateVertexShader(vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), 0, &solidColorVS_);

	if (FAILED(d3dResult))
	{
		if (vsBuffer)
			vsBuffer->Release();

		return false;
	}

	D3D11_INPUT_ELEMENT_DESC solidColorLayout[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0}
	};

	unsigned int totalLayoutElements = ARRAYSIZE(solidColorLayout);

	d3dResult = d3dDevice_->CreateInputLayout(solidColorLayout, totalLayoutElements, vsBuffer->GetBufferPointer(), vsBuffer->GetBufferSize(), &inputLayout_);

	vsBuffer->Release();

	if (FAILED(d3dResult))
	{
		return false;
	}

	ID3DBlob* psBuffer = 0;

	compileResult = CompileD3DShader(L"SolidGreenColor.fx", "PS_Main", "ps_4_0", &psBuffer);

	if (compileResult == false)
	{
		MessageBox(0, L"Error loading pixel shader!", L"Compile Error", MB_OK);
		return false;
	}

	d3dResult = d3dDevice_->CreatePixelShader(psBuffer->GetBufferPointer(), psBuffer->GetBufferSize(), 0, &solidColorPS_);

	psBuffer->Release();

	if (FAILED(d3dResult))
	{
		return false;
	}

	VertexPos vertices[] =
	{
		XMFLOAT3(0.5f,  0.5f, 0.5f),
		XMFLOAT3(0.5f, -0.5f, 0.5f),
		XMFLOAT3(-0.5f, -0.5f, 0.5f)
	};

	D3D11_BUFFER_DESC vertexDesc;
	ZeroMemory(&vertexDesc, sizeof(vertexDesc));
	vertexDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexDesc.ByteWidth = sizeof(VertexPos) * 3;

	D3D11_SUBRESOURCE_DATA resourceData;
	ZeroMemory(&resourceData, sizeof(resourceData));
	resourceData.pSysMem = vertices;

	d3dResult = d3dDevice_->CreateBuffer(&vertexDesc, &resourceData, &vertexBuffer_);

	if (FAILED(d3dResult))
	{
		return false;
	}

	return true;
}

void TriangleDemo::UnloadContent()
{
}

void TriangleDemo::Update(float dt)
{
}

void TriangleDemo::Render()
{
}
