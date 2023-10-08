/*
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void main()
{
	char *pBuf, *iBuf;
	int i;

	pBuf = (char*)malloc(10);

	iBuf = pBuf;

	for (i = 0; i < 10; i++)
		*pBuf++ = i + 'A';

	pBuf = iBuf;

	for (i = 0; i < 10; i++)
		printf("%c", *pBuf++);
	
	free(pBuf);
	_getch();	
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	int *str;
	int num;
	int i = 0, sum = 0;

	printf("몇개의 수를 입력하시겠습니까?\n");
	scanf("%d", &num);

	str = (int *)malloc(sizeof(int) * num);

	printf("실제 수를 입력하세요.\n");

	for (i = 0; i < num; i++)
	{
		scanf("%d", &str[i]);
		
		sum += str[i];
	}

	printf("sum = %d\n", sum);
	free(str);

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

int str_equal(char *s1, char *s2)
{
	int i = 0;

	while (1)
	{
		if (s1[i] != s2[i])
			return 0;
		if (s1[i] == '\0' && s2[i] == '\0')
			return 1;
		i++;
	}
}

void main()
{
	char str1[100], str2[100];
	int code;

	printf("문자열을 입력해주세요. : ");
	gets(str1);
	fflush(stdin);
	printf("문자열을 입력해주세요. : ");
	gets(str2);

	code = str_equal(str1, str2);

	switch (code)
	{
	case 0:
		printf("이들 문자열은 다릅니다.\n");
		break;
	case 1:
		printf("이들 문자열은 같습니다.\n");
	}
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void SelFunction(int s);
void Add(void);
void Min(void);

int main(void)
{
	int sel;

	while(1)
	{
		printf("선택 : 덧셈(1), 뺄셈(2), 종료(3)");
		scanf("%d", &sel);
		
		if (sel == 3)
			break;
		SelFunction(sel);
	}

	printf("프로그램이 종료 되었습니다. \n");

}

void SelFunction(int s)
{
	void (*fPtr)(void);
	if (s == 1)
		fPtr = Add;
	else
		fPtr = Min;
	fPtr();
}

void Add(void)
{
	int a, b;
	
	printf("덧셈을 위한 두 개의 숫자 입력 : ");
	scanf("%d %d", &a, &b);
	printf("덧셈 결과 : %d \n\n", a + b);
}

void Min(void)
{
	int a, b;

	printf("뺄셈을 위한 두 개의 숫자 입력 : ");
	scanf("%d %d", &a, &b);
	printf("뺄셈 결과 : %d \n\n", a - b);
}
*/

/*
#include <stdio.h>
#include <conio.h>

enum Days {MON, TUE, WED, THU, FRI, SAT, SUN};

void main()
{
	int day;

	printf("Input a day(0: Monday ~ 6: Sunday) : ");
	scanf("%d", &day);

	switch(day)
	{
	case MON:
		printf("수영을 하세요. \n");
		break;
	case TUE:
		printf("조깅을 하세요. \n");
		break;
	case WED:
		printf("조금 더 주무세요. \n");
		break;
	case THU:
		printf("볼링을 하세요. \n");
		break;
	case FRI:
		printf("조금 더 주무세요. \n");
		break;
	case SAT:
		printf("등산을 하세요. \n");
		break;
	case SUN:
		printf("원하는걸 하세요. \n");
		break;
	}
	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

typedef struct Dog // 선언 타입 1
{
	int data1;
	int data2;
} DOG;

typedef struct // 선언 타입2
{
	int data1;
	int data2;
} CAT;

void main()
{
	DOG d1; // typedef에 의한 선언
	struct Dog d2; // 이전 형식 (OK)

	CAT c1; // typedef에 의한 선언
	struct Cat c2; // 의전 형식 (ERROR)

	_getch();
}