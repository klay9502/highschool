// p67 8-2

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int i;
//	int num;
//	int three = 0,seven = 0;
//	int t_result = 0,s_result = 0;
//
//	puts("3�� ���, 7�� ����� ����. 1���� ������ �� �߿�?");
//
//	scanf("%d", &num);
//
//	for (i = 1; i <= num; i++)
//	{
//		three++;
//		seven++;
//		if (i % 3 == 0)
//			t_result += three;
//		if (i % 7 == 0)
//			s_result += seven;
//	}
//	printf("1���� %d���� 3�� ����� ���� %d, 7�� ��� ���� %d �Դϴ�.\n",num,t_result,s_result);
//	_getch();
//}

// p67 8-3

//#include <stdio.h>		// made by ����
//#include <conio.h>
//
//int main(void)
//{
//	int num,num2; //�Է¹��� num��  num2�� ������ ����
//	int i;//for������ ���� i�� ����
//
//	printf("1���� 100������ �� �߿��� ����� ���ϱ�\n");
//	printf("���1:");
//	scanf("%d", &num);
//	printf("���2:");
//	scanf("%d", &num2);//�Է¹ޱ�
//
//	for(i=1; i<=100; i++)//1���� 100�����̹Ƿ� i�� 1�� �ʱ�ȭ�ϰ� 100���� +1���ؼ� ������
//	{
//		if(i%num==0 && i%num2==0)//���࿡ i�� num�� num2�� �������� �������� ���̹Ƿ�
//		{
//			printf("%d�� %d�� ����� : %d\n",num,num2,i);//����ڷ� ����ϱ�
//		}
//	}
//	_getch();
//}

// p67 8-4

//#include <stdio.h>		// made by ����
//#include <conio.h>
//
//int main(void)
//{
//	int num,num2; //�Է¹��� num,num2�� ������ �ΰ�
//	int i,inum; //for������ ���� i�� num,num2�� ���ؼ� ���� ���� ���� inum(for������ �������� �Ѱ�)
//
//	printf("����� ���� �� ������ �Է��ϼ���\n");
//	printf("�Է�1:");
//	scanf("%d",&num);
//	printf("�Է�2:");
//	scanf("%d", &num2);//�Է¹ޱ�
//
//	printf("�����:");//�̸� ����ϱ�
//
//	if(num<num2)
//	{
//		inum=num;
//	}
//	else;
//	{
//		inum=num2;
//	}
//	//�������� ���� �ᱹ �����̾�ߵǹǷ� for���� ���� Ƚ���� �ִ��� ���̱� ����
//	//num�� num2�� ���ؼ� ���� ���� �������� �ΰ� ������ ���� ���ϰ� ���� ���� inum�� ����
//
//	for(i=1; i<=inum; i++)//i�� 1�� �ΰ� ����num(inum)���� ������
//	{
//		if(num%i==0 && num2%i==0)//���� i�� num�� num2�� �� �������ٸ�
//		{
//			printf("%4d", i);//i�� �������� ���̹Ƿ� i���
//		}
//	}
//	printf("\n");
//}

// ppt ����

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int TotalNumber, InputNumber;
//	int i,j;
//
//	printf("1���� �����ϴ� ���α׷��Դϴ�.\n");
//	printf("������ ���� �Է��ϼ���. \n");
//	printf("1 ���� -> ");
//	scanf("%d",&InputNumber);
//
//	printf("1���� %d���� �����մϴ�.\n", InputNumber);
//
//	TotalNumber = 0;
//	i = 1;
//	for (; i <= InputNumber; i++)
//	{
//		TotalNumber += i;
//		printf("TotalNumber�� �� : %d\n",TotalNumber);
//	}
//	printf("\n1���� %d������ ������ %d�Դϴ�.\n", InputNumber,TotalNumber);
//	_getch();
//}

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int TotalNumber, InputNumber;
//	int i,j;
//
//	printf("1���� �����ϴ� ���α׷��Դϴ�.\n");
//	printf("������ ���� �Է��ϼ���. \n");
//	printf("1 ���� -> ");
//	scanf("%d",&InputNumber);
//
//	printf("1���� %d���� �����մϴ�.\n", InputNumber);
//
//	TotalNumber = 0;
//	for (i = 1; i <= InputNumber ; TotalNumber += i++);	// �������� �����ݷ� ����
//
//	printf("\n1���� %d������ ������ %d�Դϴ�.\n", InputNumber,TotalNumber);
//	_getch();
//}

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int a = 1;
//
//	for (; a <= 2; a++)
//		printf("%2d",a);
//
//	puts("\n��ȣ!");
//
//	for (; a >= 1; a--)
//		printf("%2d",a);
//
//	putchar('\n');
//	_getch();
//}

