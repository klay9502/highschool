#include <Windows.h>
#define COL GetStdHandle(STD_OUTPUT_HANDLE)
#define WHITE		SetConsoleTextAttribute(COL, 0x0007);
#define GRAY		SetConsoleTextAttribute(COL, 0x0008);
#define YELLOW		SetConsoleTextAttribute(COL, 0x000e);
#define SKY			SetConsoleTextAttribute(COL, 0x000b);
#define GREEN		SetConsoleTextAttribute(COL, 0x0002);