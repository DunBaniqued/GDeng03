#include "AppWindow.h"

void AppWindow::onCreate()
{
	GraphicsEngine::get()->init();
	m_swap_chain=GraphicsEngine::get()->createSwapChain();

	RECT rc = this->getClientWindowRect();
	m_swap_chain->init(this->m_hwnd, rc.right - rc.left, rc.bottom - rc.top);

	Quad* q = new Quad(
		{ 0.6f, 0.2f, 0.0f },
		{ 0.3f, 0.2f, 0.0f },
		{ 0.6f, -0.2f, 0.0f },
		{ 0.3f, -0.2f, 0.0f }
	);

	v_vb.push_back(q->m_vb);
	v_vs.push_back(q->m_vs);
	v_ps.push_back(q->m_ps);

	q = new Quad(
		{ 0.2f, 0.2f, 0.0f },
		{ -0.1f, 0.2f, 0.0f },
		{ 0.2f, -0.2f, 0.0f },
		{ -0.1f, -0.2f, 0.0f }
	);

	v_vb.push_back(q->m_vb);
	v_vs.push_back(q->m_vs);
	v_ps.push_back(q->m_ps);

	q = new Quad(
		{ -0.2f, 0.2f, 0.0f },
		{ -0.5f, 0.2f, 0.0f },
		{ -0.2f, -0.2f, 0.0f },
		{ -0.5f, -0.2f, 0.0f }
	);

	v_vb.push_back(q->m_vb);
	v_vs.push_back(q->m_vs);
	v_ps.push_back(q->m_ps);
}

void AppWindow::onUpdate()
{
	GraphicsEngine::get()->getImmediateDeviceContext()->clearRenderTargetColor(this->m_swap_chain,0,0.3f,0.4f,1);

	RECT rc = this->getClientWindowRect();
	GraphicsEngine::get()->getImmediateDeviceContext()->setViewportSize(rc.right - rc.left, rc.bottom - rc.top);


	for (size_t i = 0; i < v_vb.size(); ++i) {
		GraphicsEngine::get()->getImmediateDeviceContext()->setVertexShader(v_vs[i]);
		GraphicsEngine::get()->getImmediateDeviceContext()->setPixelShader(v_ps[i]);
		GraphicsEngine::get()->getImmediateDeviceContext()->setVertexBuffer(v_vb[i]);
		GraphicsEngine::get()->getImmediateDeviceContext()->drawTriangleStrip(v_vb[i]->getSizeVertexList(), 0);
	}

	m_swap_chain->present(true);
}

void AppWindow::onDestory()
{
	Window::onDestory();
	m_vb->release();
	m_swap_chain->release();
	m_vs->release();
	m_ps->release();
	GraphicsEngine::get()->release();
}
