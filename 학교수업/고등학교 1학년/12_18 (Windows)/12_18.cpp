// 12_18.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>

using namespace std;

class Point
{
public:
	int x;
	int y;

	void Set (int _x, int _y)
	{
		x = _x;
		y = _y;
	}

	Point Get (void)
	{
		return *this;
	}

	void Draw (void)
	{
		cout << x << " " << y << endl;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Point p1;
	p1.Set (10, 10);
	p1.Draw ();

	_getch();
	return 0;
}

