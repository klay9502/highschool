#ifndef __IMG_FISH_2_H__
#define __IMG_FISH_2_H__

typedef struct _IMAGE_FISH_2 {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

	Uint32			colorKey;

} FISH_2;

FISH_2* Fish_2_Init(SDL_Renderer* pRenderer);
void Fish_2_Process (FISH_2* pFish_2, SDL_Renderer* pRenderer);
void Fish_2_Render (FISH_2* pFish_2, SDL_Renderer* pRenderer);
void Fish_2_Release (FISH_2* pFish_2);

#endif __IMG_FISH_2_H__