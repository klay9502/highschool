// p100 예제17

/*
// strcpy 함수 사용 예
#include <stdio.h>
#include <string.h>
#include <conio.h>

void main()
{
	char a[20];
	char b[20];

	strcpy(a, "my name is YH");
	strcpy(b, a);

	printf("%s\n", b);

	_getch();
}
*/

/*
// 직접구현
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>

char str_cpy(char *user, char *name);

void main()
{
	char *a;
	char *b;

	a = (char*)calloc(sizeof(char) * 10, 0);
	b = (char*)calloc(sizeof(char) * 10, 0);

	str_cpy(a, "My name is KJM");
	str_cpy(b, a);
	
	printf("%s\n", b);
	_getch();
}

char str_cpy(char *user, char *name)
{
	int i;

	for (i = 0; name[i] != NULL; i++)
		user[i] = name[i];
	return *user;
}
*/

// p100 예제18

/*
#include <stdio.h>
#include <string.h>
#include <conio.h>

void BoxMessage(char *str);

void main()
{
	BoxMessage("문자의 길이에 맞도록 - 를 감싸서 출력하기");
	_getch();
}

void BoxMessage(char *str)
{
	int i, len;
	
	len = strlen(str);
	puts("");
	for (i = 0; i < len + 4; i++)
		putch('-');
	puts("");
	printf("%s\n",str);
	for (i = 0; i < len + 4; i++)
		putch('-');
	puts("");
}
*/

// p100 예제19

/*
#include <stdio.h>
#include <string.h>
#include <conio.h>

void main()
{
	char first_name[10] = "김";
	char last_name[10] = "영하";

	printf("%s%s\n", first_name, last_name);
	strcpy(first_name, "이");
	printf("%s%s\n", first_name, last_name);
	strcat(last_name, " 선생님");
	printf("%s%s\n", first_name, last_name);
	_getch();
}
*/

// p101 예제20

/*
#include <stdio.h>
#include <string.h>
#include <conio.h>

void main()
{
	char name1[30] = "김영하";
	char name2[30];
	int i;

	scanf("%s", name2);
	i = strcmp(name1, name2);

	if (i == 0)
		puts("두 문자열이 같습니다.");
	else
		puts("두 문자열이 다릅니다.");
	_getch();
}
*/

// 로그인 프로그램

/*
#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
	char id[30] = "anione";
	char password[30] = "game_anione";
	char c_id[30];
	char c_password[30];

	printf("ID : ");
	scanf("%s", c_id);
	printf("Password : ");
	scanf("%s", c_password);

	if (strcmp(id, c_id) == 0 && strcmp(password, c_password) == 0)
		puts("로그인 성공...\n환영합니다\n");
	else
		puts("로그인 실패...\n아이디 또는 비밀번호가 틀렸습니다.\n");
	_getch();
}
*/

// p101 예제21

/*
//atoi 함수 사용 예
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	int k;
	int x= 1234;
	char str[30];

	itoa(x, str, 10);
	printf("%s\n", str);

	k = atoi(str);
	printf("%d\n", k);

	_getch();
}
*/