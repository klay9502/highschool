//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int m_xpos, m_ypos;
//public:
//	CPoint(int _x = 0, int _y = 0) : m_xpos(_x), m_ypos(_y)
//	{ /* empty */ }
//	
//	void ShowPosition(void) const
//	{
//		cout << '[' << m_xpos << ", " << m_ypos << ']' << endl;
//	}
//
//	CPoint operator+(const CPoint &ref)
//	{
//		CPoint pos(m_xpos + ref.m_xpos, m_ypos + ref.m_ypos);
//		return pos;
//	}
//};
//
//int main(void)
//{
//	CPoint pos1(3, 4);
//	CPoint pos2(10, 20);
//	// CPoint pos3 = pos1.operator+(pos2);
//	CPoint pos3 = pos1 + pos2;
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//	pos3.ShowPosition();
//
//	_getch();
//	return 0;
//}

//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int m_xpos, m_ypos;
//public:
//	CPoint(int _x = 0, int _y = 0) : m_xpos(_x), m_ypos(_y)
//	{ /* empty */ }
//	
//	void ShowPosition(void) const
//	{
//		cout << '[' << m_xpos << ", " << m_ypos << ']' << endl;
//	}
//
//	friend CPoint operator+(const CPoint &pos1, const CPoint &pos2);
//};
//
//CPoint operator+(const CPoint &pos1, const CPoint &pos2)
//{
//	CPoint pos(pos1.m_xpos + pos2.m_xpos, pos1.m_ypos + pos2.m_ypos);
//	return pos;
//}
//
//int main(void)
//{
//	CPoint pos1(3, 4);
//	CPoint pos2(10, 20);
//	// CPoint pos3 = pos1.operator+(pos2);
//	CPoint pos3 = pos1 + pos2;
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//	pos3.ShowPosition();
//
//	_getch();
//	return 0;
//}

//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int m_xpos, m_ypos;
//public:
//	CPoint(int _x = 0, int _y = 0) : m_xpos(_x), m_ypos(_y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << m_xpos << ", " << m_ypos << ']' << endl;
//	}
//
//	CPoint& operator++(void)
//	{
//		m_xpos++;
//		m_ypos++;
//		return *this;
//	}
//
//	//CPoint operator++(void)
//	//{
//	//	m_xpos++;
//	//	m_ypos++;
//	//	return *this;
//	//}
//
//	friend CPoint& operator--(CPoint &ref);
//};
//
//CPoint& operator--(CPoint &ref)
//{
//	ref.m_xpos--;
//	ref.m_ypos--;
//	return ref;
//}
//
//int main(void)
//{
//	CPoint pos(1, 2);
//
//	++pos;
//	pos.ShowPosition();
//	--pos;
//	pos.ShowPosition();
//
//	++(++pos);
//	pos.ShowPosition();
//	--(--pos);
//	pos.ShowPosition();
//
//	_getch();
//	return 0;
//}

//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int m_xpos, m_ypos;
//public:
//	CPoint(int _x = 0, int _y = 0) : m_xpos(_x), m_ypos(_y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << m_xpos << ", " << m_ypos << ']' << endl;
//	}
//
//	CPoint& operator++(void) // 전위 증가
//	{
//		m_xpos++;
//		m_ypos++;
//		return *this;
//	}
//
//	const CPoint operator++(int) // 후위 증가
//	{
//		const CPoint retobj(m_xpos, m_ypos);	// const CPoint retobj(*this);
//		m_xpos++;
//		m_ypos++;
//		return retobj;
//	}
//
//	friend CPoint& operator--(CPoint &ref);
//	friend const CPoint operator--(CPoint &ref, int);
//};
//
//CPoint& operator--(CPoint &ref)	// 전위 감소
//{
//	ref.m_xpos--;
//	ref.m_ypos--;
//	return ref;
//}
//
//const CPoint operator--(CPoint &ref, int) // 후위 감소
//{
//	const CPoint retobj(ref.m_xpos, ref.m_ypos);	// const 객체라 한다.
//	ref.m_xpos--;
//	ref.m_ypos--;
//	return retobj;
//}
//
//int main(void)
//{
//	CPoint pos(3, 5);
//	CPoint cpy;
//	cpy = pos--;
//	cpy.ShowPosition();
//	pos.ShowPosition();
//
//	cpy = pos++;
//	cpy.ShowPosition();
//	pos.ShowPosition();
//	_getch();
//	return 0;
//}

/* p409 문제 10-1 문제 1 */
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int m_xpos, m_ypos;
//public:
//	CPoint(int _x = 0, int _y = 0) : m_xpos(_x), m_ypos(_y)
//	{ /* empty */ }
//	
//	void ShowPosition(void) const
//	{
//		cout << '[' << m_xpos << ", " << m_ypos << ']' << endl;
//	}
//
//	friend CPoint operator-(const CPoint &pos1, const CPoint &pos2);
//};
//
//CPoint operator-(const CPoint &pos1, const CPoint &pos2)
//{
//	CPoint pos(pos1.m_xpos - pos2.m_xpos, pos1.m_ypos - pos2.m_ypos);
//	return pos;
//}
//
//int main(void)
//{
//	CPoint pos1(3, 4);
//	CPoint pos2(10, 20);
//	CPoint pos3 = pos1 - pos2;
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//	pos3.ShowPosition();
//
//	_getch();
//	return 0;
//}

/* p409 문제 10-1 문제 2 */
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int m_xpos, m_ypos;
//public:
//	CPoint(int _x = 0, int _y = 0) : m_xpos(_x), m_ypos(_y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << m_xpos << ", " << m_ypos << ']' << endl;
//	}
//
//	CPoint operator+=(const CPoint &ref)
//	{
//		m_xpos += ref.m_xpos;
//		m_ypos += ref.m_ypos;
//		return *this;
//	}
//
//	CPoint operator-=(const CPoint &ref)
//	{
//		m_xpos -= ref.m_xpos;
//		m_ypos -= ref.m_ypos;
//		return *this;
//	}
//};
//
//int main(void)
//{
//	CPoint pos1(5, 10);
//	CPoint pos2(10, 20);
//
//	(pos1 += pos2).ShowPosition();
//	(pos1 -= pos2).ShowPosition();
//
//	_getch();
//	return 0;
//}

/* p410 문제 10-1 문제 3 */
#include <iostream>
#include <conio.h>
using namespace std;

class CPoint
{
private:
	int m_xpos, m_ypos;
public:
	CPoint(int _x = 0, int _y = 0) : m_xpos(_x), m_ypos(_y)
	{ /* empty */ }

	void ShowPosition(void) const
	{
		cout << '[' << m_xpos << ", " << m_ypos << ']' << endl;
	}

	friend bool operator==(const CPoint &ref1, const CPoint &ref2);
	friend bool operator!=(const CPoint &ref1, const CPoint &ref2);
};

bool operator==(const CPoint &ref1, const CPoint &ref2)
{
	if (ref1.m_xpos == ref2.m_xpos && ref1.m_ypos == ref2.m_ypos)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator!=(const CPoint &ref1, const CPoint &ref2)
{
	return !(ref1 == ref2);
}

int main(void)
{
	CPoint pos1(10, 10);
	CPoint pos2(10, 10);


	_getch();
	return 0;
}