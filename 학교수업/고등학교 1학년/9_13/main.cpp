/*
#include <stdio.h>
#include <conio.h>
#define NUMBER 4

typedef struct
{
	char Name[100];		// �̸�
	int Kor;			// ��������
	int Math;			// ��������
	int Eng;			// ��������
	int Total;			// �հ�
	double Avg;			// ���
}pData;

int main(void)
{
	pData data[NUMBER];	// ���� ������

	FILE *file_in = fopen("student.txt", "r");

	FILE *file_out = fopen("output.txt", "w");

	if (file_in == NULL || file_out == NULL) {
		printf("����! \n");
		_getch();
		return 1;
	}

	fprintf(file_out, "No. Name Kor Mat Eng Tot. Avg.\n");

	for (int i = 0; i < NUMBER; i++)
	{
		// =========�Է±���=========

		fscanf(file_in, "%s %d %d %d", data[i].Name, &data[i].Kor, &data[i].Math, &data[i].Eng);
		data[i].Total = data[i].Kor + data[i].Math + data[i].Eng;
		data[i].Avg = data[i].Total / 3.0f;

		// =========��±���=========

		fprintf(file_out, "%d %5s %3d %3d %3d %4d %5.1lf\n", i + 1, data[i].Name, data[i].Kor, data[i].Math, data[i].Eng, data[i].Total, data[i].Avg);
	}

	printf("����!");

	fclose(file_in);
	fclose(file_out);

	_getch();
	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>

int main(void)
{
	char ascii;
	int cheak = 0;
	FILE *file = fopen("ascii.txt", "w");

	if (file == NULL) {
		printf("����! \n");
		_getch();
		return 1;
	}

	printf("ASCII ���̺��� �ۼ��մϴ�.\n");

	for (int i = 0; i < 128; i++)
	{
		ascii = i;
		if (i >= 33 && i <= 125)
		{
			fputc('\t', file);
			fputc(ascii, file);
		}
		else
			fputc('\t', file);

		if (cheak > 8)
		{
			fputc('\n', file);
			cheak = 0;
		}

		cheak++;
	}

	_getch();
	fclose(file);
	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main(void)
{
	int c_big = 0;
	int c_small = 0;
	int count = 0;
	char ch;

	FILE *file = NULL;
	char filename[128];

	printf("����� �����̸��� �Է��ϼ���. ");
	scanf("%s", filename);

	file = fopen( filename, "rb");

	if (file == NULL)
	{
		printf("file open error!\n");
		return -1;
	}

	printf("***%s���� ��� ���***\n", filename);

	while (!feof(file))
	{
		ch = fgetc(file);

		if (isupper(ch))
			c_big++;
		if (islower(ch))
			c_small++;
		count++;
	}

	printf("�빮�� : %d\n", c_big);
	printf("�ҹ��� : %d\n", c_small);
	printf("��ü���� : %d\n", count);

	_getch();
	fclose(file);
	return 0;
}
*/

#include <stdio.h>
#include <conio.h>

typedef struct
{
	int Code;
	char Word[100];
}pdata;

int main(void)
{
	int number;
	pdata data;
	FILE *file = fopen("100.txt", "r");

	if (file == NULL) {
		printf("����! \n");
		_getch();
		return 1;
	}

	printf("�˻� ��ȣ �Է�(1~19) : ");
	scanf("%d", &number);

	if (number > 0 && number <= 19)
	{
		for (int i = 0; i < 19; i++)
		{
			fscanf(file, "%d %s", &data.Code, data.Word);

			if (data.Code == number)
			{
				printf("\n\n\t�˻��Ͻ� �ܾ�� [%s]�Դϴ�.\n", data.Word);
				break;
			}
		}
	}
	else
		printf("\n\n\t�˻� ��ȣ�� �������� �ʽ��ϴ�.\n");

	_getch();
	fclose(file);
	return 0;
}