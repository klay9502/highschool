#ifndef __IMG_FISH_1_H__
#define __IMG_FISH_1_H__

typedef struct _IMAGE_FISH_1 {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

	Uint32			colorKey;

} FISH_1;

FISH_1* Fish_1_Init(SDL_Renderer* pRenderer);
void Fish_1_Process (FISH_1* pFish_1, SDL_Renderer* pRenderer);
void Fish_1_Render (FISH_1* pFish_1, SDL_Renderer* pRenderer);
void Fish_1_Release (FISH_1* pFish_1);

#endif __IMG_FISH_1_H__