/*
#include <stdio.h>
#include <conio.h>

int main()
{
	char ch = 0;

	while (ch != EOF)
	{
		ch = fgetc(stdin);
		// ch = getchar();
		fputc(ch, stdout);
		// putchar(ch);
	}

	printf("program ����\n");

	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>

int main()
{
	fputs("fputs�Լ��� ���� ���.", stdout);
	fputs("I LOVE C-���", stdout);

	fputs("\n", stdout);

	puts("fputs�Լ��� ���� ���.");
	puts("I LOVE C-���");

	_getch();
	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>

int main()
{
	char str[10];

	fputs("���ڿ��� �Է��ϼ��� :", stdout);
	fgets(str,sizeof(str), stdin); // ���� 3�� �����

	fputs("�Էµ� ���ڿ�: ", stdout);
	fputs(str, stdout);

	_getch();
	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int state;
	
	// ������ ����
	FILE *file = fopen("Tset.txt", "wt");
	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	// puts �Լ��� Ȱ��
	puts("Don't Worry!");

	// fputs �Լ��� Ȱ��1
	fputs("Don't Worry!", stdout);

	// fputs �Լ��� Ȱ��2
	fputs("Don't Worry!", file);

	// ������ ����
	state = fclose(file);
	if (state != 0) {
		printf("file close error!\n");
		return 1;
	}

	_getch();
	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int state;
	char buf[30];
	
	// ������ ����
	FILE *file = fopen("Tset.txt", "rt");
	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	// fgets �Լ��� Ȱ��1
	fputs("������ �Է� : ", stdout);
	fgets(buf, sizeof(buf), stdin);
	puts(buf);

	// fgets �Լ��� Ȱ��1
	fgets(buf, sizeof(buf), file);
	puts(buf);

	// ������ ����
	state = fclose(file);
	if (state != 0) {
		printf("file close error!\n");
		return 1;
	}

	_getch();
	return 0;
}
*/