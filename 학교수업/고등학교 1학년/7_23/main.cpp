/*
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

char question[5][5] = {
	{'-', '-', '-', '*', '*'},
	{'*', '*', '-', '*', '*'},
	{'*', '*', '-', '-', '-'},
	{'*', '*', '*', '-', '*'},
	{'-', '-', '-', '-', '*'}
};

char question_number[5][5] = {
	{'1', ' ', '2', ' ', ' '},
	{' ', ' ', ' ', ' ', ' '},
	{' ', ' ', '3', '4', ' '},
	{' ', ' ', ' ', ' ', ' '},
	{'5', ' ', ' ', ' ', ' '}
};

int check_answer_number = 0;

void print_question()
{
	system("cls");

	for (int i = 0; i < 5; i++)
	{
		// ���� ��ȣ ���
		for (int j = 0; j < 5; j++)
			printf("%3c", question_number[i][j]);
		printf("\n");

		// ���� ���
		for (int j = 0; j < 5; j++)
			printf("%3c", question[i][j]);
		printf("\n");
	}

	printf("1���� ���ι��� : ���ٶ� �ǹ��� ����ܾ�\n");	// ask
	printf("2���� ���ι��� : �ѱ���۰����� �̴ϼ�\n");	// kbs
	printf("3���� ���ι��� : ������ȣ�� ��Ÿ���� ����ܾ�\n");	//sos
	printf("4���� ���ι��� : ��ũ����Ʈ�� ������ ���� �� �ϳ�\n");	//oak
	printf("5���� ���ι��� : å���� ��Ÿ���� ����ܾ�\n");	//desk
}

// ���� üũ

int check_answer(char question_number, char *answer)
{
	char answer1[] = {'a', 's', 'k', '\0'};
	char answer2[] = {'k', 'b', 's', '\0'};
	char answer3[] = {'s', 'o', 's', '\0'};
	char answer4[] = {'o', 'a', 'k', '\0'};
	char answer5[] = {'d', 'e', 's', 'k', '\0'};

	// �������� �迭 �ٲٱ�
	switch (question_number) {
	case '1':
		if (!strcmp(answer1, answer)) {	// strcmp(answer1, answer) == 0
			question[0][0] = 'a';
			question[0][1] = 's';
			question[0][2] = 'k';

			return 1;
		} else {
			return 0;
		}
	case '2':
		if (!strcmp(answer2, answer)) {
			question[0][2] = 'k';
			question[1][2] = 'b';
			question[2][2] = 's';

			return 1;
		} else {
			return 0;
		}
	case '3':
		if (!strcmp(answer3, answer)) {
			question[2][2] = 's';
			question[2][3] = 'o';
			question[2][4] = 's';

			return 1;
		} else {
			return 0;
		}
	case '4':
		if (!strcmp(answer4, answer)) {
			question[2][3] = 'o';
			question[3][3] = 'a';
			question[4][3] = 'k';

			return 1;
		} else {
			return 0;
		}
	case '5':
		if (!strcmp(answer5, answer)) {
			question[4][0] = 'd';
			question[4][1] = 's';
			question[4][2] = 'e';
			question[4][3] = 'k';

			return 1;
		} else {
			return 0;
		}
	default:
		return 0;
	}
}

void main()
{
	char question_number;
	char answer[6];
	int check_n;

	print_question();

	while(check_answer_number < 5)
	{
		printf("������ȣ = ");
		question_number = getchar();
		fflush(stdin);
		printf("�� = ");
		gets(answer);

		check_n = check_answer(question_number, answer);
		check_answer_number += check_n;
		check_n = 0;
		print_question();
	}
}
*/

// p119 ����16

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int m = 0;
	char str[6];

	str[0] = 'K';
	str[1] = 'O';
	str[2] = 'R';
	str[3] = 'E';
	str[4] = 'A';
	str[5] = '\0';

	while (m < 6)
	{
		putchar(str[m]);
		m++;
	}
	putchar('\n');
	_getch();
}
*/

// p119 ����17

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int i, j;
	char a[2][5] = {
		{'S', 'E', 'O', 'U', 'L'},
		{'B', 'U', 'S', 'A', 'N'}
	};

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
			printf("\na[%d][%d] = %c", i, j, a[i][j]);
		printf("\n");
	}

	_getch();
}
*/

// ppt ���ڿ��� �迭

