#pragma once
#include <d3d11.h>

class SwapChain;
class DeviceContext;
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

	SwapChain* createSwapChain();
	//DeviceContext* getImmidiateDeviceContext();
	DeviceContext* getImmidiateDeviceContext();
private:
	DeviceContext* m_imm_device_context;




	ID3D11Device* m_d3d_device;
	D3D_FEATURE_LEVEL m_feature_level;

	IDXGIDevice* m_dxgi_device;
	IDXGIAdapter* m_dxgi_adapter;
	IDXGIFactory* m_dxgi_factory;

	friend class SwapChain;

};

