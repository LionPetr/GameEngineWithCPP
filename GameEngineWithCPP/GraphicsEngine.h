#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include "Prerequisites.h"
#include "RenderSystem.h"
#include "TextureManager.h"


class GraphicsEngine
{
private:
	//initialize directx 11 and graphics engine 
	GraphicsEngine();
	//release graphics engine at the end of the program
	~GraphicsEngine();

public:
	RenderSystem* getRenderSystem();
	TextureManager* getTextureManager();
	static GraphicsEngine* get();
	static void create();
	static void release();
private:
	RenderSystem* m_render_system = nullptr;
	TextureManager* m_tex_manager = nullptr;
	static GraphicsEngine* m_engine;
};

