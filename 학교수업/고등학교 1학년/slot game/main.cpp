#include "Turboc.h"

int game_interface(void);
int PressAnyKey(void);

int main(void)
{
	char icon[10] = {'7', '$', '$', '*', '*', '*', '!', '!' , '!', '!'};
	char A, B, C;
	int money;
	int have_money = 10000;

	while (1)
	{
		game_interface();
		printf("Yours money : %d\n", have_money);
		printf("\n배팅할 돈을 입력하세요. (종료하시려면 '0'을 입력하세요): ");
		scanf("%d", &money);

		if (money == 0)
		{
			break;
		}

		else if (money < 0 || have_money < money)
		{
			printf ("\nError!!! Try again\n");
		}

		else
		{
			randomize();

			A = random(10);
			B = random(10);
			C = random(10);

			printf("\n%c %c %c\n", icon[A], icon[B], icon[C]);

			if (icon[A] == '!' && icon[B] == '!' && icon[C] != '!')
			{
				printf ("\nCongratulation!!! You money is x 3!!!\n");
				money *= 3;
				have_money += money;
			}

			else if (icon[A] != '!' && icon[B] == '!' && icon[C] == '!')
			{
				printf ("\nCongratulation!!! You money is x 3!!!\n");
				money *= 3;
				have_money += money;
			}

			else if (icon[A] == '!' && icon[B] != '!' && icon[C] == '!')
			{
				printf ("\nCongratulation!!! You money is x 3!!!\n");
				money *= 3;
				have_money += money;
			}

			else if (icon[A] == '!' && icon[B] == '!' && icon[C] == '!')
			{
				printf ("\nCongratulation!!! You money is x 5!!!\n");
				money *= 5;
				have_money += money;
			}

			else if (icon[A] == '*' && icon[B] == '*' && icon[C] == '*')
			{
				printf ("\nCongratulation!!! You money is x 10!!!\n");
				money *= 10;
				have_money += money;
			}

			else if (icon[A] == '$' && icon[B] == '$' && icon[C] == '$')
			{
				printf ("\nCongratulation!!! You money is x 50!!!\n");
				money *= 50;
				have_money += money;
			}

			else if (icon[A] == '7' && icon[B] == '7' && icon[C] == '7')
			{
				printf ("\nCongratulation!!! You money is x 100!!!\n");
				money *= 100;
				have_money += money;
			}

			else
			{
				have_money -= money;
			}

			if (have_money == 0)
			{
				printf ("\nYou don't have money!!! good bye~\n");
				break;
			}
		}

		PressAnyKey();
		clrscr();
	}

	PressAnyKey();
	return 0;
}

int game_interface(void)
{
	printf("7 X 3 \t= 배팅금 X 100\n");
	printf("$ X 3 \t= 배팅금 X 50\n");
	printf("* X 3 \t= 배팅금 X 10\n");
	printf("! X 3 \t= 배팅금 X 5\n");
	printf("! X 2 \t= 배팅금 X 3\n");

	return 0;
}

int PressAnyKey(void)
{
	printf("\n아무키나 눌러주세요.");
	_getch();
	return 0;
}