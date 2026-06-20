#include "Quad.h"

Quad::Quad(vertex upperRight, vertex upperLeft, vertex lowerRight, vertex lowerLeft)
{
	vertex list[] = {
		// x, y, z	
		lowerLeft,
		upperLeft,
		lowerRight,
		upperRight
	};

	m_vb = GraphicsEngine::get()->createVertexBuffer();
	UINT size_list = ARRAYSIZE(list);

	void* shader_byte_code = nullptr;
	size_t size_shader = 0;

	GraphicsEngine::get()->compileVertexShader(L"App/VertexShader.hlsl", "vsmain", &shader_byte_code, &size_shader, __FILE__);

	m_vs = GraphicsEngine::get()->createVertexShader(shader_byte_code, size_shader);
	m_vb->load(list, sizeof(vertex), size_list, shader_byte_code, size_shader);

	GraphicsEngine::get()->releaseCompiledShader();


	GraphicsEngine::get()->compilePixelShader(L"App/PixelShader.hlsl", "psmain", &shader_byte_code, &size_shader, __FILE__);
	m_ps = GraphicsEngine::get()->createPixelShader(shader_byte_code, size_shader);

	GraphicsEngine::get()->releaseCompiledShader();
}
