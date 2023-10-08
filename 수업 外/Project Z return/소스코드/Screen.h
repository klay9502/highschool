#ifndef _Screen_H_
#define _Screen_H_

void ScreenInit();
void ScreenFlipping();
void ScreenClear();
void ScreenRelease();
void ScreenPrint(int x, int y, char *string);
void SetColor(unsigned short color);

#endif _Screen_H_