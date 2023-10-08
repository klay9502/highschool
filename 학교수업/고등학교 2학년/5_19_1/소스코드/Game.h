#ifndef __CLASS_GAME_H__
#define __CLASS_GAME_H__

#include "MainHeader.h"

class CGame
{
private:
	int m_Window_Width;
	int m_Window_Height;
	// Windows
	HINSTANCE m_hInst;
	HWND m_hWnd;
	// DirectX
	LPDIRECT3D9 m_pD3D;
	LPDIRECT3DDEVICE9 m_pd3dDevice;
	LPD3DXSPRITE m_pd3dSprite;
	LPDIRECT3DTEXTURE9 m_Textrue[256];
public:
	CGame();
	~CGame();

	VOID GameInit(void);
	VOID InitWindow(void);
	HRESULT InitTexture(void);
	HRESULT InitDirectX(void);

	VOID GameLoop(void);
	VOID Run(void);
	VOID PreRender(void);
	INT Render(void);
	VOID PostRender(void);

	VOID GameRelease(void);

};
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif __CLASS_GAME_H__