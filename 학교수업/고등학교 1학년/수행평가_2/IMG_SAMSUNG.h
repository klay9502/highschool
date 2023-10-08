#ifndef _IMG_SAMSUNG_H_
#define _IMG_SAMSUNG_H_

typedef struct _SAMSUNG {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

}SAMSUNG;

SAMSUNG* SAMSUNG_Init(SDL_Renderer* pRenderer);
void SAMSUNG_Process(SAMSUNG* pSamsung, SDL_Renderer* pRenderer);
void SAMSUNG_Render(SAMSUNG* pSamsung, SDL_Renderer* pRenderer);
void SAMSUNG_Release(SAMSUNG* pSamsung);

#endif _IMG_SAMSUNG_H_