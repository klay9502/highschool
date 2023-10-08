#ifndef _SDL_CHAR_MONSTER_H_
#define _SDL_CHAR_MONSTER_H_

typedef struct _MONSTER_CHAR {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture[2];

	Uint32			colorKey;

	int DelayTime;
}MONSTER;

MONSTER* Monster_Init (SDL_Renderer* pRenderer);
void Monster_Process(MONSTER* pbird, SDL_Renderer* pRenderer);
void Monster_Render(MONSTER* pMario, SDL_Renderer* pRenderer);
void Monster_Release (MONSTER* pMario);

#endif _SDL_CHAR_MONSTER_H_