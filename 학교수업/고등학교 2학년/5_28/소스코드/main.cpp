//#include <iostream>
//using namespace std;
//
//class AAA
//{
//private:
//	char* str1;
//public:
//	AAA(char* str1)
//	{
//		this->str1 = new char[strlen(str1) + 1];
//		strcpy(this->str1, str1);
//	}
//
//	virtual ~AAA(void)
//	{
//		cout << "~AAA() call!" << endl;
//		delete[]str1;
//	}
//
//	virtual void ShowString(void)
//	{
//		cout << str1 << ' ';
//	}
//};
//
//class BBB : public AAA
//{
//private:
//	char* str2;
//public:
//	BBB(char* str1, char* str2) : AAA(str1)
//	{
//		this->str2 = new char[strlen(str2) + 1];
//		strcpy(this->str2, str2);
//	}
//
//	~BBB(void)
//	{
//		cout << "~BBB() call!" << endl;
//		delete[]str2;
//	}
//
//	virtual void ShowString(void)
//	{
//		AAA::ShowString();
//		cout << str2 << endl;
//	}
//};
//
//int main(void)
//{
//	AAA* a = new BBB("Good", "evening");
//	// BBB* b = new BBB("Good", "morning");
//
//	a->ShowString();
//	// b->ShowString();
//
//	cout << "-----°´Ã¼ ¼Ò¸ê Á÷Àü-----" << endl;
//	delete a;
//	// delete b;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//
//class Person
//{
//public:
//	void Sleep(void)
//	{
//		cout << "Sleep" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	void Study(void)
//	{
//		cout << "Study" << endl;
//	}
//};
//
//class PartTimeStd : public Student
//{
//public:
//	void Work(void)
//	{
//		cout << "Work" << endl;
//	}
//};
//
//int main(void)
//{
//	PartTimeStd p;
//	p.Sleep();
//	p.Study();
//	p.Work();
//
//	Person& ref = p;
//	ref.Sleep();
//	// ref.Study();
//	// ref.Work();
//
//	return 0;
//}

//#include <stdio.h>
//
//void SelFunction(int s);
//void Add(void);
//void Min(void);
//
//int main(void)
//{
//	int sel;
//
//	while (true)
//	{
//		printf("¼±ÅÃ: µ¡¼À(1), »¬¼À(2), Á¾·á(3)");
//		scanf("%d", &sel);
//
//		if (sel == 3)
//		{
//			break;
//		}
//
//		SelFunction(sel);
//	}
//	printf("ÇÁ·Î±×·¥ÀÌ Á¾·á µÇ¾ú½À´Ï´Ù. \n");
//
//	return 0;
//}
//
//void SelFunction(int s)
//{
//	void(*fPtr)(void);
//	if (s == 1)
//	{
//		fPtr = Add;
//	}
//	else
//	{
//		fPtr = Min;
//	}
//	fPtr();
//}
//
//void Add(void)
//{
//	printf("µ¡¼ÀÇß½À´Ï´Ù!");
//}
//
//void Min(void)
//{
//	printf("»¬¼ÀÇß½À´Ï´Ù!");
//}

#include <iostream>
using namespace std;

class AAA
{
public:
	void String1(void)
	{
		cout << "AAA::String" << endl;
	}
};

class BBB : virtual public AAA
{
public:
	void String2(void)
	{
		cout << "BBB::String" << endl;
	}
};

class CCC : virtual public AAA
{
public:
	void String3(void)
	{
		cout << "CCC::String" << endl;
	}
};

class DDD : public BBB, public CCC
{
public:
	void ShowString(void)
	{
		String1();
		String2();
		String3();
	}
};

int main(void)
{
	DDD ddd;
	ddd.ShowString();

	return 0;
}