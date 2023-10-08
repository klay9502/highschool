//#include <iostream>
//using namespace std;
//
//class CPerson
//{
//public:
//	void Sleep(void)
//	{
//		cout << "Sleep.." << endl;
//	}
//};
//
//class CStudent : public CPerson
//{
//public:
//	void Study(void)
//	{
//		cout << "Study..." << endl;
//	}
//};
//
//class CPartTimeStudent : public CStudent
//{
//public:
//	void Work(void)
//	{
//		cout << "Work..." << endl;
//	}
//};
//
//int main(void)
//{
//	CPerson* ptr1 = new CStudent();
//	CPerson* ptr2 = new CPartTimeStudent();
//	CStudent* ptr3 = new CPartTimeStudent();
//
//	ptr1->Sleep();
//	ptr2->Sleep();
//	ptr3->Sleep();
//
//	delete ptr1;
//	delete ptr2;
//	delete ptr3;
//
//	return 0;
//}

#include <iostream>
#include <cstring>
using namespace std;

enum RISK_LEVEL { A, B, C };

class CEmployee
{
private:
	char name[100];
public:
	CEmployee(char* name)
	{
		strcpy(this->name, name);
	}

	void ShowYourName(void) const
	{
		cout << "name: " << name << endl;
	}

	virtual int GetPay(void) const = 0;				// 순수 가상함수

	virtual void ShowSalaryInfo(void) const = 0;	// 순수 가상함수
};

class CPermanentWorker : public CEmployee
{
private:
	int salary;	// 월 급여
public:
	CPermanentWorker(char* name, int money) : CEmployee(name), salary(money)
	{
		// empty..
	}

	int GetPay(void) const
	{
		return salary;
	}

	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class CTemporaryWorker : public CEmployee
{
private:
	int workTime;		// 이 달에 일한 시간의 합계
	int payPerHour;		// 시간당 급여
public:
	CTemporaryWorker(char* name, int pay) : CEmployee(name), workTime(0), payPerHour(pay)
	{
		// empty...
	}

	void AddWorkTime(int time)
	{
		workTime += time;
	}

	int GetPay(void) const
	{
		return workTime * payPerHour;
	}

	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class CSalesWorker : public CPermanentWorker
{
private:
	int salesResult;		// 월 판매실적
	double bonusRatio;		// 상여금 비율
public:
	CSalesWorker(char* name, int money, double ratio) : CPermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{
		// empty...
	}

	void AddSalesResult(int value)
	{
		salesResult += value;
	}

	int GetPay(void) const
	{
		return CPermanentWorker::GetPay()	// CPermanentWorker의 GetPay 함수 호출.
			+ (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;		// SalesWorker의 GetPay 함수가 호출됨.
	}
};

class CForeignSalesWorker : public CSalesWorker
{
private:
	double riskBonus;
public:
	CForeignSalesWorker(char* name, int money, double ratio, RISK_LEVEL riskLevel) : CSalesWorker(name, money, ratio)
	{
		switch (riskLevel)
		{
		case A:
			riskBonus = 30;
			break;
		case B:
			riskBonus = 20;
			break;
		case C:
			riskBonus = 10;
			break;
		}
	}

	int GetRiskPay(void) const
	{
		return CSalesWorker::GetPay()
			* (riskBonus / 100);
	}

	int GetPay(void) const
	{
		return CSalesWorker::GetPay();
	}

	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl;		// SalesWorker의 GetPay 함수가 호출됨.
		cout << "risk pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() + GetRiskPay() << endl << endl;
	}
};

class CEmployeeHandler
{
private:
	CEmployee* empList[50];
	int empNum;
public:
	CEmployeeHandler(void) : empNum(0)
	{
		// empty...
	}

	void AddEmployee(CEmployee* emp)
	{
		empList[empNum++] = emp;
	}

	void ShowAllSalaryInfo(void) const
	{
		for (int i = 0; i < empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}

	void ShowTotalSalary(void) const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
		{
			sum += empList[i]->GetPay();
		}

		cout << "salary sum: " << sum << endl;
	}

	~CEmployeeHandler(void)
	{
		for (int i = 0; i < empNum; i++)
		{
			delete empList[i];
		}
	}
};

int main(void)
{
	// 직원관리를 목적으로 설계된 컨트롤 클래스의 객체생성
	CEmployeeHandler handler;

	//// 정규직 등록
	//handler.AddEmployee(new CPermanentWorker("Kim", 1000));
	//handler.AddEmployee(new CPermanentWorker("LEE", 1500));

	//// 임시직 등록
	//CTemporaryWorker* alba = new CTemporaryWorker("Jung", 700);
	//alba->AddWorkTime(5);		// 5시간 일한결과 등록.
	//handler.AddEmployee(alba);

	//// 영업직 등록
	//CSalesWorker* seller = new CSalesWorker("Hong", 1000, 0.1);
	//seller->AddSalesResult(7000);		// 영업실적 7000.
	//handler.AddEmployee(seller);

	// 해외 영업직 등록
	CForeignSalesWorker* fseller1 = new CForeignSalesWorker("Hong", 1000, 0.1, A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	CForeignSalesWorker* fseller2 = new CForeignSalesWorker("Yoon", 1000, 0.1, B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	CForeignSalesWorker* fseller3 = new CForeignSalesWorker("Lee", 1000, 0.1, C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	// 이번 달에 지불해야 할 급여의 정보
	handler.ShowAllSalaryInfo();

	//// 이번 달에 지불해야 할 급여의 총합
	//handler.ShowTotalSalary();

	return 0;
}