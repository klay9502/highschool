//// p409 문제 1
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int xpos, ypos;
//public:
//	CPoint(int x = 0, int y = 0) : xpos(x), ypos(y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << xpos << ", " << ypos << ']' << endl;
//	}
//
//	friend CPoint operator-(const CPoint& p1, const CPoint& p2);
//};
//
//CPoint operator-(const CPoint& p1, const CPoint& p2)
//{
//	CPoint temp(p1.xpos - p2.xpos, p1.ypos - p2.ypos);
//	return temp;
//}
//
//int main(void)
//{
//	CPoint pos1(15, 40);
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

//// p409 문제 2
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int xpos, ypos;
//public:
//	CPoint(int x = 0, int y = 0) : xpos(x), ypos(y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << xpos << ", " << ypos << ']' << endl;
//	}
//
//	CPoint& operator+=(const CPoint& p)
//	{
//		xpos += p.xpos;
//		ypos += p.ypos;
//		return *this;
//	}
//
//	CPoint& operator-=(const CPoint& p)
//	{
//		xpos -= p.xpos;
//		ypos -= p.ypos;
//		return *this;
//	}
//};
//
//int main(void)
//{
//	CPoint pos1(15, 40);
//	CPoint pos2(10, 20);
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//	cout << endl;
//
//	pos1 += pos2;
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//	cout << endl;
//
//	pos1 -= pos2;
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//
//	_getch();
//	return 0;
//}


//// p409 문제 3
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int xpos, ypos;
//public:
//	CPoint(int x = 0, int y = 0) : xpos(x), ypos(y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << xpos << ", " << ypos << ']' << endl;
//	}
//
//	friend bool operator==(CPoint& p1, CPoint& p2);
//	friend bool operator!=(CPoint& p1, CPoint& p2);
//};
//
//
//bool operator==(CPoint& p1, CPoint& p2)
//{
//	if (p1.xpos == p2.xpos && p1.ypos == p2.ypos)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool operator!=(CPoint& p1, CPoint& p2)
//{
//	return !(p1 == p2);
//}
//
//
//int main(void)
//{
//	CPoint pos1(15, 40);
//	CPoint pos2(10, 20);
//	CPoint pos3(15, 40);
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//	pos3.ShowPosition();
//
//	cout << "(pos1 == pos2) : " << (pos1 == pos2) << endl;
//	cout << "(pos1 == pos3) : " << (pos1 == pos3) << endl;
//	cout << "(pos1 != pos2) : " << (pos1 != pos2) << endl;
//	cout << "(pos1 != pos3) : " << (pos1 != pos3) << endl;
//
//	_getch();
//	return 0;
//}

//// p418 문제 1
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int xpos, ypos;
//public:
//	CPoint(int x = 0, int y = 0) : xpos(x), ypos(y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << xpos << ", " << ypos << ']' << endl;
//	}
//
//	CPoint operator-(void)
//	{
//		CPoint temp;
//		temp.xpos = -xpos;
//		temp.ypos = -ypos;
//		return temp;
//	}
//};
//
//
//int main(void)
//{
//	CPoint pos1(15, 40);
//	CPoint pos2 = -pos1;
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//
//	_getch();
//	return 0;
//}

//// p418 문제 2
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int xpos, ypos;
//public:
//	CPoint(int x = 0, int y = 0) : xpos(x), ypos(y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << xpos << ", " << ypos << ']' << endl;
//	}
//
//	CPoint operator~(void)
//	{
//		CPoint temp;
//		temp.xpos = ypos;
//		temp.ypos = xpos;
//		return temp;
//	}
//};
//
//
//int main(void)
//{
//	CPoint pos1(15, 40);
//	CPoint pos2 = ~pos1;
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//
//	_getch();
//	return 0;
//}

//// p418 문제 2
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int xpos, ypos;
//public:
//	CPoint(int x = 0, int y = 0) : xpos(x), ypos(y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << xpos << ", " << ypos << ']' << endl;
//	}
//
//	CPoint operator~(void)
//	{
//		CPoint temp;
//		temp.xpos = ypos;
//		temp.ypos = xpos;
//		return temp;
//	}
//};
//
//
//int main(void)
//{
//	CPoint pos1(15, 40);
//	CPoint pos2 = ~pos1;
//
//	pos1.ShowPosition();
//	pos2.ShowPosition();
//
//	_getch();
//	return 0;
//}

//// p426 교환법칙
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//class CPoint
//{
//private:
//	int xpos, ypos;
//public:
//	CPoint(int x = 0, int y = 0) : xpos(x), ypos(y)
//	{ /* empty */ }
//
//	void ShowPosition(void) const
//	{
//		cout << '[' << xpos << ", " << ypos << ']' << endl;
//	}
//
//	CPoint operator*(int num)
//	{
//		CPoint temp;
//		temp.xpos = xpos * num;
//		temp.ypos = ypos * num;
//		return temp;
//	}
//
//	friend CPoint operator*(int num, CPoint& ref);
//};
//
//CPoint operator*(int num, CPoint& ref)
//{
//	return ref*num;
//}
//
//
//int main(void)
//{
//	CPoint pos1(15, 40);
//	CPoint pos2 = pos1 * 3;
//	CPoint pos3 = 3 * pos1;
//
//	pos2.ShowPosition();
//	pos3.ShowPosition();
//
//	_getch();
//	return 0;
//}

// p446
#include <iostream>
#include <conio.h>
using namespace std;

class Person
{
private:
	char* name;
	int   age;
public:
	Person(char* _name, int _age) : age(_age)
	{
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}

	~Person(void)
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}

	Person& operator=(const Person& ref)
	{
		delete[] name;
		
		name = new char[strlen(ref.name) + 1];
		strcpy(name, ref.name);
		age = ref.age;
		return *this;
	}

	void ShowPersonInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

int main(void)
{
	Person person1("김종민", 18);
	Person person2("김민규", 18);

	person1.ShowPersonInfo();
	person2.ShowPersonInfo();

	person1 = person2;

	person1.ShowPersonInfo();
	person2.ShowPersonInfo();

	return 0;
}