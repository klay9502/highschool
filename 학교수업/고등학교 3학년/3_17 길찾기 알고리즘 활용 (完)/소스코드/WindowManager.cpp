#include "stdafx.h"
#include "WindowManager.h"


CWindowManager::CWindowManager(void)
{
	m_ptWindowSize.x	= 1280;
	m_ptWindowSize.y	= 720;
	m_bIsWindowMode		= FALSE;
}

CWindowManager::~CWindowManager(void)
{
	// empty...
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
#if _DEBUG
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
		break;
#endif
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void CWindowManager::Init(void)
{
	InitWindow();
	InitDirectX();
}

void CWindowManager::InitWindow(void)
{
	WNDCLASSEX wcex;

	wcex.cbSize			= sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= m_hInst;
	wcex.hIcon			= LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor		= NULL;
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDI_APPLICATION);
	wcex.lpszClassName	= "WindowClass";
	wcex.hIconSm		= LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_APPLICATION));

	RegisterClassEx(&wcex);

	m_hWnd = CreateWindow("WindowClass", ENGINE_NAME, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, m_ptWindowSize.x, m_ptWindowSize.y, NULL, NULL, m_hInst, NULL);

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);
}

void CWindowManager::InitDirectX(void)
{
	if ((m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
#if _DEBUG
		MessageBox(NULL, "DirectX initialization Failed!\n\nError::m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL", "ERROR", MB_ICONERROR);
#endif
		return;
	}

	D3DPRESENT_PARAMETERS d3dpp;

	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.hDeviceWindow					= m_hWnd;
	d3dpp.Windowed						= !m_bIsWindowMode;
	d3dpp.FullScreen_RefreshRateInHz	= !m_bIsWindowMode ? 0 : 60;
	d3dpp.SwapEffect					= D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferWidth				= m_ptWindowSize.x;
	d3dpp.BackBufferHeight				= m_ptWindowSize.y;
	d3dpp.BackBufferFormat				= D3DFMT_X8R8G8B8;
	d3dpp.EnableAutoDepthStencil		= TRUE;
	d3dpp.AutoDepthStencilFormat		= D3DFMT_D16;
	d3dpp.Flags							= D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL, m_hWnd, D3DCREATE_MIXED_VERTEXPROCESSING,
		&d3dpp, &m_pd3dDevice)))
	{
#if _DEBUG
		MessageBox(NULL, "DirectX initialization Failed!\n\nError::m_pD3D->CreateDevice Failed.", "ERROR", MB_ICONERROR);
#endif
		return;
	}

	D3DXCreateSprite(m_pd3dDevice, &m_pd3dSprite);
}

void CWindowManager::Release(void)
{
	UnregisterClass("WindowClass", m_hInst);
	
	if (m_pd3dSprite != nullptr)
	{
		m_pd3dSprite->Release();
		m_pd3dSprite = nullptr;
	}

	if (m_pd3dDevice != nullptr)
	{
		m_pd3dDevice->Release();
		m_pd3dDevice = nullptr;
	}
	
	if (m_pD3D != nullptr)
	{
		m_pD3D->Release();
		m_pD3D = nullptr;
	}
}
