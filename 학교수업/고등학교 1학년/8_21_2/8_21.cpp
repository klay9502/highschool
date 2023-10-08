// 8_21.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	fprintf(fp, "┌───────────────┐\n");
	fprintf(fp, "│     성       적       표     │\n");
	fprintf(fp, "├───────────────┤\n");
	fprintf(fp, "│   번호 : %2d  이름 : %s   │\n", c.number, c.name);
	fprintf(fp, "├─────┬─────────┤\n");
	fprintf(fp, "│ 국어성적 │   %3d            │\n", c.score.kor);
	fprintf(fp, "├─────┼─────────┤\n");
	fprintf(fp, "│ 영어성적 │   %3d            │\n", c.score.eng);
	fprintf(fp, "├─────┼─────────┤\n");
	fprintf(fp, "│ 수학성적 │   %3d            │\n", c.score.mth);
	fprintf(fp, "└─────┴─────────┘\n");
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