#pragma once
#include <d3d11.h>
#include "Prerequisites.h"


class VertexShader
{
public:
	VertexShader(const void* shader_byte_code, size_t bye_code_size, RenderSystem* m_system );	
	~VertexShader();

private:
	ID3D11VertexShader* m_vs;
	RenderSystem* m_system = nullptr;

	friend class RenderSystem;
	friend class DeviceContext;
};

