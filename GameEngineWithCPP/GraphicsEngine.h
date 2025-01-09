#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>

class SwapChain;
class VertexBuffer;
class DeviceContext;
class VertexShader;

class GraphicsEngine
{
public:
	GraphicsEngine();

	//initialize directx 11 and graphics engine 
	bool init();
	//release graphics engine at the end of the program
	bool release();

	~GraphicsEngine();

	static GraphicsEngine* get();

	bool compileVertexShader(const wchar_t* file_name, const char* entry_point_name, void** shader_byte_code, size_t* byte_code_size);
	void releaseCompiledShader();

	bool createShaders();
	bool setShaders();

	SwapChain* createSwapChain();
	//DeviceContext* getImmidiateDeviceContext();
	DeviceContext* getImmidiateDeviceContext();
	VertexBuffer* createVertexBuffer();
	VertexShader* createVertexShader(const void* shader_byte_code, size_t bye_code_size);
private:
	DeviceContext* m_imm_device_context;




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

};

