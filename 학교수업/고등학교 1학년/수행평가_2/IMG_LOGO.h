#ifndef _IMG_LOGO_H_
#define _IMG_LOGO_H_

typedef struct _LOGO {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

} LOGO;

LOGO* LOGO_Init(SDL_Renderer* pRenderer);
void LOGO_Render(LOGO* pLogo, SDL_Renderer* pRenderer);
void LOGO_Release(LOGO* pLogo);

#endif _IMG_LOGO_H_