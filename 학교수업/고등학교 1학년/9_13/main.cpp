/*
#include <stdio.h>
#include <conio.h>
#define NUMBER 4

typedef struct
{
	char Name[100];		// 이름
	int Kor;			// 국어점수
	int Math;			// 수학점수
	int Eng;			// 영어점수
	int Total;			// 합계
	double Avg;			// 평균
}pData;

int main(void)
{
	pData data[NUMBER];	// 개인 데이터

	FILE *file_in = fopen("student.txt", "r");

	FILE *file_out = fopen("output.txt", "w");

	if (file_in == NULL || file_out == NULL) {
		printf("실패! \n");
		_getch();
		return 1;
	}

	fprintf(file_out, "No. Name Kor Mat Eng Tot. Avg.\n");

	for (int i = 0; i < NUMBER; i++)
	{
		// =========입력구문=========

		fscanf(file_in, "%s %d %d %d", data[i].Name, &data[i].Kor, &data[i].Math, &data[i].Eng);
		data[i].Total = data[i].Kor + data[i].Math + data[i].Eng;
		data[i].Avg = data[i].Total / 3.0f;

		// =========출력구문=========

		fprintf(file_out, "%d %5s %3d %3d %3d %4d %5.1lf\n", i + 1, data[i].Name, data[i].Kor, data[i].Math, data[i].Eng, data[i].Total, data[i].Avg);
	}

	printf("성공!");

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
		printf("실패! \n");
		_getch();
		return 1;
	}

	printf("ASCII 테이블을 작성합니다.\n");

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

	printf("출력할 파일이름을 입력하세요. ");
	scanf("%s", filename);

	file = fopen( filename, "rb");

	if (file == NULL)
	{
		printf("file open error!\n");
		return -1;
	}

	printf("***%s파일 출력 결과***\n", filename);

	while (!feof(file))
	{
		ch = fgetc(file);

		if (isupper(ch))
			c_big++;
		if (islower(ch))
			c_small++;
		count++;
	}

	printf("대문자 : %d\n", c_big);
	printf("소문자 : %d\n", c_small);
	printf("전체문자 : %d\n", count);

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
		printf("실패! \n");
		_getch();
		return 1;
	}

	printf("검색 번호 입력(1~19) : ");
	scanf("%d", &number);

	if (number > 0 && number <= 19)
	{
		for (int i = 0; i < 19; i++)
		{
			fscanf(file, "%d %s", &data.Code, data.Word);

			if (data.Code == number)
			{
				printf("\n\n\t검색하신 단어는 [%s]입니다.\n", data.Word);
				break;
			}
		}
	}
	else
		printf("\n\n\t검색 번호는 존재하지 않습니다.\n");

	_getch();
	fclose(file);
	return 0;
}