#ifndef __IMG_BACKGROUND_H__
#define __IMG_BACKGROUND_H__

typedef struct _IMAGE_BG {

	SDL_Surface* pSurface;
	SDL_Texture* pTexture;
} BACKGROUND;

BACKGROUND* BG_Init(SDL_Renderer* pRenderer);
void BG_Process (BACKGROUND* pBG, SDL_Renderer* pRenderer);
void BG_Render (BACKGROUND* pBG, SDL_Renderer* pRenderer);
void BG_Release (BACKGROUND* pBG);

#endif __IMG_BACKGROUND_H__