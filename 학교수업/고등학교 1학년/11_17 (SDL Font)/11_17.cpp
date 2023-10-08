// 11_17.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

void OutputText(SDL_Renderer* pRenderer,	// 그림이 최종 출력될 화면
				char* fontName,				// 폰트 파일
				int x, int y,				// 글자가 출력될 위치 좌표
				SDL_Color fontColor,		// 글자 색
				int fontSize,				// 글자 크기
				char* strbuffer)			// 글자 내용
{
	SDL_Texture* pTexture;		// 출력용 텍스쳐

	TTF_Font* pFont;	// 폰트 포인터 변수
	pFont = TTF_OpenFont(fontName, fontSize);	// 폰트 열기
	
	SDL_Surface* pSufText;		// 글자 출력 이미지를 받을 포인터 변수

	pSufText = TTF_RenderText_Solid(pFont, strbuffer, fontColor);	// 글자 => 이미지 변환
	pTexture = SDL_CreateTextureFromSurface(pRenderer, pSufText);	// Surface => Texture 변환

	SDL_Rect Rect = {x, y, pSufText->w, pSufText->h};	// 출력 위치와 크기 설정
	SDL_RenderCopy(pRenderer, pTexture, NULL, &Rect);	// 후면 버퍼에 출력

	SDL_FreeSurface(pSufText);	// Surface 이미지 해제
	SDL_DestroyTexture(pTexture);	// Texture 이미지 해제
	TTF_CloseFont(pFont);	// 폰트 해제
}

#define VA_MAX 1024

void OutputTexts(SDL_Renderer* pRenderer,
				 char* fontName,		
				 int x, int y,			
				 SDL_Color fontColor,	
				 int fontSize,			
				 char* format, ...)	// ... 연속 변수 문법
{
	static char strBuffer[VA_MAX];
	va_list v1;
	va_start(v1, format);
	_vsnprintf(strBuffer, VA_MAX, format, v1);
	va_end(v1);

	OutputText(pRenderer, fontName, x, y, fontColor, fontSize, strBuffer);
}

void OutputHanText(SDL_Renderer* pRenderer,	// 그림이 최종 출력될 화면
				char* fontName,				// 폰트 파일
				int x, int y,				// 글자가 출력될 위치 좌표
				SDL_Color fontColor,		// 글자 색
				int fontSize,				// 글자 크기
				char* strbuffer)			// 글자 내용
{
	SDL_Texture* pTexture;		// 출력용 텍스쳐

	TTF_Font* pFont;	// 폰트 포인터 변수
	pFont = TTF_OpenFont(fontName, fontSize);	// 폰트 열기

	SDL_Surface* pSufText;		// 글자 출력 이미지를 받을 포인터 변수

	Uint16 destBuffer[VA_MAX];
	han2unicode(strbuffer, destBuffer);

	pSufText = TTF_RenderUNICODE_Solid(pFont, destBuffer, fontColor);	// 글자 => 이미지 변환
	pTexture = SDL_CreateTextureFromSurface(pRenderer, pSufText);	// Surface => Texture 변환

	SDL_Rect Rect = {x, y, pSufText->w, pSufText->h};	// 출력 위치와 크기 설정
	SDL_RenderCopy(pRenderer, pTexture, NULL, &Rect);	// 후면 버퍼에 출력

	SDL_FreeSurface(pSufText);	// Surface 이미지 해제
	SDL_DestroyTexture(pTexture);	// Texture 이미지 해제
	TTF_CloseFont(pFont);	// 폰트 해제
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

		OutputHanTexts(pRenderer, "HANSolM.ttf", 100, 120, color, 20, "울산애니원고등학교");

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

