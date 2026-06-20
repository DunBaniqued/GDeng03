#pragma once
#include <vector>
#include "../GameEngine/VertxBuffer/VertxBuffer.h"
#include "../GameEngine/GraphicsEngine/VertexShader/VertexShader.h"
#include "../GameEngine/GraphicsEngine/PixelShader/PixelShader.h"
#include "AppWindow.h"

struct vec3;
struct vertex;

class Quad
{
public:
	Quad(vertex upperRight, vertex upperLeft, vertex lowerRight, vertex lowerLeft);

	VertxBuffer* m_vb;
	VertexShader* m_vs;
	PixelShader* m_ps;
};

