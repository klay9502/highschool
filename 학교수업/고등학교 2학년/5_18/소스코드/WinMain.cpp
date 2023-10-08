#include <windows.h>
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#define WIDTH	1024
#define HEIGHT	768

LPDIRECT3D9 g_pD3D;
LPDIRECT3DDEVICE9 g_pd3dDevice;
LPDIRECT3DVERTEXBUFFER9 g_pVB; // 정점을 저장하는 그래픽카드 메모리공간 할당받는 변수
LPDIRECT3DTEXTURE9 g_pTexture; // 3D에서 사용할 이미지(텍스쳐)

struct CUSTOMVERTEX
{
	D3DXVECTOR3 pos; // 정점 위치
	float tu, tv;	// 텍스쳐 좌표
};
#define MYFVF (D3DFVF_XYZ|D3DFVF_TEX1)

BOOL g_bIsFullScreen = false;

HRESULT InitD3D(HWND hWnd);
HRESULT InitVB(void);
VOID Run(LPDIRECT3DDEVICE9 pd3dDevice);
VOID Cleanup(void);
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
	HWND hWnd;
	WNDCLASSEX wcex;

	HINSTANCE hInstance = GetModuleHandle(NULL);

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hCursor = LoadCursor(0, IDC_ARROW);
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);
	wcex.lpfnWndProc = WndProc;
	wcex.lpszClassName = "MyWindowClass";
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClassEx(&wcex);

	hWnd = CreateWindow("MyWindowClass", "MyWindowName", WS_OVERLAPPEDWINDOW, 0, 0, WIDTH, HEIGHT, NULL, NULL, hInstance, NULL);

	if (SUCCEEDED(InitD3D(hWnd)))
	{
		InitVB();	// 정점 세팅
		ShowWindow(hWnd, nShowCmd);
		UpdateWindow(hWnd);

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
				Run(g_pd3dDevice);
			}
		}
	}

	return 0;
}

HRESULT InitD3D(HWND hWnd)
{
	if ((g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		return E_FAIL;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = !g_bIsFullScreen;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferWidth = WIDTH;
	d3dpp.BackBufferHeight = HEIGHT;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice)))
	{
		return E_FAIL;
	}

	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	g_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	return S_OK;
}

HRESULT PreRender(LPDIRECT3DDEVICE9 pd3dDevice)
{
	pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);

	return SUCCEEDED(pd3dDevice->BeginScene());
}

VOID Render(LPDIRECT3DDEVICE9 pd3dDevice)
{
	g_pd3dDevice->SetTexture(0, g_pTexture);
	g_pd3dDevice->SetStreamSource(0, g_pVB, 0, sizeof(CUSTOMVERTEX));
	g_pd3dDevice->SetFVF(MYFVF);
	g_pd3dDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 4);
}

VOID PostRender(LPDIRECT3DDEVICE9 pd3dDevice)
{
	pd3dDevice->EndScene();
	pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

VOID Run(LPDIRECT3DDEVICE9 pd3dDevice)
{
	PreRender(pd3dDevice);
	Render(pd3dDevice);
	PostRender(pd3dDevice);
}

VOID Cleanup(void)
{
	if (g_pd3dDevice != NULL)
	{
		g_pd3dDevice->Release();
	}
	
	if (g_pD3D != NULL)
	{
		g_pD3D->Release();
	}
}

HRESULT InitVB(void)
{
	D3DXCreateTextureFromFile(g_pd3dDevice, "Image.jpg", &g_pTexture);

	// 그래픽카드  메모리 할당
	g_pd3dDevice->CreateVertexBuffer(6 * sizeof(CUSTOMVERTEX), 0, MYFVF, D3DPOOL_DEFAULT, &g_pVB, NULL);

	CUSTOMVERTEX* pV;
	g_pVB->Lock(0, 0, (void**)&pV, 0);
	{
		{
			pV[0].pos = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
			pV[0].tu = -1.0f;	pV[0].tv = 1.0f;

			pV[1].pos = D3DXVECTOR3(-1.0f, 1.0f, 0.0f);
			pV[1].tu = -1.0f;	pV[1].tv = 0.0f;

			pV[2].pos = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
			pV[2].tu = 0.0f;	pV[2].tv = 0.0f;
		}
		{
			pV[3].pos = D3DXVECTOR3(1.0f, -1.0f, 0.0f);
			pV[3].tu = 0.0f;	pV[3].tv = 1.0f;

			pV[4].pos = D3DXVECTOR3(-1.0f, -1.0f, 0.0f);
			pV[4].tu = -1.0f;	pV[4].tv = 1.0f;

			pV[5].pos = D3DXVECTOR3(1.0f, 1.0f, 0.0f);
			pV[5].tu = 0.0f;	pV[5].tv = 0.0f;
		}
	}
	g_pVB->Unlock();

	return S_OK;
}