/*
#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
	char st[20];
	int num;
	
	strcpy(st, "I like C-Language.");

	for (num = 0; st[num] != '\0'; num++);
	printf("No, of characters = %d\n", num);
	_getch();
}
*/

// p121 ����18

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char a[6];
	static char b[] = {'S', 'E', 'O', 'U', 'L', '\0'};	// ���� �迭�� �ʱ�ȭ
	int i;

	a[0] = 'K', a[1] = 'O', a[2] = 'R';	// �迭���ҿ� ���ڻ�� ����
	a[3] = 'E', a[4] = 'A', a[5] = '\0';

	for (i = 0; i < 6; i++)
		printf("a[%d] = %c\n", i, a[i]);

	printf("���ڿ�(1) = %s\n", a);	// a[6]�� ������� �ʰ�, �迭�� a�� ����Ѵ�.
	printf("���ڿ�(2) = %s\n", b);	// b[]�� ������� �ʰ�, �迭�� a�� ����Ѵ�.

	_getch();
}
*/

// p121 ����19

/*
#include <stdio.h>
#include <conio.h>

char a[] = "PAPER";	// ���ڹ迭 �ʱ�ȭ

void main()
{
	printf("a[] = %s\n", a);
	printf("%c%c%c%c%c\n", a[0], a[1], a[2], a[3], a[4]);
	_getch();
}
*/

// p121 ����20

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	static char sta[5] = {'A', 'B', 'C', 'D', '\0'};
	static char stb[5] = {'A', 'B', 'C', 'D'};
	static char stc[5] = "ABCD";
	int i;

	printf("sta = %s\n", sta);
	printf("stb = %s\n", stb);
	printf("stc = %s\n", stc);
	printf("�� ���ھ� ���ε��� ����غ���.\n");

	for (i = 0; i < 5; i++)
		putchar(sta[i]);
	putchar('\n');

	printf("�迭 �� �Ϻθ� �ٲ� �� ����غ���.\n");
	sta[1] = 'X';
	sta[3] = 'Y';

	printf("sta = %s\n", sta);
	_getch();
}
*/

// p122 ��������5

/*
#include <stdio.h>
#include <ctype.h>
#include <conio.h>

void main()
{
	char str[80];
	int i;

	printf("���ڿ� �빮�� �Է�\n");
	gets(str);
	printf("�Է��� ���ڿ� �ҹ��� ���\n");
	for (i = 0; str[i]; i++)
		printf("%c", tolower(str[i]));
	putchar('\n');
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char str[] = "ABC";

	printf("str = %s\n", str);

	str[0] = '\0';

	puts("���ڿ� str�� �����ڿ��� �Ǿ����ϴ�.");
	printf("str = %s\n", str);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	char str[100];
	char MAX;
	int i = 1;

	printf("���ڿ��� �Է��Ͻÿ�. : ");
	scanf("%s", str);

	MAX = str[0];

	for (int i = 1; str[i] != '\0'; i++)
	{
		if (MAX < str[i])
			MAX = str[i];
	}

	printf("�ƽ�Ű �ڵ尪�� ���� ū ����: %c", MAX);
	_getch();
}
*/

/*
#include <stdio.h>
#include <string.h>
#include <Windows.h>

void main()
{
	int cnt = 0;	// �迭�� �������� ����Ű�� ����
	char mes[] = "KimJongMin ";
	int len = strlen(mes);

	printf("�������Դϴ�.\n");

	while(1)
	{
		printf("\r");

		for (int i = 0; i < len;i++)
		{
			if (cnt + i < len)
				printf("%c", mes[cnt + i]);
			else
				printf("%c", mes[cnt + i - len]);
		}

		// (int i = cnt; i < len; i++)
		//	printf("%c", mes[i]);
		//for (int i = 0; i < cnt; i++)
		//	printf("%c", mes[i]);

		Sleep(2000);
		cnt++;

		if (cnt == len)
			cnt = 0;
	}
}
*/

#include <stdio.h>
#include <conio.h>

void main()
{
	char str[100];
	int i = 0, idx = 0;

	printf("���ڿ��� �Է����ּ���. : ");
	scanf("%s", str);

	for (i = 0; str[i] != '\0'; i++)
	{
		if ('0' < str[i] && str[i] > '9')
			continue;
		else
		{
			str[idx] = str[i];
			idx++;
		}
	}

	puts("���ڹ��ڸ� �����߽��ϴ�.\n");
	printf("str = %s\n", str);

	_getch();
}