/*
#include <iostream>

using namespace std;

void SwapByRef2(int &ref1, int &ref2)
{
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;

	SwapByRef2(val1, val2);
	cout<<"val1: "<<val1<<endl;
	cout<<"val2: "<<val2<<endl;
	return 0;
}
*/

/*
#include <iostream>

using namespace std;

struct _Person {
	int age;
	char name[20];
	char personnalID[20];
};

typedef struct _Person Person;

void ShowData(const Person &p)
{
	cout<<"******* 개인 정보 출력 *******"<<endl;
	cout<<"이    름: " << p.name<<endl;
	cout<<"주민번호: " << p.personnalID<<endl;
	cout<<"나    이: " << p.age<<endl;
}

int main(void)
{
	Person man;

	cout<<"이    름:";
	cin>>man.name;

	cout<<"니    이:";
	cin>>man.age;

	cout<<"주민번호:";
	cin>>man.personnalID;

	ShowData(man);

	return 0;
}
*/

#include <iostream>
#include <cstring>

using namespace std;

char *MakeStrAdr(int len)
{
	// char * str = (char*)malloc(sizeof(char)*len);
	char * str = new char[len];

	return str;
}

int main(void)
{
	char * str = MakeStrAdr(20);
	strcpy(str, "I am so happy~");
	cout << str << endl;

	// free(str);
	delete []str;

	return 0;
}