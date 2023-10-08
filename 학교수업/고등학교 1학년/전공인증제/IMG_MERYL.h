#ifndef __IMG_MERYL_H__
#define __IMG_MERYL_H__

typedef struct _IMAGE_MERYL {

	SDL_Surface*	pSurface;
	SDL_Texture*	pTexture;

	Uint32			colorKey;

} MERYL;

MERYL* Meryl_Init(SDL_Renderer* pRenderer);
void Meryl_Process (MERYL* pMeryl, SDL_Renderer* pRenderer);
void Meryl_Render (MERYL* pMeryl, SDL_Renderer* pRenderer);
void Meryl_Release (MERYL* pMeryl);

#endif __IMG_MERYL_H__