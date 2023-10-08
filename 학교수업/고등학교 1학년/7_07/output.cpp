// p92 예제13

/*
#include <stdio.h>

extern int num;

void output()
{
	printf("%d\n", num);
}
*/

// p94 실전 4-1

/*
#include <stdio.h>

void save(int money)
{
	static int total = 0;
	total += money;
	printf("현재까지의 총 저축액 %d\n",total);
}
*/

#include <stdio.h>

	static int zro = 0;
	static int one = 0;
	static int two = 0;
	static int tre = 0;
	static int fur = 0;
	static int fiv = 0;
	static int six = 0;
	static int sev = 0;
	static int eig = 0;
	static int nin = 0;

void function(char ch)
{
	switch (ch) {
	case '0':
		zro++;
		break;
	case '1':
		one++;
		break;
	case '2':
		two++;
		break;
	case '3':
		tre++;
		break;
	case '4':
		fur++;
		break;
	case '5':
		fiv++;
		break;
	case '6':
		six++;
		break;
	case '7':
		sev++;
		break;
	case '8':
		eig++;
		break;
	case '9':
		nin++;
		break;
	}
}

void output()
{
	printf("숫자의 출현 횟수\n");
	printf(" 0: %d\t 1: %d\n", zro, one);
	printf(" 2: %d\t 3: %d\n", two, tre);
	printf(" 4: %d\t 5: %d\n", fur, fiv);
	printf(" 6: %d\t 7: %d\n", six, sev);
	printf(" 8: %d\t 9: %d\n", eig, nin);
}