// p67 8-5

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int num1,num2;;
//	int GCM, LCM;	// �ִ����� �� �ּ� �����
//
//	printf("�� ������ �Է��ϼ���.##\n");
//	printf("�Է�1 :"); scanf("%d",&num1);
//	printf("�Է�2 :"); scanf("%d",&num2);
//
//	for (int i = 1;; i++)			// �ּҰ���� ���ϱ�
//	{
//		if (i % num1 == 0 && i % num2 == 0)
//		{
//			GCM = i;
//			break;
//		}
//	}
//
//	for (int i = num1;; i--)			// �ִ����� ���ϱ�
//	{
//		if (num1 % i == 0 && num2 % i == 0)
//		{
//			LCM = i;
//			break;
//		}
//	}
//
//	printf("%d��(��) %d�� �ִ����� : %d, �ּҰ���� : %d�Դϴ�.",num1,num2,LCM,GCM);
//	_getch();
//}

// p68 8-6

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int result = 0;
//	bool code = 0;
//
//	for (int i = 0; i < 100; i++)
//	{
//		if (code == 0)
//		{
//			result += i;
//			code = 1;
//			continue;
//		}
//		else	// 'code'�� '1'�϶�
//		{
//			result -= i;
//			code = 0;
//			continue;
//		}
//	}
//	printf("1-2+3-4+...+99-100 �հ�� %d�Դϴ�.",result);
//	_getch();
//}

// p68 8-7

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int result = 1;
//	bool code = 0;
//
//	for (int i = 1; i <= 10; i++)
//	{
//		if (code == 0)
//		{
//			printf("%d *",-i);
//			result *= -i;
//			code = 1;
//			continue;
//		}
//		if (code == 1)
//		{
//			printf(" %d ",i);
//			result *= i;
//			code = 0;
//			continue;
//		}
//	}
//	printf("����� : %d",result);
//	_getch();
//}

// p68 8-8

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	float result = 0;
//
//	for (float i = 1; i <= 100; i++)
//		result += (i / (i + 1));
//	printf("1/2+2/3+3/4+...99/100 �հ�� %.1f�Դϴ�.\n",result);
//	_getch();
//}

// p68 8-9

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int result = 0;
//
//	for (int i = 1; ; i++)
//	{
//		result += i;
//		if (result >= 5000)
//		{
//			printf("5000�� �Ѵ� ������ N�� => %d\n",i);
//			printf("�׶��� �� => %d",result);
//			break;
//		}
//	}
//	_getch();
//}

// p68 8-10

//#include <stdio.h>
//#include <conio.h>
//
//void main()
//{
//	int num;
//	int result = 1;
//
//	printf("���丮�� ��� ���α׷�(n!)\n");
//	printf("n �� �Է�: "); scanf("%d",&num);
//
//	for (int i = 1; i <= num; i++)
//	{
//		if (i < num)
//		{
//			printf("%d * ",i);
//			result *= i;
//		}
//		else
//		{
//			result *= i;
//			printf("%d = %d",i,result);
//		}
//	}
//	_getch();
//}

// p68 8-11

#include <stdio.h>
#include <conio.h>

void main()
{
	int num;
	int a = 0, b = 1;
	bool count = 0;

	printf("�Ǻ���ġ���� ���ϴ� ���α׷�\n");
	printf("�Ǻ���ġ���� ���� �Է�: "); scanf("%d",&num);

	for (int i = 1; i <= num; i++)
	{
		if (count == 0)
		{
			a += b;
			printf("%d\t",a);
			count = 1;
		}
		else	// 'count == 1'
		{
			b += a;
			printf("%d\t",b);
			count = 0;
		}
	}
	_getch();
}