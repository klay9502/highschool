/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char str1[5] = "abcd";
	char *str2 = "ABCD";

	printf("%s\n", str1);
	printf("%s\n", str2);

	str1[0] = 'x';
	// str2[0] = 'x'; // Error?!

	printf("%s\n", str1);
	printf("%s\n", str2);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char *p;
	p = "school-bus";

	while(*p != 'h')
		p++;

	printf("%s\n", p);
	_getch();
}
*/

// p156 ��������2

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char ch = 'A';
	char s[] = "mububja";
	char *pt;
	int i;

	pt = &ch;

	printf("ch = %c, *pt = %c\n", ch, *pt);
	printf("\npointer ������ ũ�� = %d\n", sizeof(pt));
	
	pt = s;

	printf("s = %u, %s, sizeof(s) = %d\n", s, s, sizeof(s));

	for (i = 0; i < sizeof(s) - 1; i++)
	{
		printf("s + %d = %u, pt + %d = %u\t", i, s + i, i, pt + i);
		printf("s[%d] = %c, pt[%d] = %c\n", i, s[i], i, pt[i]);
	}

	printf("\npointer������ ������Ű�� ó��\n");

	for (i = 0; i < sizeof(s) - 1; i++)
	{
		printf("pt = %u, *pt = %c\n", pt, *pt);
		pt++;
	}

	printf("\nwhile���� ��� ���ڿ� ���\n");

	pt = s;

	while((*pt) != NULL)
	{
		putchar(*pt);
		pt++;
	}
	putchar('\n');
	_getch();
}
*/

// p158 ����24

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char a[8];
	char *p;
	int n;

	p = &a[0]; // �迭 �ּҸ� ������ �ּҿ� ����

	printf("���ڿ� �Է�?");
	scanf("%8c", p); // Ű���忡 �ڷ� �Է�
	for (n = 0; n < 8; n++)
		printf("���ڿ���� = %c\n", *(p + n));
	_getch();
}
*/

// p158 ����25

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char line[20];
	char *r;
	int n;

	r = gets(line); // ���ڿ��� �Է�
	for (n = 0; n < 12; n++)
		printf("%c", *(r + n));
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
	int i;
	int num;
	char *str = "clay9502";
	
	printf("���� ID�� %s �̰�", str);
	printf("���ڿ� ũ�� : %d�̴�.\n\n", strlen(str));

	num = strlen(str);

	for (i = 0; i < num; i++)
	{
		printf("%2d��° ���� ������ : %s\n", i, (str + i));
	}
	_getch();
}
*/

// p158 ����26

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char a[3][8];

	scanf("%s", a[0]);
	scanf("%s", a[1]);
	scanf("%s", a[2]);

	printf("%s, %s, %s\n", a[0], a[1], a[2]);
	_getch();
}
*/

// p158 ����27

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char line1[20], line2[20], line3[20];
	char *a[3];

	a[0] = "	"; // a[0]�� ��Ī�ϴ� �ּ� ���� �������� ����
	a[1] = "	";
	a[2] = "	";

	a[0] = gets(line1); // a[0]�� ��Ī�ϴ� �ּ� ���� ���ڿ� ����
	a[1] = gets(line2);
	a[2] = gets(line3);

	printf("%s, %s, %s\n", a[0], a[1], a[2]);
	_getch();
}
*/

// p160 ����28

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	static char *a[4] = {
		"Kim", "Lee", "Pak", "Cho"
	};
	int i, j;

	printf("a[0]�� ���� �ּ� = %c\n", *a[0]);
	printf("a[1]�� ���� �ּ� = %c\n", *a[1]);
	printf("a[2]�� ���� �ּ� = %c\n", *a[2]);
	printf("a[3]�� ���� �ּ� = %c\n", *a[3]);
	printf("===<�迭�� �� ���� ��>===\n");

	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			printf("a[%d][%d] == %c\n", i, j, a[i][j]);
	_getch();
}
*/

// p161 ����29

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char *p[4];
	int i;

	p[0] = "red";
	p[1] = "yellow";
	p[2] = "blue";
	p[3] = "green";

	for (i = 0; i < 4; i++)
		printf("%s\n", p[i]); // ���ڿ��� ���� �ּҸ� %s�� ǥ��
	_getch();
}
*/

// p161 ����30

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	static char *str[] = {
		"Computer", "Hardware", "Software"
	};
	int i;

	for (i = 0; i <= 2; i++)
		printf("str[%d] --> %s\n", i, str[i]);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 10;
	char b = 'A';
	float c = 100.11;
	void *ptr;

	ptr = &a;

	printf("ptr�� ī��Ű�� ���� ������ : %d\n", *((int *)ptr));

	ptr = &b;

	printf("ptr�� ī��Ű�� ���� ������ : %c\n", *((char *)ptr));

	ptr = &c;

	printf("ptr�� ī��Ű�� ���� ������ : %.2f\n", *((float *)ptr));
	_getch();
}
*/