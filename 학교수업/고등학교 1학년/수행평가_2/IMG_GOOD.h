#ifndef _IMG_GOOD_H_
#define _IMG_GOOD_H_

typedef struct _GOOD {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

} GOOD;

GOOD* GOOD_Init(SDL_Renderer* pRenderer);
void GOOD_Render(GOOD* pGood, SDL_Renderer* pRenderer);
void GOOD_Release(GOOD* pGood);

#endif _IMG_GOOD_H_