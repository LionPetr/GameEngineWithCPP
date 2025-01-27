#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include "Prerequisites.h"


class RenderSystem
{
public:
	//initialize directx 11 and graphics engine 
	RenderSystem();
	//release graphics engine at the end of the program
	~RenderSystem();


	bool compileVertexShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);
	bool compilePixelShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);
	void releaseCompiledShader();

	SwapChainPtr createSwapChain(HWND hwnd, UINT width, UINT height);
	DeviceContextPtr getImmidiateDeviceContext();
	VertexBufferPtr createVertexBuffer(void* list_vertices, UINT size_vertex, UINT size_list, void* shader_byte_code, UINT size_byte_shader);
	IndexBufferPtr createIndexBuffer(void* list_indices, UINT size_list);
	VertexShaderPtr createVertexShader(const void* shader_byte_code, size_t bye_code_size);
	PixelShaderPtr createPixelShader(const void* shader_byte_code, size_t bye_code_size);
	ConstantBufferPtr createConstantBuffer(void* buffer, UINT size_buffer);
private:
	DeviceContextPtr m_imm_device_context;

	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;

	IDXGIDevice* m_dxgi_device;
	IDXGIAdapter* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;
	ID3D11DeviceContext* m_imm_context;

	ID3DBlob* m_blob = nullptr;

	ID3DBlob* m_vsblob = nullptr;
	ID3DBlob* m_psblob = nullptr;
	ID3D11VertexShader* m_vs = nullptr;
	ID3D11PixelShader* m_ps = nullptr;

	friend class VertexShader;
	friend class SwapChain;
	friend class VertexBuffer;
	friend class PixelShader;
	friend class ConstantBuffer;
	friend class IndexBuffer;
	friend class Texture;
};

