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

	printf("program 종료\n");

	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>

int main()
{
	fputs("fputs함수에 의한 출력.", stdout);
	fputs("I LOVE C-언어", stdout);

	fputs("\n", stdout);

	puts("fputs함수에 의한 출력.");
	puts("I LOVE C-언어");

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

	fputs("문자열을 입력하세요 :", stdout);
	fgets(str,sizeof(str), stdin); // 인자 3개 기억요망

	fputs("입력된 문자열: ", stdout);
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
	
	// 파일의 개방
	FILE *file = fopen("Tset.txt", "wt");
	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	// puts 함수의 활용
	puts("Don't Worry!");

	// fputs 함수의 활용1
	fputs("Don't Worry!", stdout);

	// fputs 함수의 활용2
	fputs("Don't Worry!", file);

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
	int state;
	char buf[30];
	
	// 파일의 개방
	FILE *file = fopen("Tset.txt", "rt");
	if (file == NULL) {
		printf("file open error!\n");
		return 1;
	}

	// fgets 함수의 활용1
	fputs("데이터 입력 : ", stdout);
	fgets(buf, sizeof(buf), stdin);
	puts(buf);

	// fgets 함수의 활용1
	fgets(buf, sizeof(buf), file);
	puts(buf);

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