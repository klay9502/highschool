#include <stdio.h>
#include <conio.h>

int main(void)
{
	int num, temp;
	int data[10];

	// �Է���Ʈ
	printf("������ �������� ����(�ִ� 10): ");
	scanf("%d", &num);

	while (1)
	{
		if (num > 10)
		{
			printf("�ִ��Ѱ�ġ�� �ʰ��Ͽ����ϴ�\n������ �������� ����(�ִ� 10): ");
			scanf("%d", &num);
		}
		else break;
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d��° �������Է�? ", i);
		scanf("%d", &data[i]);
	}

	printf("\n���� �� :\n");

	for (int i = 0; i < num; i++)
	{
		printf("%d ", data[i]);
	}
	
	// ��� ��Ʈ

	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 1; j < num; j++)
		{
			if (data[j - 1] > data[j])
			{
				temp = data[j - 1];
				data[j - 1] = data[j];
				data[j] = temp;
			}
		}
	}

	// ��� ��Ʈ
	printf("\n���� �� :\n");

	for (int i = 0; i < num; i++)
	{
		printf("%d ", data[i]);
	}

	_getch();
	return 0;
}