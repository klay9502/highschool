/*
#include <stdio.h>
#include <conio.h>

int main(int argc,  char *argv[])
{
	int i = 0;
	printf("���޵� ���ڿ��� �� : %d\n", argc);

	for (i = 0; i < argc; i++)
		printf("%d��° ���ڿ� : %s \n", i + 1, argv[i]);

	return 0;

}
*/

/*
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fin, *fout;

	if (argc < 3)
	{
		printf("���� �������� �Է��ϼ���! : �������� ����_ ���Ϻ���_����");
		return -1;
	}

	if ((fin = fopen(argv[1], "r")) == NULL)
	{
		printf("���� ������ �� �� �����ϴ�.");
		return -1;
	}

	if ((fout = fopen(argv[2], "w")) == NULL)
	{
		printf("���� ������ �� �� �����ϴ�.");
		return -1;
	}

	while (!feof(fin))
		fputc((char)toupper(fgetc(fin)), fout);

	fclose(fin);
	fclose(fout);
	
	return 0;
}
*/

/*
#include <stdio.h>
#include <conio.h>
#define ARY_SIZE 10

int main(void)
{
	int i;
	FILE *fp;
	double a[ARY_SIZE] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0};

	if ((fp = fopen("ARRAY.txt", "wb")) == NULL) // ����
		printf("\a������ �� �� �����ϴ�.\n");

	fwrite(a, sizeof(double), ARY_SIZE, fp); // a�� ����
	fclose(fp); // �ݱ�

	for (i = 0; i < ARY_SIZE; i++)
		a[i] = 0.0;
	for (i = 0; i < ARY_SIZE; i++)
		printf("a[%d] = %f\n", i, a[i]);
	printf("\n\n\n");

	if ((fp = fopen("ARRAY.txt", "rb")) == NULL) // ����
		printf("\a������ �� �� �����ϴ�.\n");

	fread(a, sizeof(double), ARY_SIZE, fp); // a�� �о���δ�.
	
	for (i = 0; i < ARY_SIZE; i++)
		printf("a[%d] = %f\n", i, a[i]);
	fclose(fp); // �ݱ�

	return 0;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void main()
{
	char buf[512];
	FILE *fp;

	if((fp = fopen("test2.txt", "rb")) == NULL)
	{
		printf("test2.txt can't open\n");
		exit(-1);
	}

	fread (buf, 6, 4, fp);
	fwrite(buf, 4, 3, stdout);
	fclose(fp);
	_getch();
}
*/