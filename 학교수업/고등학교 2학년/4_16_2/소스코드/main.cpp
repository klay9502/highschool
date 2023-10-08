//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class MyFriendInfo
//{
//private:
//	char* name;
//	int age;
//public:
//	MyFriendInfo(char* name, int age) : age(age)
//	{
//		this->name = new char[strlen(name)+1];
//		strcpy(this->name, name);
//	}
//
//	void ShowMyFriendInfo(void)
//	{
//		cout << "Name: " << name << endl;
//		cout << "Age: " << age << endl;
//	}
//	~MyFriendInfo()
//	{
//		delete []name;
//	}
//};
//
//class MyFriendDatailInfo : public MyFriendInfo
//{
//private:
//	char* address;
//	char* phone;
//public:
//	MyFriendDatailInfo(char* name, int age, char* address, char* phone) : MyFriendInfo(name, age)
//	{
//		this->address = new char[strlen(address)+1];
//		this->phone = new char[strlen(phone)+1];
//		strcpy(this->address, address);
//		strcpy(this->phone, phone);
//	}
//	void ShowMyFriendDatailInfo(void)
//	{
//		ShowMyFriendInfo();
//		cout << "Address: " << address << endl;
//		cout << "PhoneNumber: " << phone << endl;
//	}
//	~MyFriendDatailInfo()
//	{
//		delete []address;
//		delete []phone;
//	}
//};
//
//int main(void)
//{
//	MyFriendDatailInfo Human_1("김민규", 18, "남구 무거동", "010-1234-5678");
//	MyFriendDatailInfo Human_2("김종민", 18, "창원 도계동", "010-8566-9502");
//
//	Human_1.ShowMyFriendDatailInfo();
//	cout << endl;
//	Human_2.ShowMyFriendDatailInfo();
//
//	return 0;
//}

//#include <iostream>
//#include <cstring>
//using namespace std;
//
//class Computer
//{
//private:
//	char* owner;
//public:
//	Computer(char* owner)
//	{
//		this->owner = new char[strlen(owner) + 1];
//		strcpy(this->owner, owner);
//	}
//	void Calculate(void)
//	{
//		cout << "요청 내용을 계산합니다." << endl;
//	}
//	~Computer()
//	{
//		delete[]owner;
//	}
//};
//
//class NotebookComp : public Computer
//{
//private:
//	int Battery;
//public:
//	NotebookComp(char* name, int initChag) : Computer(name), Battery(initChag)
//	{
//		// empty...
//	}
//	void Charging(void)
//	{
//		Battery += 5;
//	}
//	void UseBattery(void)
//	{
//		Battery -= 1;
//	}
//	void MovingCal(void)
//	{
//		if (GetBatteryInfo() < 1)
//		{
//			cout << "충전이 필요합니다." << endl;
//			return;
//		}
//		cout << "이동하면서 ";
//		Calculate();
//		UseBattery();
//	}
//	int GetBatteryInfo()
//	{
//		return Battery;
//	}
//};
//
//class TabletNotebook : public NotebookComp
//{
//private:
//	char* regstPenModel;
//public:
//	TabletNotebook(char* name, int initChag, char* pen) : NotebookComp(name, initChag)
//	{
//		regstPenModel = new char[strlen(pen) + 1];
//		strcpy(regstPenModel, pen);
//	}
//	void Write(char* penInfo)
//	{
//		if (GetBatteryInfo() < 1)
//		{
//			cout << "충전이 필요합니다." << endl;
//			return;
//		}
//		if (strcmp(regstPenModel, penInfo) != 0)
//		{
//			cout << "등록된 팬이 아닙니다.";
//			return;
//		}
//		cout << "필기 내용을 처리합니다." << endl;
//		UseBattery();
//	}
//	~TabletNotebook()
//	{
//		delete[]regstPenModel;
//	}
//};
//
//int main(void)
//{
//	NotebookComp nc("김민규", 5);
//	TabletNotebook tn("김종민", 5, "ISE-241-242");
//	nc.MovingCal();
//	tn.Write("ISE-241-242");
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Gun
//{
//private:
//	int bullet;	// 장전된 총알의 수
//public:
//	Gun(int bNum) : bullet(bNum)
//	{
//		// empty...
//	}
//	void Shot()
//	{
//		cout << "빵!" << endl;
//		bullet--;
//	}
//};
//
//class Police
//{
//private:
//	int handcuffs;
//	Gun* pistol;
//public:
//	Police(int bNum, int bcuff) : handcuffs(bcuff)
//	{
//		if (bNum > 0)
//		{
//			pistol = new Gun(bNum);
//		}
//		else
//		{
//			pistol = NULL;
//		}
//	}
//	void PutHandcuff(void)
//	{
//		cout << "잡았다! 요놈!" << endl;
//		handcuffs--;
//	}
//	void Shot(void)
//	{
//		if (pistol == NULL)
//		{
//			cout << "헛빵!" << endl;
//		}
//		else
//		{
//			pistol->Shot();
//		}
//	}
//	~Police()
//	{
//		if (pistol != NULL)
//		{
//			delete pistol;
//		}
//	}
//};
//
//int main(void)
//{
//	Police pman1(5, 3);
//	pman1.Shot();
//	pman1.PutHandcuff();
//
//	Police pman2(0, 3);
//	pman2.Shot();
//	pman2.PutHandcuff();
//
//	return 0;
//}

#include <iostream>
using namespace std;

class Book
{
private:
	char* title;	// 책의 제목
	char* isbn;		// 국제표준도서번호
	int price;		// 책의 정가
public:
	Book(char* title, char* isbn, int price) : price(price)
	{
		this->title = new char[strlen(title) + 1];
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->title, title);
		strcpy(this->isbn, isbn);
	}
	~Book()
	{
		delete[]isbn;
		delete[]title;
	}
	void ShowBookInfo(void)
	{
		cout << "제목: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "가격: " << price << endl;
	}
};

class EBook : public Book
{
private:
	char* DRMKey;	// 보안관련 키
public:
	EBook(char* title, char* isbn, int price, char* DRMKey) : Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}

	void ShowEBookInfo(void)
	{
		ShowBookInfo();
		cout << "인증키: " << DRMKey << endl;
	}

	~EBook()
	{
		delete[]DRMKey;
	}
};

int main(void)
{
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;

	EBook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();

	return 0;
}