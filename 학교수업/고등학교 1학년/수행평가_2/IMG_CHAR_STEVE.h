#ifndef _IMG_CHAR_STEVE_
#define _IMG_CHAR_STEVE_

typedef struct _STEVE_JOBS {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;
	int				xpos;
	int				ypos;
} STEVE;

STEVE* STEVE_Init (SDL_Renderer* pRenderer);
void STEVE_Process (STEVE* pSteve, SDL_Renderer* pRenderer);
void STEVE_Render (STEVE* pSteve, SDL_Renderer* pRenderer);
void STEVE_Release (STEVE* pSteve);

#endif _IMG_CHAR_STEVE_