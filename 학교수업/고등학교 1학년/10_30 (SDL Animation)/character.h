#pragma once

typedef struct tagCharacter
{
	SDL_Surface*	pImage;
	SDL_Texture*	pTexture;
	Uint32			colorKey;
	int				SpriteWidth;
	int				SpriteHeight;

} CHARACTER;

CHARACTER*	CharInit(SDL_Renderer* pRenderer);
VOID		CharProcess(CHARACTER* pChar);
VOID		CharRender(SDL_Renderer* pRenderer, CHARACTER* pChar);
VOID		CharRelease(CHARACTER* pChar);