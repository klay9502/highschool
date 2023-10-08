/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int state; // error üũ ����.
	int i, j; // for ���� ����.
	int a = 0, b = 0, c = 0; // fscanf ����.
	char c1 = 0, c2 = 0; // fscanf ����.

	// ���� ���� ���� ����

	FILE *file = fopen("Test1.txt", "wt");

	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	// fprintf �Լ��� Ȱ��

	for (i = 2; i < 10; i++)
		for (j = 1; j < 10; j++)
			fprintf(file, "%d x %d = %d\n", i, j, i * j);
	
	// ������ ����

	state = fclose(file);

	if (state != 0) {
		printf("file close error!\n");
		return 1;
	}

	// �б� ���� ���� ����

	file = fopen("Test1.txt", "rt");

	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	// fscanf �Լ��� Ȱ��

	for (i = 2; i < 10; i++)
		for (j = 1; j < 10; j++)
		{
			fscanf(file, "%d %c %d %c %d", &a, &c1, &b, &c2, &c);
			printf("%d %c %d %c %d\n", a, c1, b, c2, c);
		}

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
	int state; // error üũ ����.
	char buf[20];

	// �б� ���� ���� ����

	FILE *file = fopen("Test1.txt", "r");

	if (file == NULL) {
		printf("file open error! \n");
		return 1;
	}

	while (1)
	{
		if (feof(file) != 0)
			break;
		fgets(buf, sizeof(buf), file);
		fputs(buf, stdout);
	}

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
	int state; // error üũ ����.
	int age; // ���� ����.
	char name[20]; // �̸� ����.

	// ���� ���� ���� ����

	FILE *file = fopen("Test.txt", "wt");

	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	for (int i = 1; i <= 5; i++)
	{
		fprintf(stdout, "%d �� �����Է� : ", i);
		fscanf(stdin, "%s", name);
		fprintf(stdout, "�����Է�: ");
		fscanf(stdin, "%d", &age);
		fprintf(file, "%s %d\n", name, age);
	}

	state = fclose(file);

	if (state != 0) {
		printf("file close error!\n");
		return 1;
	}

	_getch();
	return 0;
}
*/

#include <stdio.h>
#include <conio.h>

int main(void)
{
	int state; // error üũ ����.
	char buf[20];

	// �б� ���� ���� ����

	FILE *file = fopen("mystory.txt", "r");

	if (file == NULL) {
		printf("file open error! \n");
		return 1;
	}

	while (1)
	{
		fgets(buf, sizeof(buf), file);
		if (feof(file) != 0)
			break;
		fputs(buf, stdout);
	}

	state = fclose(file);

	if (state != 0) {
		printf("file close error!\n");
		return 1;
	}

	_getch();
	return 0;
}