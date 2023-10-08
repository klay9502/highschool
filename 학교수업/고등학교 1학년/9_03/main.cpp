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
		printf("���� �������� �Է��ϼ���! : �������� �ɼ�\n");
		printf("�ɼ� /r : ���� ���� �о����\n");
		printf("�ɼ� /w : ���� ���� �ۼ��ϱ�\n");

		return -1;
	}

	if (!strcmp(argv[1], "/r"))
		DoReadAction();
	else if (!strcmp(argv[1], "/w"))
		DoWriteAction();
	else
	{
		printf("�ɼ��� ��Ȯ���� �ʽ��ϴ�.\n");
		printf("�ٽ� Ȯ���� �ּ���.");

		return -1;
	}

	return 0;
}

int DoReadAction(void)
{
	FILE *fin;

	if ((fin = fopen("grade.txt", "rb")) == NULL)
	{
		printf("������ �� �� �����ϴ�.");
		
		return -1;
	}

	if (fread(Data, sizeof(Grade), 3, fin) != 3)
	{
		printf("������ �б⿡ ������ �߻��Ͽ����ϴ�.");
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
		printf("������ ������ �� �����ϴ�.");
		
		return -1;
	}

	InputUserData();

	if (fwrite(Data, sizeof(Grade), 3, fout) != 3)
	{
		printf("������ ���⿡ ������ �߻��Ͽ����ϴ�.");
		fclose(fout);

		return -1;
	}

	fclose(fout);

	return 0;
}

void InputUserData(void)
{
	int i;

	printf("�й�/�л��̸�/���� �� �Է��ϼ���.\n");

	for (i = 0; i < 3; i++)
	{
		printf("[�й�] : ");
		scanf("%d", &Data[i].Number);
		printf("[�̸�] : ");
		scanf("%s", Data[i].Name);
		printf("[����] : ");
		scanf("%d", &Data[i].Grade);
		printf("--------------------\n");
	}
}

void OutputUserData(void)
{
	int i;

	printf("�й�/�л��̸�/�����Դϴ�.\n");

	for (i = 0; i < 3; i++)
	{
		printf("[�й�] : %d\n", Data[i].Number);
		printf("[�̸�] : %s\n", Data[i].Name);
		printf("[����] : %d\n", Data[i].Grade);
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
		printf("[����]����.exe �˻�_�̸�\n");
		printf("�� : ����.exe ���濭\n");
		
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
			printf("[�й�] : %d\n", Data[i].Number);
			printf("[�̸�] : %s\n", Data[i].Name);
			printf("[����] : %d\n", Data[i].Grade);
			printf("--------------------\n");

			return 0;
		}
	}

	printf("[%s]��� �̸��� ������...�ٽý������ּ���.", name);

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
		printf("���� : ex11_7.exe ����_1 ����_2 ����_3\n");
		printf("�� ���α׷��� ����_1�� ����_2�� ���ļ� ����_3�� �����մϴ�.\n");

		return -1;
	}
	
	if ((fin1 = fopen(argv[1], "rt")) == NULL)
	{
		printf("�о���� ������ �����ϴ�.\n");

		return -1;
	}

	if ((fin2 = fopen(argv[2], "rt")) == NULL)
	{
		printf("�о���� ������ �����ϴ�.\n");

		return -1;
	}

	if ((fout = fopen(argv[3], "wt")) == NULL)
	{
		printf("����� ������ ������ �� �����ϴ�.\n");

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