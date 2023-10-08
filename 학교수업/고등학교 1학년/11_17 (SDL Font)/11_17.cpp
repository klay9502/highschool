// 11_17.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

void OutputText(SDL_Renderer* pRenderer,	// �׸��� ���� ��µ� ȭ��
				char* fontName,				// ��Ʈ ����
				int x, int y,				// ���ڰ� ��µ� ��ġ ��ǥ
				SDL_Color fontColor,		// ���� ��
				int fontSize,				// ���� ũ��
				char* strbuffer)			// ���� ����
{
	SDL_Texture* pTexture;		// ��¿� �ؽ���

	TTF_Font* pFont;	// ��Ʈ ������ ����
	pFont = TTF_OpenFont(fontName, fontSize);	// ��Ʈ ����
	
	SDL_Surface* pSufText;		// ���� ��� �̹����� ���� ������ ����

	pSufText = TTF_RenderText_Solid(pFont, strbuffer, fontColor);	// ���� => �̹��� ��ȯ
	pTexture = SDL_CreateTextureFromSurface(pRenderer, pSufText);	// Surface => Texture ��ȯ

	SDL_Rect Rect = {x, y, pSufText->w, pSufText->h};	// ��� ��ġ�� ũ�� ����
	SDL_RenderCopy(pRenderer, pTexture, NULL, &Rect);	// �ĸ� ���ۿ� ���

	SDL_FreeSurface(pSufText);	// Surface �̹��� ����
	SDL_DestroyTexture(pTexture);	// Texture �̹��� ����
	TTF_CloseFont(pFont);	// ��Ʈ ����
}

#define VA_MAX 1024

void OutputTexts(SDL_Renderer* pRenderer,
				 char* fontName,		
				 int x, int y,			
				 SDL_Color fontColor,	
				 int fontSize,			
				 char* format, ...)	// ... ���� ���� ����
{
	static char strBuffer[VA_MAX];
	va_list v1;
	va_start(v1, format);
	_vsnprintf(strBuffer, VA_MAX, format, v1);
	va_end(v1);

	OutputText(pRenderer, fontName, x, y, fontColor, fontSize, strBuffer);
}

void OutputHanText(SDL_Renderer* pRenderer,	// �׸��� ���� ��µ� ȭ��
				char* fontName,				// ��Ʈ ����
				int x, int y,				// ���ڰ� ��µ� ��ġ ��ǥ
				SDL_Color fontColor,		// ���� ��
				int fontSize,				// ���� ũ��
				char* strbuffer)			// ���� ����
{
	SDL_Texture* pTexture;		// ��¿� �ؽ���

	TTF_Font* pFont;	// ��Ʈ ������ ����
	pFont = TTF_OpenFont(fontName, fontSize);	// ��Ʈ ����

	SDL_Surface* pSufText;		// ���� ��� �̹����� ���� ������ ����

	Uint16 destBuffer[VA_MAX];
	han2unicode(strbuffer, destBuffer);

	pSufText = TTF_RenderUNICODE_Solid(pFont, destBuffer, fontColor);	// ���� => �̹��� ��ȯ
	pTexture = SDL_CreateTextureFromSurface(pRenderer, pSufText);	// Surface => Texture ��ȯ

	SDL_Rect Rect = {x, y, pSufText->w, pSufText->h};	// ��� ��ġ�� ũ�� ����
	SDL_RenderCopy(pRenderer, pTexture, NULL, &Rect);	// �ĸ� ���ۿ� ���

	SDL_FreeSurface(pSufText);	// Surface �̹��� ����
	SDL_DestroyTexture(pTexture);	// Texture �̹��� ����
	TTF_CloseFont(pFont);	// ��Ʈ ����
}

void OutputHanTexts(SDL_Renderer* pRenderer,
				 char* fontName,		
				 int x, int y,			
				 SDL_Color fontColor,	
				 int fontSize,			
				 char* format, ...)
{
	static char strBuffer[VA_MAX];
	va_list v1;
	va_start(v1, format);
	_vsnprintf(strBuffer, VA_MAX, format, v1);
	va_end(v1);

	OutputHanText(pRenderer, fontName, x, y, fontColor, fontSize, strBuffer);
}


int _tmain(int argc, _TCHAR* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	SDL_Window* pWnd = SDL_CreateWindow("TTF", 100, 100, 640, 480, 0);

	SDL_Renderer* pRenderer = SDL_CreateRenderer(pWnd, -1, SDL_RENDERER_ACCELERATED);

	SDL_Surface* pSurface = SDL_GetWindowSurface(pWnd);
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);

	bool bIsQuit = false;
	SDL_Event evnt;
	while(!bIsQuit)
	{
		SDL_PollEvent(&evnt);
		
		if (evnt.type == SDL_KEYDOWN)
		{
			switch(evnt.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				bIsQuit = true;
				break;
			}
		}
		SDL_SetRenderDrawColor(pRenderer, 0xff, 0xff, 0x00, 0xff);
		SDL_RenderClear(pRenderer);

		SDL_Color color = {0, 0, 0};
		OutputTexts(pRenderer, "segoeuib.ttf", 100, 100, color, 20, "AnioneHighSchool");

		OutputHanTexts(pRenderer, "HANSolM.ttf", 100, 120, color, 20, "���ִϿ�����б�");

		SDL_RenderPresent(pRenderer);
	}

	SDL_DestroyTexture(pTexture);
	SDL_FreeSurface(pSurface);
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWnd);
	TTF_Quit();
	SDL_Quit();
	return 0;
}

