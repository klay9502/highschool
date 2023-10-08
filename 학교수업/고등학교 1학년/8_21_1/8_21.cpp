// 8_21.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

int main()
{
	char str[256] = "파일 출력 성공\n";
	FILE* fp;
	fp = fopen("test.txt", "rt+");

	while(1)
	{
		if (fgets(str, 256, fp) == NULL)
		{
			printf("파일을 끝까지 읽었습니다");
			break;
		}
		puts(str);
	}
	fclose(fp);

	_getch();
	return 0;
}