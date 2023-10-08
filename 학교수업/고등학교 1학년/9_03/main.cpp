/*
#include <stdio.h>
#include <string.h>

typedef struct _Grade
{
	char Name[10];
	int Number;
	int Grade;
} Grade;

Grade Data[3];

int DoReadAction(void);
int DoWriteAction(void);
void InputUserData(void);
void OutputUserData(void);

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("다음 형식으로 입력하세요! : 실행파일 옵션\n");
		printf("옵션 /r : 점수 파일 읽어오기\n");
		printf("옵션 /w : 점수 파일 작성하기\n");

		return -1;
	}

	if (!strcmp(argv[1], "/r"))
		DoReadAction();
	else if (!strcmp(argv[1], "/w"))
		DoWriteAction();
	else
	{
		printf("옵션이 정확하지 않습니다.\n");
		printf("다시 확인해 주세요.");

		return -1;
	}

	return 0;
}

int DoReadAction(void)
{
	FILE *fin;

	if ((fin = fopen("grade.txt", "rb")) == NULL)
	{
		printf("파일을 열 수 없습니다.");
		
		return -1;
	}

	if (fread(Data, sizeof(Grade), 3, fin) != 3)
	{
		printf("데이터 읽기에 오류가 발생하였습니다.");
		fclose(fin);
		
		return -1;
	}

	fclose(fin);

	OutputUserData();
	
	return 0;
}

int DoWriteAction(void)
{
	FILE *fout;

	if ((fout = fopen("grade.txt", "wb")) == NULL)
	{
		printf("파일을 생성할 수 없습니다.");
		
		return -1;
	}

	InputUserData();

	if (fwrite(Data, sizeof(Grade), 3, fout) != 3)
	{
		printf("데이터 쓰기에 오류가 발생하였습니다.");
		fclose(fout);

		return -1;
	}

	fclose(fout);

	return 0;
}

void InputUserData(void)
{
	int i;

	printf("학번/학생이름/점수 를 입력하세요.\n");

	for (i = 0; i < 3; i++)
	{
		printf("[학번] : ");
		scanf("%d", &Data[i].Number);
		printf("[이름] : ");
		scanf("%s", Data[i].Name);
		printf("[점수] : ");
		scanf("%d", &Data[i].Grade);
		printf("--------------------\n");
	}
}

void OutputUserData(void)
{
	int i;

	printf("학번/학생이름/점수입니다.\n");

	for (i = 0; i < 3; i++)
	{
		printf("[학번] : %d\n", Data[i].Number);
		printf("[이름] : %s\n", Data[i].Name);
		printf("[점수] : %d\n", Data[i].Grade);
		printf("--------------------\n");
	}
}
*/

/*
#include <stdio.h>
#include <string.h>

typedef struct _Grade
{
	char Name[10];
	int Number;
	int Grade;
} Grade;

Grade Data[3];

int DoReadAction(char *name);
int OutputUserData(char* name);

int main(int argc, char *argv[])
{
	char name[10];

	if (argc < 2)
	{
		printf("[사용법]파일.exe 검색_이름\n");
		printf("예 : 파일.exe 이충열\n");
		
		return -1;
	}

	strcpy(name, argv[1]);
	DoReadAction(name);

	return 0;
}

int DoReadAction(char* name)
{
	FILE *fin;

	OutputUserData(name);

	return 0;
}

int OutputUserData(char* name)
{
	FILE *fout;

	for (int i = 0; i < 3; i++)
	{
		if (!strcmp(Data[i].Name, name))
		{
			printf("[학번] : %d\n", Data[i].Number);
			printf("[이름] : %s\n", Data[i].Name);
			printf("[점수] : %d\n", Data[i].Grade);
			printf("--------------------\n");

			return 0;
		}
	}

	printf("[%s]라는 이름이 없군요...다시실행해주세요.", name);

	return -1;
}
*/

/*
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	FILE *fin1, *fin2, *fout;
	char src1[80], src2[80];

	if (argc < 4)
	{
		printf("사용법 : ex11_7.exe 파일_1 파일_2 파일_3\n");
		printf("이 프로그램은 파일_1과 파일_2를 합쳐서 파일_3에 저장합니다.\n");

		return -1;
	}
	
	if ((fin1 = fopen(argv[1], "rt")) == NULL)
	{
		printf("읽어들일 파일이 없습니다.\n");

		return -1;
	}

	if ((fin2 = fopen(argv[2], "rt")) == NULL)
	{
		printf("읽어들일 파일이 없습니다.\n");

		return -1;
	}

	if ((fout = fopen(argv[3], "wt")) == NULL)
	{
		printf("출력할 파일을 생성할 수 없습니다.\n");

		return -1;
	}

	while (!feof(fin1) || !feof(fin2))
	{
		if (!feof(fin1))
		{
			fgets(src1, 80, fin1);
			fputs(src1, fout);
		}
		if (!feof(fin2))
		{
			fgets(src2, 80, fin2);
			fputs(src2, fout);
		}
	}
	
	fclose(fin1);
	fclose(fin2);
	fclose(fout);

	return 0;
}
*/