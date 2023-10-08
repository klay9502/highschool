/*
#include <stdio.h>

int main(void)
{
	char buf[10];

	// ���� ����
	FILE *file = fopen("Test.txt","wt");
	fputs("1234abcd56789",file);
	fclose(file);

	// Random Access�� ���� �ٽ� ����
	file = fopen("Test.txt","rt");

	// ���� ��ġ ������ �ʱ⼳��
	fgets(buf,7,file);
	printf("%s \n",buf);

	// ****���� ��ġ ������ �̵�****
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

	printf("���� : ");
	scanf("%s", filename);

	fp = fopen(filename,"rb");
	
	if (fp == NULL)
	{
		printf("file open error!\n");
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	end = ftell(fp);
	printf("end�� ��ġ : %d\n", end);

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

	printf("���� : ");
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

	printf("[ó��]\n");

	fseek(fp, 0, SEEK_END);
	end = ftell(fp);

	for (int i = 1; i <= end; i++)
	{
		fseek(fp, -i, SEEK_END);
		ch = fgetc(fp);
		printf("%c", ch);
	}

	printf("\n[������]\n");
}
*/

#include <stdio.h>
#include <conio.h>
#define NUMBER 100

typedef struct
{
	char name[100];		// �̸�
	double height;		// ����
	double weight;		// ü��
}pdata;

void sort(pdata data[], int n);		// �迭 data�� ó�� n�� ��Ҹ� ������ ������������ sort

int main(void)
{
	int human = 0;		// �ö���
	double hsum = 0.0;	// ������ �հ�
	double wsum = 0.0;	// ü���� �հ�
	pdata data[NUMBER];	// ���ε�����
	
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