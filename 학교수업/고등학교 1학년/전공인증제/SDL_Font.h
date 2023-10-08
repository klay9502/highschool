#ifndef __SDL_FONT_H__
#define __SDL_FONT_H__

void OutputText(SDL_Renderer* pRenderer, char* fontName, int x, int y, SDL_Color fontColor, int fontSize, char* strbuffer);
void OutputTexts(SDL_Renderer* pRenderer, char* fontName, int x, int y, SDL_Color fontColor, int fontSize, char* foramt, ...);
void OutputHanText(SDL_Renderer* pRenderer, char* fontName, int x, int y, SDL_Color fontColor, int fontSize, char* strbuffer);
void OutputHanTexts(SDL_Renderer* pRenderer, char* fontName, int x, int y, SDL_Color fontColor, int fontSize, char* foramt, ...);

#endif __SDL_FONT_H__