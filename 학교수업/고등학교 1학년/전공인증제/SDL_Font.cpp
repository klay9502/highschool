#include "stdafx.h"

void OutputText( SDL_Renderer* pRenderer,	//그림이 최종 출력될 화면
	             char* fontName,			//폰트 파일
				 int x, int y,				//글자가 출력될 위치 좌표
				 SDL_Color fontColor,		//글자 색
				 int	fontSize,			//글자 크기
				 char* strbuffer )			//글자 내용
{
	SDL_Texture* pTexture;	//출력용 텍스쳐

	TTF_Font*	pFont;		//폰트 포인터 변수
	pFont = TTF_OpenFont( fontName, fontSize ); //폰트 열기
	
	SDL_Surface* pSufText;	//글자 출력 이미지를 받을 포인터 변수

	pSufText = TTF_RenderText_Solid( pFont, strbuffer, fontColor );//글자==>이미지 변환
	pTexture = SDL_CreateTextureFromSurface( pRenderer, pSufText );//Surface==>Texture 변환

	SDL_Rect Rect = { x, y, pSufText->w, pSufText->h }; //출력 위치와 크기 설정
	SDL_RenderCopy( pRenderer, pTexture, NULL, &Rect); //후면 버퍼에 출력

	SDL_FreeSurface( pSufText ); //Surface 이미지 해제
	SDL_DestroyTexture( pTexture ); //Texture 이미지 해제
	TTF_CloseFont( pFont ); //폰트 해제
}

#define VA_MAX	1024

void OutputTexts( SDL_Renderer* pRenderer, 
	             char* fontName,
				 int x, int y,
				 SDL_Color fontColor,
				 int	fontSize,
				 char* format, ... ) //... 연속 변수 문법
{
	static char strBuffer[VA_MAX];  //글자를 변환해서 넣어둘 변수
	va_list	vl;                     //실질 메모리 변수 //list자료구조 분석 시작
	va_start( vl, format );         //format 형태를 분석
	_vsnprintf( strBuffer, VA_MAX, format, vl ); //strBuffer로 format을 변환
	va_end( vl ); //list 자료구조분석 끝

	OutputText( pRenderer, fontName, x, y, fontColor, fontSize, strBuffer );
}

void OutputHanText(	 SDL_Renderer* pRenderer, 
					 char* fontName,
					 int x, int y,
					 SDL_Color fontColor,
					 int	fontSize,
					 char* strbuffer )
{
	SDL_Texture* pTexture;

	TTF_Font*	pFont;
	pFont = TTF_OpenFont( fontName, fontSize );
	SDL_Surface* pSufText;

	Uint16 destBuffer[VA_MAX];
	han2unicode( strbuffer, destBuffer );

	pSufText = TTF_RenderUNICODE_Solid( pFont, destBuffer, fontColor );
	pTexture = SDL_CreateTextureFromSurface( pRenderer, pSufText );

	SDL_Rect Rect = { x, y, pSufText->w, pSufText->h };
	SDL_RenderCopy( pRenderer, pTexture, NULL, &Rect);

	SDL_FreeSurface( pSufText );
	TTF_CloseFont( pFont );
}

void OutputHanTexts( SDL_Renderer* pRenderer, 
	             char* fontName,
				 int x, int y,
				 SDL_Color fontColor,
				 int	fontSize,
				 char* format, ... ) //... 연속 변수 문법
{
	static char strBuffer[VA_MAX];  //글자를 변환해서 넣어둘 변수
	va_list	vl;                     //실질 메모리 변수 //list자료구조 분석 시작
	va_start( vl, format );         //format 형태를 분석
	_vsnprintf( strBuffer, VA_MAX, format, vl ); //strBuffer로 format을 변환
	va_end( vl ); //list 자료구조분석 끝

	OutputHanText( pRenderer, fontName, x, y, fontColor, fontSize, strBuffer );
}