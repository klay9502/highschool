#ifndef __IMG_FISH_3_H__
#define __IMG_FISH_3_H__

typedef struct _IMAGE_FISH_3 {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

	Uint32			colorKey;

} FISH_3;

FISH_3* Fish_3_Init(SDL_Renderer* pRenderer);
void Fish_3_Process (FISH_3* pFish_3, SDL_Renderer* pRenderer);
void Fish_3_Render (FISH_3* pFish_3, SDL_Renderer* pRenderer);
void Fish_3_Release (FISH_3* pFish_3);

#endif __IMG_FISH_3_H__