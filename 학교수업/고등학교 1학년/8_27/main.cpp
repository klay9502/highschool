/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	int state; // error 체크 변수.
	int i, j; // for 루프 변수.
	int a = 0, b = 0, c = 0; // fscanf 변수.
	char c1 = 0, c2 = 0; // fscanf 변수.

	// 쓰기 전용 파일 개방

	FILE *file = fopen("Test1.txt", "wt");

	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	// fprintf 함수의 활용

	for (i = 2; i < 10; i++)
		for (j = 1; j < 10; j++)
			fprintf(file, "%d x %d = %d\n", i, j, i * j);
	
	// 파일의 종결

	state = fclose(file);

	if (state != 0) {
		printf("file close error!\n");
		return 1;
	}

	// 읽기 전용 파일 개방

	file = fopen("Test1.txt", "rt");

	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	// fscanf 함수의 활용

	for (i = 2; i < 10; i++)
		for (j = 1; j < 10; j++)
		{
			fscanf(file, "%d %c %d %c %d", &a, &c1, &b, &c2, &c);
			printf("%d %c %d %c %d\n", a, c1, b, c2, c);
		}

		// 파일의 종결

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
	int state; // error 체크 변수.
	char buf[20];

	// 읽기 전용 파일 개방

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

	// 파일의 종결

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
	int state; // error 체크 변수.
	int age; // 나이 변수.
	char name[20]; // 이름 변수.

	// 쓰기 전용 파일 개방

	FILE *file = fopen("Test.txt", "wt");

	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	for (int i = 1; i <= 5; i++)
	{
		fprintf(stdout, "%d 번 성명입력 : ", i);
		fscanf(stdin, "%s", name);
		fprintf(stdout, "나이입력: ");
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
	int state; // error 체크 변수.
	char buf[20];

	// 읽기 전용 파일 개방

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