// 8_21.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int main()
{
	char str[256] = "���� ��� ����\n";
	FILE* fp;
	fp = fopen("test.txt", "rt+");

	while(1)
	{
		if (fgets(str, 256, fp) == NULL)
		{
			printf("������ ������ �о����ϴ�");
			break;
		}
		puts(str);
	}
	fclose(fp);

	_getch();
	return 0;
}