#include "stdafx.h"

void OutputText( SDL_Renderer* pRenderer,	//�׸��� ���� ��µ� ȭ��
	             char* fontName,			//��Ʈ ����
				 int x, int y,				//���ڰ� ��µ� ��ġ ��ǥ
				 SDL_Color fontColor,		//���� ��
				 int	fontSize,			//���� ũ��
				 char* strbuffer )			//���� ����
{
	SDL_Texture* pTexture;	//��¿� �ؽ���

	TTF_Font*	pFont;		//��Ʈ ������ ����
	pFont = TTF_OpenFont( fontName, fontSize ); //��Ʈ ����
	
	SDL_Surface* pSufText;	//���� ��� �̹����� ���� ������ ����

	pSufText = TTF_RenderText_Solid( pFont, strbuffer, fontColor );//����==>�̹��� ��ȯ
	pTexture = SDL_CreateTextureFromSurface( pRenderer, pSufText );//Surface==>Texture ��ȯ

	SDL_Rect Rect = { x, y, pSufText->w, pSufText->h }; //��� ��ġ�� ũ�� ����
	SDL_RenderCopy( pRenderer, pTexture, NULL, &Rect); //�ĸ� ���ۿ� ���

	SDL_FreeSurface( pSufText ); //Surface �̹��� ����
	SDL_DestroyTexture( pTexture ); //Texture �̹��� ����
	TTF_CloseFont( pFont ); //��Ʈ ����
}

#define VA_MAX	1024

void OutputTexts( SDL_Renderer* pRenderer, 
	             char* fontName,
				 int x, int y,
				 SDL_Color fontColor,
				 int	fontSize,
				 char* format, ... ) //... ���� ���� ����
{
	static char strBuffer[VA_MAX];  //���ڸ� ��ȯ�ؼ� �־�� ����
	va_list	vl;                     //���� �޸� ���� //list�ڷᱸ�� �м� ����
	va_start( vl, format );         //format ���¸� �м�
	_vsnprintf( strBuffer, VA_MAX, format, vl ); //strBuffer�� format�� ��ȯ
	va_end( vl ); //list �ڷᱸ���м� ��

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
				 char* format, ... ) //... ���� ���� ����
{
	static char strBuffer[VA_MAX];  //���ڸ� ��ȯ�ؼ� �־�� ����
	va_list	vl;                     //���� �޸� ���� //list�ڷᱸ�� �м� ����
	va_start( vl, format );         //format ���¸� �м�
	_vsnprintf( strBuffer, VA_MAX, format, vl ); //strBuffer�� format�� ��ȯ
	va_end( vl ); //list �ڷᱸ���м� ��

	OutputHanText( pRenderer, fontName, x, y, fontColor, fontSize, strBuffer );
}