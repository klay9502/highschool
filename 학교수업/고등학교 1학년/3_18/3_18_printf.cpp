//�ۼ���¥ : 2014.3.18
//�ۼ����� : printf ����
//�ۼ��� : ������

#include <stdio.h>
#include <Windows.h>
#include <time.h>

void main()
{
	printf("���ڿ� ���		:[%-20s]\n","��� ���ǻ�");
	printf("���ڿ� ���		:[%20s]\n","��� ���ǻ�");
	printf("���� ���		:[%10c]\n",'a');
	printf("���� ���		:[%-10c]\n",'a');
	printf("���� ������ ���	:[%-10d]\n",'a');
	printf("���� ����		:[%-10d]\n",1234);
	printf("������ ����		:[%10d]\n",1234);
	printf("0���� ���		:[%010d]\n",1234);
	printf("������ 0����		:[%010d]\n",-1234);
	printf("�ε��Ҽ��� ���		:[%8.2f]\n",123.4567);
	printf("�ε��Ҽ��� ���		:[%-8.2f]\n",123.4567);
	printf("�ε��Ҽ��� ���		:[%10.2f]\n",0.0012345);
	printf("�ε��Ҽ��� ���		:[%10.2e]\n",0.0012345);
	printf("�ε��Ҽ��� ���		:[%10.2g]\n",0.0012345);
	for(;;)	
	{
		system("color a6");
		Sleep(250);
		system("color b5");
		Sleep(250);
		system("color c4");
		Sleep(250);
		system("color d3");
		Sleep(250);
		system("color e2");
		Sleep(250);
		system("color f1");
		Sleep(250);
	}
}