#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include "Prerequisites.h"
#include "RenderSystem.h"


class GraphicsEngine
{
public:
	GraphicsEngine();

	//initialize directx 11 and graphics engine 
	bool init();
	//release graphics engine at the end of the program
	bool release();
	static GraphicsEngine* get();
	~GraphicsEngine();
	RenderSystem* getRenderSystem();


private:
	RenderSystem* m_render_system = nullptr;
};

