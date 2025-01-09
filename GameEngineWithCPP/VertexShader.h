#pragma once
#include <d3d11.h>


class GraphicsEngine;
class DeviceContext;


class VertexShader
{
public:
	VertexShader();
	bool release();
	
	~VertexShader();

private:
	bool init(const void* shader_byte_code, size_t bye_code_size);

	ID3D11VertexShader* m_vs;

	friend class GraphicsEngine;
	friend class DeviceContext;
};

