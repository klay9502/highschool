//#include <iostream>
//using namespace std;
//
//class FruitSeller
//{
//private:
//	const int APPLE_PRICE;
//	int numOfApples;
//	int myMoney;
//public:
//	FruitSeller(int price, int num, int money) : APPLE_PRICE(price), numOfApples(num), myMoney(money)
//	{
//		// empty...
//	}
//
//	int SaleApples(int money)
//	{
//		int num = money / APPLE_PRICE;
//		numOfApples -= num;
//		myMoney += money;
//		
//		return num;
//	}
//	
//	void ShowSalesResult() const
//	{
//		cout << "남은 사과: " << numOfApples << endl;
//		cout << "판매 수익: " << myMoney << endl << endl;
//	}
//};
//
//class FruitBuyer
//{
//private:
//	int myMoney;
//	int numOfApples;
//public:
//	FruitBuyer(int money) : myMoney(money), numOfApples(0)
//	{
//		// empty...
//	}
//
//	void BuyApples(FruitSeller &seller, int money)
//	{
//		numOfApples += seller.SaleApples(money);
//		myMoney -= money;
//	}
//
//	void ShowBuyerResult() const
//	{
//		cout << "현재 잔액: " << myMoney << endl;
//		cout << "사과 개수: " << numOfApples << endl << endl;
//	}
//};
//
//int main(void)
//{
//	FruitSeller seller(1000, 20, 0);
//	FruitBuyer buyer(5000);
//	buyer.BuyApples(seller, 2000);
//
//	cout << "과일 판매자의 현황" << endl;
//	seller.ShowSalesResult();
//	cout << "과일 구매자의 현황" << endl;
//	buyer.ShowBuyerResult();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class AAA
//{
//public:
//	AAA()
//	{
//		cout << "empty object" << endl;
//	}
//
//	void ShowYourName()
//	{
//		cout << "I'm class AAA" << endl;
//	}
//};
//
//class BBB
//{
//private:
//	AAA &ref;
//	const int &num;
//
//public:
//	BBB(AAA &r, const int &n) : ref(r), num(n)
//	{
//		// empty...
//	}
//
//	void ShowYourName()
//	{
//		ref.ShowYourName();
//		cout << "and" << endl;
//		cout << "I ref num" << num << endl;
//	}
//};
//
//int main(void)
//{
//	AAA obj1;
//	BBB obj2(obj1, 20);
//	obj2.ShowYourName();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Time
//{
//private:
//	int hour, min, sec;
//public:
//	Time(int _hour = 0, int _min = 0, int _sec = 0) : hour(_hour), min(_min), sec(_sec)
//	{
//		// empty...
//	}
//
//	void ShowTime()
//	{
//		cout << "[" << hour << "시 " << min << "분 " << sec << "초]" << endl;
//	}
//
//	void ShowTimeInSec()
//	{
//		int temp;
//
//		temp = (hour * 60 * 60) + (min * 60) + sec;
//
//		cout << temp << "초" << endl << endl;
//	}
//};
//
//int main(void)
//{
//	Time time1(10);
//	Time time2(10, 20);
//	Time time3(10, 20, 30);
//
//	time1.ShowTime();
//	time1.ShowTimeInSec();
//
//	time2.ShowTime();
//	time2.ShowTimeInSec();
//
//	time3.ShowTime();
//	time3.ShowTimeInSec();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Person
//{
//private:
//	char *name;
//	char *phone;
//	int	  age;
//public:
//	Person(char* _name, char* _phone, int _age);
//	~Person();
//	void ShowData();
//};
//
//Person::Person(char* _name, char* _phone, int _age)
//{
//	cout << "생성자 호출" << endl;
//
//	name = new char[strlen(_name) + 1];
//	strcpy(name, _name);
//
//	phone = new char[strlen(_phone) + 1];
//	strcpy(phone, _phone);
//
//	age = _age;
//}
//
//Person::~Person()
//{
//	cout << "소멸자 호출" << endl;
//	delete[]name;
//	delete[]phone;
//}
//
//void Person::ShowData()
//{
//	cout << "name: " << name << endl;
//	cout << "phone: " << phone << endl;
//	cout << "age: " << age << endl;
//}
//
//int main(void)
//{
//	Person human("김종민", "010-8566-9502", 18);
//	human.ShowData();
//
//	return 0;
//}

#include <iostream>
#include <cstring>
using namespace std;

class Person
{
private:
	char *name;
	int age;
public:
	Person(char *myname, int myage)
	{
		int len = strlen(myname) + 1;
		
		name = new char[len];
		strcpy(name, myname);
		age = myage;
	}

	Person()
	{
		name = NULL;
		age = 0;
		cout << "called Person()" << endl;
	}

	void SetPersonInfo(char *myname, int myage)
	{
		name = myname;
		age = myage;
	}

	void ShowPersonInfo() const
	{
		cout << "이름: " << name << ", ";
		cout << "나이: " << age << endl;
	}
	
	~Person()
	{
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void)
{
	Person parr[3];
	char namestr[100];
	char *strptr;
	int age;
	int len;

	for (int i = 0; i < 3; i++)
	{
		cout << "이름: ";
		cin >> namestr;
		cout << "나이: ";
		cin >> age;
		len = strlen(namestr) + 1;
		strptr = new char[len];
		strcpy(strptr, namestr);
		parr[i].SetPersonInfo(strptr, age);
	}

	for (int i = 0; i < 3; i++)
	{
		parr[i].ShowPersonInfo();
	}

	return 0;
}