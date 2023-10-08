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

	virtual int GetPay(void) const = 0;				// ���� �����Լ�

	virtual void ShowSalaryInfo(void) const = 0;	// ���� �����Լ�
};

class CPermanentWorker : public CEmployee
{
private:
	int salary;	// �� �޿�
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
	int workTime;		// �� �޿� ���� �ð��� �հ�
	int payPerHour;		// �ð��� �޿�
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
	int salesResult;		// �� �ǸŽ���
	double bonusRatio;		// �󿩱� ����
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
		return CPermanentWorker::GetPay()	// CPermanentWorker�� GetPay �Լ� ȣ��.
			+ (int)(salesResult * bonusRatio);
	}

	void ShowSalaryInfo(void) const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;		// SalesWorker�� GetPay �Լ��� ȣ���.
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
		cout << "salary: " << GetPay() << endl;		// SalesWorker�� GetPay �Լ��� ȣ���.
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
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	CEmployeeHandler handler;

	//// ������ ���
	//handler.AddEmployee(new CPermanentWorker("Kim", 1000));
	//handler.AddEmployee(new CPermanentWorker("LEE", 1500));

	//// �ӽ��� ���
	//CTemporaryWorker* alba = new CTemporaryWorker("Jung", 700);
	//alba->AddWorkTime(5);		// 5�ð� ���Ѱ�� ���.
	//handler.AddEmployee(alba);

	//// ������ ���
	//CSalesWorker* seller = new CSalesWorker("Hong", 1000, 0.1);
	//seller->AddSalesResult(7000);		// �������� 7000.
	//handler.AddEmployee(seller);

	// �ؿ� ������ ���
	CForeignSalesWorker* fseller1 = new CForeignSalesWorker("Hong", 1000, 0.1, A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	CForeignSalesWorker* fseller2 = new CForeignSalesWorker("Yoon", 1000, 0.1, B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	CForeignSalesWorker* fseller3 = new CForeignSalesWorker("Lee", 1000, 0.1, C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();

	//// �̹� �޿� �����ؾ� �� �޿��� ����
	//handler.ShowTotalSalary();

	return 0;
}