#include <iostream>
using namespace std;

class AAA
{
public:
	virtual void fct(void)
	{
		cout << "AAA" << endl;
	}
};

class BBB : public AAA
{
public:
	void fct(void)
	{
		cout << "BBB" << endl;
	}
};

class CCC : public BBB
{
public:
	void fct(void)
	{
		cout << "CCC" << endl;
	}
};

int main(void)
{
	BBB* b = new CCC;
	b->fct();

	AAA* a = b;
	a->fct();

	delete b;
	return 0;
}