#ifndef _IMG_APPLE_H_
#define _IMG_APPLE_H_

typedef struct _APPLE {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

}APPLE;

APPLE* APPLE_Init(SDL_Renderer* pRenderer);
void APPLE_Process(APPLE* pApple, SDL_Renderer* pRenderer);
void APPLE_Render(APPLE* pApple, SDL_Renderer* pRenderer);
void APPLE_Release(APPLE* pApple);

#endif _IMG_APPLE_H_