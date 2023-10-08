#include "Game.h"

CGame::CGame()
{
	m_Window_Width = 800;
	m_Window_Height = 600;
}

CGame::~CGame()
{
	// empty...
}

VOID CGame::GameInit(void)
{
	InitWindow();
	InitDirectX();
	InitTexture();
}

VOID CGame::InitWindow(void)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = m_hInst;
	wcex.hIcon = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hIconSm = LoadIcon(m_hInst, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hbrBackground = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDI_APPLICATION);
	wcex.lpszClassName = "WindowClass";

	RegisterClassEx(&wcex);

	m_hWnd = CreateWindow("WindowClass", "WindowName", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, m_Window_Width, m_Window_Height, NULL, NULL, m_hInst, NULL);

	if (SUCCEEDED(InitDirectX()))
	{
		ShowWindow(m_hWnd, SW_SHOW);
		UpdateWindow(m_hWnd);
	}
}

HRESULT CGame::InitDirectX(void)
{
	if ((m_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferWidth = m_Window_Width;
	d3dpp.BackBufferHeight = m_Window_Height;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(m_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, m_hWnd, D3DCREATE_MIXED_VERTEXPROCESSING, &d3dpp, &m_pd3dDevice)))
	{
		return E_FAIL;
	}

	m_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	return S_OK;
}

HRESULT CGame::InitTexture(void)
{
	D3DXCreateSprite(m_pd3dDevice, &m_pd3dSprite);

	if (FAILED(D3DXCreateTextureFromFile(m_pd3dDevice, "./Texture/FEZ.png", &m_Textrue[0])))
	{
		MessageBox(NULL, "FEZ.png file could not find", "ERROR!", 0);
		m_Textrue[0] = NULL;
		return E_FAIL;
	}

	if (FAILED(D3DXCreateTextureFromFile(m_pd3dDevice, "./Texture/Block.png", &m_Textrue[1])))
	{
		MessageBox(NULL, "Background.jpg file could not find", "ERROR!", 0);
		m_Textrue[1] = NULL;
		return E_FAIL;
	}

	return S_OK;
}

VOID CGame::GameLoop(void)
{
	MSG msg;

	ZeroMemory(&msg, sizeof(msg));

	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			Run();
		}
	}
}

VOID CGame::Run(void)
{
	PreRender();
	Render();
	PostRender();
}

VOID CGame::PreRender(void)
{
	// empty...
}

INT CGame::Render(void)
{
	if (m_pd3dDevice == NULL)
	{
		return -1;
	}

	m_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(153, 217, 234), 1.0f, 0);

	if (FAILED(m_pd3dDevice->BeginScene()))
		return -1;

	m_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);
	
	// Block Image
	for (int i = 0; i < 8; i++)
	{
		RECT rcBG = { 0, 0, 100, 100 };
		m_pd3dSprite->Draw(m_Textrue[1], &rcBG, NULL, &D3DXVECTOR3(i * 100, 500, 0), D3DXCOLOR(1, 1, 1, 1));
	}

	// FEZ Image
	RECT rcFEZ = { 0, 0, 130, 250 };
	m_pd3dSprite->Draw(m_Textrue[0], &rcFEZ, NULL, &D3DXVECTOR3(100, 250, 0), D3DXCOLOR(1, 1, 1, 1));

	m_pd3dSprite->End();

	m_pd3dDevice->EndScene();

	return m_pd3dDevice->Present(0, 0, 0, 0);
}

VOID CGame::PostRender(void)
{
	// empty...
}

VOID CGame::GameRelease(void)
{
	if (m_pd3dSprite != NULL)
	{
		m_pd3dSprite->Release();
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}