//#include <iostream>
//using namespace std;
//
//class SoSimple
//{
//private:
//	int num1;
//	int num2;
//public:
//	SoSimple(int num1, int num2) : num1(num1), num2(num2)
//	{
//		// empty;
//	}
//
//	~SoSimple()
//	{
//		// empty;
//	}
//
//	SoSimple(SoSimple &copy) : num1(copy.num1), num2(copy.num2)
//	{
//		cout << "Called SoSomple(SoSimple &copy)" << endl;
//	}
//
//	void SoSimpleShow()
//	{
//		cout << num1 << endl;
//		cout << num2 << endl;
//	}
//};
//
//int main(void)
//{
//	SoSimple sim1(15, 20);
//	SoSimple sim2 = sim1;
//	sim2.SoSimpleShow();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//private:
//	char* name;
//	char* phone;
//	int age;
//public:
//	Person(char* _name, char* _phone, int _age) : age(_age)
//	{
//		name = new char[strlen(_name) + 1];
//		strcpy(name, _name);
//
//		phone = new char[strlen(_phone) + 1];
//		strcpy(phone, _phone);
//	}
//
//	explicit Person(const Person &p) : age(p.age)
//	{
//		name = new char[strlen(p.name) + 1];
//		strcpy(name, p.name);
//
//		phone = new char[strlen(p.phone) + 1];
//		strcpy(phone, p.phone);
//	}
//
//	~Person()
//	{
//		delete[]phone;
//		delete[]name;
//	}
//	void ShowData()
//	{
//		cout << "name: " << name << endl;
//		cout << "phone: " << phone << endl;
//		cout << "age: " << age << endl << endl;
//	}
//};
//
//int main(void)
//{
//	Person man = { "Kim", "010-2222-4444", 18 };
//	Person girl(man);
//
//	man.ShowData();
//	girl.ShowData();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//enum POS { CLERK, SENIOR, ASSIST, MANAGER };
//
//class NameCard
//{
//private:
//	char* name;
//	char* company;
//	char* phone;
//	POS emPosition;
//public:
//	NameCard(char* _name, char* _company, char* _phone, POS _emPosition) : emPosition(_emPosition)
//	{
//		name = new char[strlen(_name) + 1];
//		strcpy(name, _name);
//
//		company = new char[strlen(_company) + 1];
//		strcpy(company, _company);
//
//		phone = new char[strlen(_phone) + 1];
//		strcpy(phone, _phone);
//	}
//
//	explicit NameCard(NameCard &copy) : emPosition(copy.emPosition)
//	{
//		name = new char[strlen(copy.name) + 1];
//		strcpy(name, copy.name);
//
//		company = new char[strlen(copy.company) + 1];
//		strcpy(company, copy.company);
//
//		phone = new char[strlen(copy.phone) + 1];
//		strcpy(phone, copy.phone);
//	}
//
//	~NameCard(void)
//	{
//		delete[]phone;
//		delete[]company;
//		delete[]name;
//	}
//
//	void ShowNameCardInfo()
//	{
//		cout << "이름: " << name << endl;
//		cout << "회사: " << company << endl;
//		cout << "전화번호: " << phone << endl;
//		cout << "직급: ";
//
//		switch (emPosition)
//		{
//		case CLERK:
//			cout << "사원";
//			break;
//		case SENIOR:
//			cout << "주임";
//			break;
//		case ASSIST:
//			cout << "대리";
//			break;
//		case MANAGER:
//			cout << "과장";
//			break;
//		}
//
//		cout << endl << endl;
//	}
//};
//
//int main(void)
//{
//	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", CLERK);
//	NameCard manSenior("Hong", "OrnageEng", "010-3333-4444", SENIOR);
//	NameCard copy1(manClerk);
//	NameCard copy2(manSenior);
//	
//	copy1.ShowNameCardInfo();
//	copy2.ShowNameCardInfo();
//	return 0;
//}

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num;
public:
	SoSimple(int num) : num(num)
	{
		// empty...
	}
	SoSimple(const SoSimple &copy) : num(copy.num)
	{
		cout << "Called SoSimple(const SoSimple &copy)" << endl;
	}
	~SoSimple()
	{
		// empty...
	}
	void ShowData(void)
	{
		cout << "num: " << num << endl;
	}
};


void SimpleFuncObj(SoSimple obj)
{
	obj.ShowData();
}

int main(void)
{
	SoSimple obj(7);

	cout << "함수호출 전" << endl;
	SimpleFuncObj(obj);
	cout << "함수호출 후" << endl;

	return 0;
	return 0;
}