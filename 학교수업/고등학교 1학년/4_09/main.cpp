//=========================
// ��¥...2014 / 04 / 09
// ����...'��Ʈ,���� ������'
// ����...'������'
//=========================

// 39p ���� 3-1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;
	int result;
	
	printf("�ϳ��� ������ �Է��ϼ���. :");
	scanf("%d",&num);

	result = num & ~7;

	printf("���� 3��Ʈ�� 0���� ���簪�� %d�Դϴ�\n",result);
	_getch();
}
*/

// 40p ���� 3-2

/*
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

void main()
{
	int Input_code;
	int Play_code;

	printf("�Ʒ��� ������ ���� �� �̿��� �����մϴ�.\n");
	printf("4���� ���� �� ���縦 ���ϴ� �ϳ��� ���Ӹ��� �����ϼ���.\n");
	printf("===========================================================\n");
	printf(": 1.��Ÿ<500��>	2. ����<700��>	3. ī����	4.ũ������\n");
	printf("===========================================================\n");
	scanf("%d",&Input_code);

	printf("%d �� ������ �����ϼ̽��ϴ�\n");

	printf("������ = >");
	Sleep(1000);
	printf(">");
	Sleep(1000);							// ������...
	printf(">");
	Sleep(1000);
	printf(">\n");
	Sleep(1000);

	printf("�����Ϸ�~!!\n");
	printf("���ӿ� ������ ������ ����̽��ϴ�.\n");

	printf("���� ���尡�� = >");
	Sleep(1000);
	printf(">");
	Sleep(1000);
	printf(">");							// ���ɿ��� Ȯ����...
	Sleep(1000);
	printf(">\n\n");
	Sleep(1000);

	printf("������ ������ �����ϼ���.\n");
	printf("===========================================================\n");
	printf(": 1.��Ÿ<500��>	2. ����<700��>	3. ī����	4.ũ������\n");
	printf("===========================================================\n");
	scanf("%d",&Play_code);

	((Input_code & Play_code) == (Input_code | Play_code)) ?		// ������ȣ Ȯ����...
		printf("���ӷε� ��...\n") :
		printf("�� ������ �������� �����̽��ϴ�. ���α׷��� �����մϴ�.\n");

	_getch();
}
*/

// 40p ����10

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float num1, num2;
	float data1, data2;

	num1 = num2 = 4.352;
	data1 = data2 = 3.141592;

	printf("���Կ����ڿ� ���� �˾ƺ��ô�.\n");
	num1 += num2 -= data1 *= data2 /= 2;
	
	printf("num1 : [%-10.3f]\n",num1);
	printf("num2 : [%-10.3f]\n",num2);
	printf("data1 : [%-10.3f]\n",data1);
	printf("data2 : [%-10.3f]\n",data2);
	_getch();
}
*/

// 41p ����11

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 1;
	float b = 3.14;
	double c = 2;
	c += -a++ + ++b;

	printf("c += -a++ + ++b ���� c���� %f �Դϴ�. \n", c);
	_getch();
}
*/

// 42p ��������4

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main()
{
	int Left,Right;
	int bet;
	
	printf("������ �ܷ� ǥ�� ���α׷�\n");
	printf("���� �������� �ܷ��� ����մϴ�.\n");

	srand((int)time(NULL));
	Left = rand()%100;

	printf("������ �������� �ܷ��� ����մϴ�.\n");

	Right = rand()%100;

	printf("���� ������ �ܷ� = %d\n",Left);
	printf("������ ������ �ܷ� = %d\n",Right);

	bet = (Left + Right) / 2;

	(bet < 5) ?
		printf("�������� ��ü�ϼ���.\n") :
		printf("���� ������ �ܷ��� %d%%�Դϴ�.\n",bet);
	_getch();
}
*/