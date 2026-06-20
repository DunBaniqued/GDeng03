#pragma once
#include "../GameEngine/WindowingSystem/Window.h"
#include "../GameEngine/GraphicsEngine/GraphicsEngine.h"
#include "../GameEngine/GraphicsEngine/SwapChainz/SwapChainz.h"
#include "../GameEngine/GraphicsEngine/DeviceContext/DeviceContext.h"
#include "../GameEngine/VertxBuffer/VertxBuffer.h"
#include "../GameEngine/GraphicsEngine/VertexShader/VertexShader.h"
#include "../GameEngine/GraphicsEngine/PixelShader/PixelShader.h"
#include <vector>;
#include "Quad.h"

struct vec3 {
	float x, y, z;
};

struct vertex {
	vec3 position;
};

class AppWindow: public Window
{
public:
	// Inherited via Window
	void onCreate() override;
	void onUpdate() override;
	void onDestory() override;

private:
	SwapChainz* m_swap_chain;
	VertxBuffer* m_vb;
	VertexShader* m_vs;
	PixelShader* m_ps;

	std::vector<VertxBuffer*> v_vb;
	std::vector<VertexShader*> v_vs;
	std::vector<PixelShader*> v_ps;
};

