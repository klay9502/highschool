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
	scanf("%d",&num);

	str=(int *)malloc(sizeof(int)*num);
	printf("실제 수를 입력하세요\n");
	while(i<num)
	{
		scanf("%d",&str[i]);
		i++;
	}
	for(i = 0; i<num; i++)
	{
		sum+=str[i];
	}
	printf("sum = %d\n",sum);

	free(str);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

struct perInfo {
	char addr[30];
	char tel[20];
};

struct person {
	char name[20];
	char pID[20];
	struct perInfo *inf;
};

int main()
{
	struct perInfo info = {"Korean Seoul", "333-4444"};
	struct person man = {"Mr.Lee", "820204-xxxx512"};

	man.inf = &info;

	printf("name : %s\n", man.name);
	printf("pID : %s\n", man.pID);
	printf("addr : %s\n", man.inf->addr);
	printf("tel : %s\n", man.inf->tel);

	_getch();
}
*/

#include <stdio.h>
#include <conio.h>

typedef struct _Grade {
	char Name[20];
	int Number;
	int Korean;
} Grade;

int ShowTable(Grade *);

void main()
{
	Grade student[3];

	printf("1학년의 성적 관리 프로그램입니다.\n");

	for (int i = 0; i < 3; i++)
	{
		printf("%d번째 학생의 이름을 입력하세요. : ", i + 1); scanf("%s", student[i].Name);
		printf("학번을 입력하세요. : "); scanf("%d", student[i].Number);
		printf("국어 성적을 입력하세요. : "); scanf("%d", student[i].Korean);
	}

	printf("============================================================================");

	ShowTable(student);
	_getch();
}

int ShowTable(Grade *str)
{
	printf("학번\t\t\t\t이름\t\t\t\t국어 성적\n");
	
	for (int i = 0; i < 3; i++)
	{
		printf("[%d]번\t\t\t\t[%s]\t\t\t\t%d\n", );
}