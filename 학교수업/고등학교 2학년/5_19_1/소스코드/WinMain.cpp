#include "MainHeader.h"
#include "Game.h"

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
	CGame Game;

	Game.GameInit();
	Game.GameLoop();
	Game.GameRelease();

	return 0;
}