// Engine.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "Engine.h"
#include "System.h"


int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
#if _DEBUG
	/*AllocConsole();
	freopen("CONOUT$", "w", stdout);*/
#endif
	CSystem system;

	system.Init();
	system.MessageLoop();
	system.Release();
}