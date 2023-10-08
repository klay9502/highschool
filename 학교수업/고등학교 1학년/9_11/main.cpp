/*
#include <stdio.h>

int main(void)
{
	char buf[10];

	// 파일 생성
	FILE *file = fopen("Test.txt","wt");
	fputs("1234abcd56789",file);
	fclose(file);

	// Random Access를 위해 다시 개방
	file = fopen("Test.txt","rt");

	// 파일 위치 지시자 초기설정
	fgets(buf,7,file);
	printf("%s \n",buf);

	// ****파일 위치 지시자 이동****
	//fseek(file,2,SEEK_CUR);
	//fseek(file,-2,SEEK_CUR);
	fseek(file,2,SEEK_SET);
	//fseek(file,-2,SEEK_END);
	// ***********************

	printf("%c\n",fgetc(file));
	fclose(file);

	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>

int main()
{
	int end;
	FILE *fp = NULL;
	char filename[128];

	printf("파일 : ");
	scanf("%s", filename);

	fp = fopen(filename,"rb");
	
	if (fp == NULL)
	{
		printf("file open error!\n");
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	end = ftell(fp);
	printf("end의 위치 : %d\n", end);

	fclose(fp);
	_getch();
	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void PrintReverse(FILE *fp);

int main(void)
{
	FILE *fp = NULL;
	char filename[128];

	printf("파일 : ");
	scanf("%s", filename);

	fp = fopen( filename, "rb");

	if (fp == NULL)
	{
		printf("file open error!\n");
		return -1;
	}
	PrintReverse(fp);
	fclose(fp);

	_getch();

	return 0;
}

void PrintReverse(FILE *fp)
{
	int end, ch;

	printf("[처음]\n");

	fseek(fp, 0, SEEK_END);
	end = ftell(fp);

	for (int i = 1; i <= end; i++)
	{
		fseek(fp, -i, SEEK_END);
		ch = fgetc(fp);
		printf("%c", ch);
	}

	printf("\n[마지막]\n");
}
*/

#include <stdio.h>
#include <conio.h>
#define NUMBER 100

typedef struct
{
	char name[100];		// 이름
	double height;		// 신장
	double weight;		// 체중
}pdata;

void sort(pdata data[], int n);		// 배열 data의 처음 n개 요소를 신장의 오름차순으로 sort

int main(void)
{
	int human = 0;		// 시람수
	double hsum = 0.0;	// 신장의 합계
	double wsum = 0.0;	// 체중의 합계
	pdata data[NUMBER];	// 개인데이터
	
	FILE *file = fopen("hw.txt", "rt");

	if (file == NULL) {
		printf("file open error! \n");
		return 1;
	}

	while(!feof(file))
	{
		fscanf(file, "%s %lf %lf", data[human].name, &data[human].height, &data[human].weight);
		human++;
	}

	for (int i = 0; i < human; i++)
		printf("%s		%lf	%lf\n", data[i].name, data[i].height, data[i].weight);

	_getch();
	return 0;
}

void sort(pdata data[], int n)
{
	int k = n - 1;
	pdata temp;
	
	while (k >= 0)
	{
		int i;
		
		for (i = 0; i <= k; i++)
			if (data[i - 1].height > data[i].height)
			{
				temp = data[i - 1];
				data[i - 1] = data[i];
				data[i] = temp;
			}
			k--;
	}
}