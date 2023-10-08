#include <iostream>

using namespace std;

bool IsPositive(int num)
{
	if (num < 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

int main(void)
{
	bool IsPos;
	int num;

	cout << "Input Number: ";
	cin >> num;

	IsPos = IsPositive(num);

	if (IsPos)
	{
		cout << "Positive Number" << endl;
	}
	else
	{
		cout << "Negative Number" << endl;
	}

	return 0;
}