#include <stdio.h>
#include <conio.h>

int main(void)
{
	int num, temp;
	int data[10];

	// 입력파트
	printf("정렬할 데이터의 개수(최대 10): ");
	scanf("%d", &num);

	while (1)
	{
		if (num > 10)
		{
			printf("최대한계치를 초과하였습니다\n정렬할 데이터의 개수(최대 10): ");
			scanf("%d", &num);
		}
		else break;
	}

	for (int i = 0; i < num; i++)
	{
		printf("%d번째 데이터입력? ", i);
		scanf("%d", &data[i]);
	}

	printf("\n정렬 전 :\n");

	for (int i = 0; i < num; i++)
	{
		printf("%d ", data[i]);
	}
	
	// 계산 파트

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

	// 출력 파트
	printf("\n정렬 후 :\n");

	for (int i = 0; i < num; i++)
	{
		printf("%d ", data[i]);
	}

	_getch();
	return 0;
}