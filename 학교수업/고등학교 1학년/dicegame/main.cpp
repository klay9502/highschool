#include "Turboc.h"

int inGame(void);
int inScore(void);
int random_dice(void);
int deal(int have_money);

int have_money = 10000;
int All = 0, Win = 0, Lose = 0, Draw = 0;

int main(void)
{
	int code;

	while (1)
	{
		if (have_money <= 0)
		{
			printf("\n*** You don't have money!!! ***");
			_getch();
			break;
		}

		printf("\n*** Dice Game ***\n\n");
		printf("1. Play the Game\n");
		printf("2. Score\n");
		printf("3. Exit\n");
		printf("\nInput : ");
		scanf("%d", &code);

		switch (code)
		{
		case 1:
			clrscr();
			inGame();
			break;
			
		case 2:
			clrscr();
			inScore();
			break;
			
		case 3:
			exit(1);
		}
	}

	return 0;
}

int inGame(void)
{
	int choose;
	int your_dice, com_dice;
	int deal_money;

	your_dice = random_dice();

	printf("------------------------------------\n");
	printf("Your Money : %d\\\n", have_money);
	printf("------------------------------------\n");
	printf("Your dice is... %d\n", your_dice);
	printf("------------------------------------\n");
	printf("Call or Die? (1. Call / 2. Die) : ");
	scanf("%d", &choose);

	switch (choose)
	{
	case 1:
		deal_money = deal(have_money);
		com_dice = random_dice();

		printf("Computer dice is... %d\n", com_dice);

		if (com_dice > your_dice)
		{
			printf("\nYou Lose!!!\n");
			have_money -= deal_money;
			Lose++;
		}

		if (com_dice < your_dice)
		{
			printf("\nYou Win!!!\n");
			have_money += deal_money;
			Win++;
		}

		if (com_dice == your_dice)
		{
			printf("\nDraw..\n");
			Draw++;
		}

		All++;
		break;

	case 2:
		printf("Standard betting money(10\) are lost...\n");
		have_money -= 10;
		break;

	default:
		printf("Code Error\n");
		break;

	}
	
	_getch();
	clrscr();
	return 0;
}

int random_dice(void)
{
	int dice, dice_sum = 0;

	for (int i = 0; i < 3; i++)
	{
		randomize();

		dice = random(6) + 1;
		dice_sum += dice;
	}

	return dice_sum;
}

int deal(int have_money)
{
	int deal_money;

	printf("Please deal your money (10\\ ~ %d\\) : ", have_money);
	scanf("%d", &deal_money);

	if (deal_money % 10 != 0 || deal_money < 0)
		deal(have_money);

	return deal_money;
}

int inScore(void)
{
	printf("Your Money : %d\\\n", have_money);
	printf("%dALL %dW %dL %dD", All, Win, Lose, Draw);

	_getch();
	clrscr();
	return 0;
}