//#include <iostream>
//using namespace std;
//
//class PermanentWorker
//{
//private:
//	char name[100];
//	int salary;		// 매달 지불해야 하는 금여액
//public:
//	PermanentWorker(char* name, int money) : salary(money)
//	{
//		strcpy(this->name, name);
//	}
//	int GetPay(void) const
//	{
//		return salary;
//	}
//	void ShowSalaryInfo(void) const
//	{
//		cout << "name: " << name << endl;
//		cout << "salary: " << GetPay() << endl << endl;
//	}
//};
//
//class EmployeeHandler
//{
//private:
//	PermanentWorker* empList[50];
//	int empNum;
//public:
//	EmployeeHandler(void) : empNum(0)
//	{}
//	void AddEmployee(PermanentWorker* emp)
//	{
//		empList[empNum++] = emp;
//	}
//	void ShowAllSalaryInfo(void) const
//	{
//		for (int i = 0; i < empNum; i++)
//		{
//			empList[i]->ShowSalaryInfo();
//		}
//	}
//	void ShowTotalSalary(void) const
//	{
//		int sum = 0;
//		for (int i = 0; i < empNum; i++)
//		{
//			sum += empList[i]->GetPay();
//		}
//		cout << "salary sum: " << sum << endl;
//	}
//	~EmployeeHandler()
//	{
//		for (int i = 0; i < empNum; i++)
//		{
//			delete empList[i];
//		}
//	}
//};
//
//int main(void)
//{
//	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
//	EmployeeHandler handler;
//
//	// 직원 등록
//	handler.AddEmployee(new PermanentWorker("KIM", 1000));
//	handler.AddEmployee(new PermanentWorker("LEE", 1500));
//	handler.AddEmployee(new PermanentWorker("JUN", 2000));
//
//	// 이번 달에 지불해야 할 급여의 정보
//	handler.ShowAllSalaryInfo();
//
//	// 이번 달에 지불해야 할 급여의 총합
//	handler.ShowTotalSalary();
//	return 0;
//}

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Person
//{
//private:
//	int age;		// 나이
//	char name[50];	// 이름
//public:
//	Person(int myage, char* myname) : age(myage)
//	{
//		strcpy(name, myname);
//	}
//	void WhatYourName(void) const
//	{
//		cout << "My name is " << name << endl;
//	}
//	void HowOldAreYou(void) const
//	{
//		cout << "I'm " << age << "years old" << endl;
//	}
//};
//
//class UnivStudent : public Person
//{
//private:
//	char major[50];
//public:
//	UnivStudent(char* myname, int myage, char* mymajor) : Person(myage, myname)
//	{
//		strcpy(major, mymajor);
//	}
//	void WhoAreYou(void) const
//	{
//		WhatYourName();
//		HowOldAreYou();
//		cout << "My major is " << major << endl << endl;
//	}
//};
//
//int main(void)
//{
//	UnivStudent ustd1("LEE", 22, "Computer eng.");
//	ustd1.WhoAreYou();
//
//	UnivStudent ustd2("KIM", 21, "Electronic eng.");
//	ustd2.WhoAreYou();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class SoBase
//{
//private:
//	int baseNum;
//public:
//	SoBase() : baseNum(20)
//	{
//		cout << "SoBase()" << endl;
//	}
//	SoBase(int num) : baseNum(num)
//	{
//		cout << "SoBase(int num)" << endl;
//	}
//	void ShowBaseData(void)
//	{
//		cout << baseNum << endl;
//	}
//};
//
//class SoDerived : public SoBase
//{
//private:
//	int derivNum;
//public:
//	SoDerived() : derivNum(30)
//	{
//		cout << "SoDerived()" << endl;
//	}
//	SoDerived(int num) : derivNum(num)
//	{
//		cout << "SoDerived(int num)" << endl;
//	}
//	SoDerived(int baseNum, int num) : SoBase(baseNum), derivNum(num)
//	{
//		cout << "SoDerived(int baseNum, int num)" << endl;
//	}
//	void ShowDerivData(void)
//	{
//		ShowBaseData();
//		cout << derivNum << endl;
//	}
//};
//
//int main(void)
//{
//	cout << "case1....." << endl;
//	SoDerived dr1;
//	dr1.ShowDerivData();
//	cout << "---------------------------------" << endl;
//
//	cout << "case2....." << endl;
//	SoDerived dr2(12);
//	dr2.ShowDerivData();
//	cout << "---------------------------------" << endl;
//
//	cout << "case3....." << endl;
//	SoDerived dr3(23, 24);
//	dr3.ShowDerivData();
//	
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class SoBase
//{
//private:
//	int baseNum;
//public:
//	SoBase(int n) : baseNum(n)
//	{
//		cout << "SoBase() : " << baseNum << endl;
//	}
//	~SoBase()
//	{
//		cout << "~SoBase() : " << baseNum << endl;
//	}
//};
//
//class SoDerived : public SoBase
//{
//private:
//	int derivNum;
//public:
//	SoDerived(int n) : SoBase(n), derivNum(n)
//	{
//		cout << "SoDerived() : " << derivNum << endl;
//	}
//	~SoDerived()
//	{
//		cout << "~SoDerived() : " << derivNum << endl;
//	}
//};
//
//int main(void)
//{
//	SoDerived drv1(15);
//	SoDerived drv2(27);
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
//public:
//	Person(char *myname)
//	{
//		name = new char[strlen(myname) + 1];
//		strcpy(name, myname);
//	}
//	~Person()
//	{
//		delete[]name;
//	}
//	void WhatYourName() const
//	{
//		cout << "My name is " << name << endl;
//	}
//};
//
//class UnivStudent : public Person
//{
//private:
//	char* major;
//public:
//	UnivStudent(char* myname, char* mymajor) : Person(myname)
//	{
//		major = new char[strlen(mymajor) + 1];
//		strcpy(major, mymajor);
//	}
//	~UnivStudent()
//	{
//		delete[]major;
//	}
//	void WhoAreYou() const
//	{
//		WhatYourName();
//		cout << "My major is " << major << endl << endl;
//	}
//};
//
//int main(void)
//{
//	UnivStudent st1("Kim", "Mathematics");
//	st1.WhoAreYou();
//	UnivStudent st2("Hong", "Physics");
//	st2.WhoAreYou();
//
//	return 0;
//}

#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int oil) : gasolineGauge(oil)
	{
		// empty..
	}
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int oil, int elec) : Car(oil), electricGauge(elec)
	{
		// empty...
	}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int oil, int elec, int water) : HybridCar(oil, elec), waterGauge(water)
	{
		// empty...
	}
	void ShowCurrentGauge()
	{
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main(void)
{
	HybridWaterCar WaterCar(5, 10, 15);

	WaterCar.ShowCurrentGauge();
}