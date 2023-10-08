//#include <iostream>
//using namespace std;
//
//class Temporary
//{
//private:
//	int num;
//public:
//	Temporary(int num) : num(num)
//	{
//		cout << "Create Object: " << num << endl;
//	}
//	~Temporary()
//	{
//		cout << "Destroy Object: " << num << endl;
//	}
//	void ShowTempInfo(void)
//	{
//		cout << "My name is " << num << endl;
//	}
//};
//
//int main(void)
//{
//	Temporary(100);
//	cout << "*********************** after make!" << endl << endl;
//
//	Temporary(200).ShowTempInfo();
//	cout << "*********************** after make!" << endl << endl;
//
//	const Temporary &ref = Temporary(300);
//	cout << "*********************** end of main!" << endl << endl;
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//class SoSimple
//{
//private:
//	int num;
//public:
//	SoSimple(int num) : num(num)
//	{
//		cout << "New Object: " << this << endl;
//	}
//	SoSimple(const SoSimple &copy) : num(copy.num)
//	{
//		cout << "New Copy Object: " << this << endl;
//	}
//	~SoSimple()
//	{
//		cout << "Destroy Object: " << this << endl;
//	}
//};
//
//SoSimple SimpleFuncObj(SoSimple obj)
//{
//	cout << "Para ADR: " << &obj << endl;
//	return obj;
//}
//
//int main(void)
//{
//	SoSimple obj(7);
//	SimpleFuncObj(obj);
//
//	cout << endl;
//	SoSimple &tempRef = SimpleFuncObj(obj);
//	cout << "Return Obj: " << &tempRef << endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class SoSimple
//{
//private:
//	static int simObjCnt;
//public:
//	SoSimple()
//	{
//		simObjCnt++;
//		cout << simObjCnt << "번째 SoSimple 객체" << endl;
//	}
//	~SoSimple()
//	{
//		// empty...
//	}
//};
//int SoSimple::simObjCnt = 0;
//
//class SoComplex
//{
//private:
//	static int cmxObjCnt;
//public:
//	SoComplex()
//	{
//		cmxObjCnt++;
//		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
//	}
//	SoComplex(SoComplex &copy)
//	{
//		cmxObjCnt++;
//		cout << cmxObjCnt << "번째 SoComplex 객체" << endl;
//	}
//	~SoComplex()
//	{
//		// empty...
//	}
//};
//int SoComplex::cmxObjCnt = 0;
//
//int main(void)
//{
//	SoSimple sim1;
//	SoSimple sim2;
//
//	SoComplex cmx1;
//	SoComplex cmx2 = cmx1;
//	SoComplex();
//
//	return 0;
//}
//
//#include <iostream>
//using namespace std;
//
//class SoSimple
//{
//public:
//	static int simObjCnt;
//public: // 불필요하지만 변수와 함수의 구분을 목적으로 삽입하기도 함.
//	SoSimple()
//	{
//		simObjCnt++;
//	}
//	~SoSimple()
//	{
//		// empty...
//	}
//};
//int SoSimple::simObjCnt = 0;
//
//int main(void)
//{
//	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
//	SoSimple sim1;
//	SoSimple sim2;
//
//	cout << SoSimple::simObjCnt << "번째 SoSimple 객체" << endl;
//	cout << sim1.simObjCnt << "번째 SoSimple 객체" << endl;
//	cout << sim2.simObjCnt << "번째 SoSimple 객체" << endl;
//
//	return 0;
//}

#include <iostream>
using namespace std;

class SoSimple
{
private:
	int num1;
	mutable int num2; // const 함수에 대해 예외를 둔다!
public:
	SoSimple(int num1, int num2) : num1(num1), num2(num2)
	{
		// empty...
	}
	void ShowSimpleData() const
	{
		cout << num1 << "," << num2 << endl;
	}
	void CopyToNum2() const
	{
		num2 = num1;
	}
};

int main(void)
{
	SoSimple sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();

	return 0;
}