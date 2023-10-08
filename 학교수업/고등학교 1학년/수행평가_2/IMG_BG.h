#ifndef _IMG_BG_H_
#define _IMG_BG_H_

typedef struct _BACKGROUND {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

} BACKGROUND;

BACKGROUND* BG_Init(SDL_Renderer* pRenderer);
void BG_Render(BACKGROUND* pBG, SDL_Renderer* pRenderer);
void BG_Release(BACKGROUND* pBG);

#endif _IMG_BG_H_