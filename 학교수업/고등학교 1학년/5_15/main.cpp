/*
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	int num;

	printf("0~2 ������ ���� �߻� ����~!\n");
	srand(time(NULL));
	num = rand()%3;

	switch (num) {
		case 0:
			puts("0");
			break;
		case 1:
			puts("1");
			break;
		case 2:
			puts("2");
			break;
		default:
			puts("�߸��� ���� �߻�"); }
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;

	printf("����� ���� ����Ͻʴϱ�? (y or n)\n");
	scanf("%c",&ch);
	switch (ch) {
	case 'y':
		puts("���� ����� ����մϴ�.");
		break;
	case 'n':
		puts("�׷��� ���� ����� �����ϴ�.");
		break;
	default:
		puts("�߸��� �Է�."); }
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char Grade;

	printf("�������� ���� ������ �Է��ϼ���.\n");
	printf("���� ����: "); scanf("%c",&Grade);

	switch (Grade) {
	case 'A':
		printf("100�� >= ���� ���� >= 91��");
		break;
	case 'B':
		printf("90�� >= ���� ���� >= 81��");
		break;
	case 'C':
		printf("80�� >= ���� ���� >= 71��");
		break;
	case 'D':
		printf("70�� >= ���� ���� >= 61��");
		break;
	default:
		printf("���� ������ 60�� ����"); }
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	float num,num2,result;
	char code;

	printf("��Ģ������ ������ ���� ���α׷�\n");
	printf("(�Ǽ�*��ȣ*�Ǽ�) : "); scanf("%f%c%f",&num,&code,&num2);

	switch (code) {
	case '+':	// '+' ����
		result = num + num2;
		break;
	case '-':	// '-' ����
		result = num - num2;
		break;
	case '*':	// '*' ����
		result = num * num2;
		break;
	case '/':	// '/' ����
		result = num / num2;
		break;
	default:
		printf("�߸��� Ű����\n"); }
	printf("%.2f %c %.2f = %.2f\n",num,code,num2,result);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int Grade;
	int code;

	printf("���� ����\n");
	printf("�Է� : "); scanf("%d",&Grade);

	code = Grade / 10;

	switch (code) {
	case 10:	// 90 ~ 100��
	case 9:
		printf("��� 'A'");
		break;
	case 8:		// 80 ~ 89��
		printf("��� 'B'");
		break;
	case 7:		// 70 ~ 79��
		printf("��� 'C'");
		break;
	case 6:		// 60 ~ 69��
		printf("��� 'D'");
		break;
	default:	// 60�� �̸�
		printf("��� 'F'"); }
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int num;

	for (num = 1; num <= 10; num++)
		printf("%d",num);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	
	printf("i�� �ʱⰪ = 0 \n\n");
	
	for (i = 0; i < 10; i++)
		printf("%d��° ����, ���� i�� ��: %d\n",i+1,i);
	printf("\nfor�� �Ϸ� �� i�� �� = %d\n",i);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char ch;

	printf("���ĺ� ����ϱ�\n");
	for(ch = 'A'; ch <= 'Z'; ch++)
		printf("%c",ch);
	printf("\n");
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int num;
	int b = 0;
	int c = 0;

	puts("3�� ����� 7�� ��� ���� ����. 1���� ������ �� �߿�?");

	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		if (i % 3 == 0)
			b++;
		if (i % 7 == 0)
			c++;
	}
	printf("1���� %d���� 3�� ����� �� %d��, 7�� ����� �� %d�� �Դϴ�.\n",num,b,c);
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	int i;
	int num;
	int three = 0,seven = 0;
	int t_result = 0,s_result = 0;

	puts("3�� ���, 7�� ����� ����. 1���� ������ �� �߿�?");

	scanf("%d", &num);

	for (i = 1; i <= num; i++)
	{
		three++;
		seven++;
		if (i % 3 == 0)
			t_result += three;
		if (i % 7 == 0)
			s_result += seven;
	}
	printf("1���� %d���� 3�� ����� ���� %d, 7�� ��� ���� %d �Դϴ�.\n",num,t_result,s_result);
	_getch();
}