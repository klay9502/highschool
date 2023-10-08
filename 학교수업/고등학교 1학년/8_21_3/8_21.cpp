// 8_21.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	BYTE* data;
	int filesize;

	FILE* fp;
	fp = fopen("filename.bmp", "rb");

	fread(&bfh, sizeof(BITMAPFILEHEADER), 1, fp);
	fread(&bih, sizeof(BITMAPINFOHEADER), 1, fp);
	
	filesize = bih.biWidth * bih.biHeight * bih.biBitCount / 8;
	data = (BYTE*)malloc(filesize);
	fread(data, filesize, 1, fp);

	fclose(fp);

	printf("%s File Size = %dByte\n", "filename.bmp", bfh.bfSize);
	printf("%s Image ũ�� = %d x %d\n", "filename.bmp", bih.biWidth, bih.biHeight);
	printf("%s Image�� Pixel�� Bit �� = %dBit\n", "filename.bmp", bih.biBitCount);
	printf("%s Image�� Pixel�� Byte �� = %dByte\n", "filename.bmp", bih.biBitCount / 8);
	printf("%s Image�� BMPFILEHEADERũ�� = %d\n", "filename.bmp", sizeof(bfh));
	printf("%s Image�� BMPINFOHEADERũ�� = %d\n", "filename.bmp", sizeof(bih));
	printf("%s Image�� IMAGE Dataũ�� = %d\n", "filename.bmp", filesize);

	int linesize = bih.biWidth * 3;

	for (int y = bih.biHeight; y > 0; y--)
	{
		for (int x = 0; x < bih.biWidth; x++)
		{
			int offset = y * linesize + x * 3;

			if( data[offset + 0] == 255 && data[offset + 1] == 255 && data[offset + 2] == 255)
			{
				printf(" *"); // ����̸� * ���
			}
			else
			{
				printf("  "); // ����� �ƴϸ� ���� ���
			}
		}
		printf("\n");
	}
	
	puts("Press A Key!!!");
	getch();
	return 0;
}
