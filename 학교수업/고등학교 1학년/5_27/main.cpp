// p71 9-3

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j, p_j = 1;
	int x, y;

	printf("�� ���Դϱ�? "); scanf("%d",&x);
	printf("�� ���Դϱ�? "); scanf("%d",&y);

	for (i = 1; i <= x; i++)
	{
		for (j = 1; j <= y; j++)
		{
			if (p_j >= 10)
				p_j = 0;
			printf("%d", p_j);
			p_j++;
		}
		printf("\n");
		p_j--;
	}

	_getch();
	return 0;
}
*/

// p71 9-4

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j;
	int x, y;
	bool code = 0;

	printf("�� ���Դϱ�? "); scanf("%d",&x);
	printf("�� ���Դϱ�? "); scanf("%d",&y);

	for (i = 0; i < x; i++)
	{
		switch (code) {
		case 0:
			for (j = 0; j < y; j++)
			{
				if (j % 2 == 0)
					printf("O");
				else		// j % 2 == 1
					printf("X");
			}
			printf("\n");
			code = 1;
			break;
		case 1:
			for (j = 0; j < y; j++)
			{
				if (j % 2 == 0)
					printf("X");
				else		// j % 2 == 1
					printf("O");
			}
			printf("\n");
			code = 0;
		}
	}
	_getch();
	return 0;
}
*/

// p72 9-5

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i, j = 'A';
	
	for (i = 1; j <= 'Z'; i++, j++)
	{
		printf("%c",j);
		if (i % 4 == 0)
			printf("\n");
	}
	_getch();
	return 0;
}
*/

// p72 9-6

/*

#include <stdio.h>
#include <conio.h>

int main(void)
{
	char in;
	
	printf("������ ���ĺ��� �Է��Ͻÿ� :");
	scanf("%c", &in);
	for (int i = 1; ;i++)		// ���� ����
	{
		for (int j = 0; j < i; j++)
		{
			printf("%c",in);
			in++;
			if (in > 'z')
				break;
		}
		if (in > 'z')
				break;
		printf("\n");
	}
	_getch();
	return 0;
}
*/

// p72 9-7

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int cheak = 0;
	int result = 0;
	int next = 0;

	printf("1���� 1000������ �� �߿��� �Ҽ��� ���ϴ� ���α׷�\n\n");
	for (int i = 2; i <= 1000; i++)		// 1�� �Ҽ��� �ƴ�. 2���� �ص� �������
	{
		for (int j = 2; j <= i; j++)
		{
			if (i % j == 0)
				cheak++;
		}

		if (cheak == 1)
		{
			printf("%d\t",i);
			result++;
			next++;
		}
		cheak = 0;
		if (next == 8)
		{
			printf("\n");
			next = 0;
		}
	}
	printf("\n");
	printf("1���� 1000������ �Ҽ��� %d�� �Դϴ�.\n", result);
	_getch();
	return 0;
}
*/

// continue ���� 1

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	i = j = 0;

	printf("continue���� �׽�Ʈ�Դϴ�.\n");

	do {
		printf("do_while���� %d��° �ݺ��Դϴ�.\n",i);
		for (j = 0; j < 10; j++)
		{
			if (j == 5)
				continue;
			printf("for���� %d��° �ݺ��Դϴ�.\n",j);
		}
		i++;
	} while (i < 5);

	printf("���α׷��� �����մϴ�.\n");
	_getch();
}
*/

// continue ���� 2

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int i = 0, hap = 0;

	while (i <= 100)
	{
		i++;
		if (i % 2 == 1)
			continue;
		hap += i;
		if (hap > 1000)
			break;
	}
	printf("i�� ���� %d�� �� ���� 1000�� �Ѿ����ϴ�.\n",i);
	_getch();
	return 0;
}
*/

// goto ���� 1

#include <stdio.h>
#include <conio.h>

int main(void)
{
	int a = 1;
here:
	a++;
	if (a == 2)
		goto here;
	printf("%d\n",a);
	_getch();
	return 0;
}