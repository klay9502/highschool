//�ۼ���¥ : 2014.3.19
//�ۼ����� : ������� ����
//�ۼ��� : ������
/*
#include <stdio.h>

void main()
{
	printf("%5c \n",'*');
	printf("%4c%2c \n",'*','*');
	printf("%4c%2c \n",'*','*');
	printf("%2c%c%2c%2c%c \n",'*','*','*','*','*');
	printf("%c%3c%2c%3c \n",'*','*','*','*');
	printf("%2c%c%2c%c%c%c \n",'*','*','*','#','*','*');
	printf("%4c%2c%c \n",'*','*','#');
	printf("%4c%2c%2c \n",'*','*','#');
	printf("%5c%3c \n",'*','#');
}


#include <stdio.h>

void main()
{
	printf("%s\n","��");
}


#include <stdio.h>

void main()
{
	char a='A';
	char array[10]="BCDE";
	int b=5;
	float c=3.0;
	printf("(%c)\n",a);
	printf("(%s)\n",array);
	printf("(%d)\n",b);
	printf("(%.1f)\n",c);
}



#include <stdio.h>

void main()
{
	printf("���� 333�� 8������ 16������ ���\n8:%o, 16:%x\n",333,333);
}


#include <stdio.h>

void main()
{
	int Num=10;					//���� Num�� ���� �� �ʱ�ȭ
	short Age=0;				//���� Age�� ����
	char TotalRank=0;			//���� TotalRank�� ����

	printf("Number : %d\n",Num);
	printf("Age : %d\n",Age);
	printf("TotalRank : %d\n",TotalRank);
	printf("\n");
	Num=Num+1;					//���� Num�� ����
	Age=18;						//���� Age�� �ʱ�ȭ
	TotalRank='A';				//���� TotalRank�� �ʱ�ȭ
	printf("Number : %d\n",Num);
	printf("Age :%d\n",Age);
	printf("TotalRank : %c\n",TotalRank);
}


#include <stdio.h>

void main()
{
	printf("Visual.Net���� ���Ǵ� �ڷ����� ũ�⸦ �˾ƺ��ô�.\n");
	printf("������ �ڷ���		-short : %d\n",sizeof(short));
	printf("			-int : %d\n",sizeof(int));
	printf("			-unsigned int: %d\n",sizeof(unsigned int));
	printf("			-long : %d\n",sizeof(long));
	printf("�Ǽ��� �ڷ���		-float: %d\n",sizeof(float));
	printf("			-double : %d\n",sizeof(double));
	printf("������ �ڷ���		-char : %d\n",sizeof(char));
	printf("			-unsigned char : %d\n",sizeof(unsigned char));
}



#include <stdio.h>

void main()
{
	int a=5;
	int b=7;
	printf("%d �� %d �� ���� %d �Դϴ�.\n",a,b,a+b);
	printf("%d �� %d �� ���� %d �Դϴ�.\n",a,b,a*b);
}


#include <stdio.h>

void main()
{
	int X=10,Z=20;
	printf("�ﰢ�� ���� = %d\n����� ���� = %d\n",X*Z/2,X*Z);
}


#include <stdio.h>

void main()
{
	printf("���� �̸� �̴ϼ��� %c%c%c �Դϴ�. �� �̸��� ������ ������.\n",'K','J','M');
	printf("���� �����..���� 1�� ����..����\n");
}
*/

#include <stdio.h>

void main()
{
	int a=7,b=3;
	printf("%d�� %d�� ���� ���� %.2f �Դϴ�.\n",a,b,(float)a/b);
	printf("%d�� %d�� ���� ���� %.2f �Դϴ�.\n",b,a,(float)b/a);
}