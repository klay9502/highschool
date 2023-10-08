#ifndef _SDL_CHAR_MARIO_H_
#define _SDL_CHAR_MARIO_H_

typedef struct _MARIO_CHAR {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture[4];

	Uint32			colorKey;

	int DelayTime;
}MARIO;

MARIO* Mario_Init (SDL_Renderer* pRenderer);
void Mario_Process(MARIO* pbird, SDL_Renderer* pRenderer);
void Mario_Render(MARIO* pMario, SDL_Renderer* pRenderer);
void Mario_Release (MARIO* pMario);

#endif _SDL_CHAR_MARIO_H_