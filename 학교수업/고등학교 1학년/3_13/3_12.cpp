/*�ۼ��� : C ���α׷��� �������� �̷���� ������?
�ۼ��� : 3.12
�ۼ��� : ������
*/

#include <stdio.h>	//��ó����
#define MAX 10

int Add(int,int);	//�Լ��� ������Ÿ��
void main()
{
	int num1,num2;	//������ ����
	int ret;
	num1=10;	//������ �ʱ�ȭ
	num2=20;

	printf("�������� C ���α׷��Դϴ�.\n");
	printf("num1�� num2�� ������ ����� �˾ƺ��ô�.\n");	//���� �����ڸ� �̿��� ������ ����
	ret=num1+num2;
	printf("������ ��� ��� : %d\n",ret);
	ret=Add(num1,num2);	// �Լ� Add()�� ȣ��
	printf("�Լ� ��� ���: %d\n",ret);
}

int Add(int a,int b)
{
	int ret;	//�Լ� Add()�� ��ü
	ret=a+b;
	return(ret);
}