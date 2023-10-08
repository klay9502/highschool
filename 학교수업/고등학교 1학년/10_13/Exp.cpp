#include "stdafx.h"
#include "Exp.h"

EXP* InitExp()
{
	EXP* exp = (EXP*)malloc( sizeof (EXP) );
	exp->pSurface = SDL_LoadBMP( "./Fort_exp_strip.bmp" );
	exp->x = 0;
	exp->y = 0;

	for (int i = 0; i < 64; i++)
	{
		exp->rtImg[i].x = i * 256;
		exp->rtImg[i].y = 0;
		exp->rtImg[i].w = 256;
		exp->rtImg[i].h = 256;
	}

	return exp;
}

void Render(EXP* exp, SDL_Surface* screen)
{
	static int i = 0;

	SDL_BlitSurface( exp->pSurface, &exp->rtImg[0], screen, NULL );

	if (++i >= 64 )
		i = 0;
}

void Release(EXP* exp)
{
	SDL_FreeSurface( exp->pSurface );
	delete exp;
}