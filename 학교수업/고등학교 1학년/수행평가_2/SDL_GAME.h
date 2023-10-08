#ifndef _SDL_GAME_H_
#define _SDL_GAME_H_

BOOL Game_Init(void);
void Game_Loop(void);
void Game_Release(void);

// 이미지 파일의 로드
class _Image
{
public:
	SDL_Texture *Image;
	int nX, nY;
};

#endif _SDL_GAME_H_