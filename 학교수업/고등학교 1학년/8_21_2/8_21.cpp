// 8_21.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

/*
#include "stdafx.h"

typedef struct tagScroe {
	int kor;
	int eng;
	int mth;
} SCORE;

typedef struct tagStudent {
	int number;
	char name[10];
	SCORE score;
} STUDENT;

void Output(FILE* fp, STUDENT c)
{
	fprintf(fp, "����������������������������������\n");
	fprintf(fp, "��     ��       ��       ǥ     ��\n");
	fprintf(fp, "����������������������������������\n");
	fprintf(fp, "��   ��ȣ : %2d  �̸� : %s   ��\n", c.number, c.name);
	fprintf(fp, "����������������������������������\n");
	fprintf(fp, "�� ����� ��   %3d            ��\n", c.score.kor);
	fprintf(fp, "����������������������������������\n");
	fprintf(fp, "�� ����� ��   %3d            ��\n", c.score.eng);
	fprintf(fp, "����������������������������������\n");
	fprintf(fp, "�� ���м��� ��   %3d            ��\n", c.score.mth);
	fprintf(fp, "����������������������������������\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	STUDENT c;
	FILE* fpSrc;
	FILE* fpDst;
	fpSrc = fopen("./input.txt", "rt");
	fpDst = fopen("./output.txt", "wt+");
	
	while (!feof(fpSrc))
	{
		fscanf(fpSrc, "%d %s %d %d %d", &c.number, c.name, &c.score.kor, &c.score.eng, &c.score.mth);
		Output(fpDst, c);
	}
	
	fclose(fpDst);
	fclose(fpSrc);

	return 0;
}
*/

#include "stdafx.h"

int main()
{
	unsigned char data[256];
	int ndatasize;
	FILE* fsrc, *fdest;
	fsrc = fopen("input.bmp", "rb+");
	fdest = fopen("output.bmp", "ab+");
	while(!feof(fsrc))
	{
		ndatasize = fread(data, 1, 256, fsrc);
		fwrite(data,1,ndatasize, fdest);
	}

	fclose(fsrc);

	return 0;
}