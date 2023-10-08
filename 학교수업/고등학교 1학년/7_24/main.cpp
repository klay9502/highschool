/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int data = 10;
	int *ptr;
	ptr = &data;

	printf("data Addr = %x\n", &data);
	printf("data Value = %d\n", data);

	printf("ptr Addr = %x\n", &ptr);
	printf("ptr Value = %d\n", ptr);

	printf("ptr's Point Value = %d\n", *ptr);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 5;

	printf("%d\n", a);
	printf("%u\n", &a);
	printf("%p\n", &a);
	printf("%x\n", &a);
	printf("%X\n", &a);


	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void main()
{
	int a = 3;
	int *pt = &a;
	
	*pt = 2 + 3;

	printf("\n\n");
	printf("pt의 주소는 %p이다.\n", &pt);
	printf("pt의 내부값을 가리키는 주소로는 %p이다. \n\n", pt);
	printf("a의 주소는 %p이다. \n", &a);
	printf("a의 메모리에 저장된 값은 %d이다, \n", a);

	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void Square(int, int*);

void main()
{
	int Number, Level;

	Level = 2;
	Number = 3;
	Square(Level, &Number);

	printf("%d, %d\n", Level, Number);

	Level = 3;
	Number = 8;
	Square(Level, &Number);

	printf("%d, %d\n", Level, Number);
	_getch();
}

void Square(int lv, int *ret)
{
	if (lv == 2)
		*ret = *ret * *ret;
	else if (lv == 3)
		*ret = *ret * *ret * *ret;
}
*/

/*
#include <stdio.h>
#include <conio.h>

void swap(int *val1, int *val2)
{
	int temp;

	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void main()
{
	int val1, val2;
	
	val1 = 10;
	val2 = 20;

	swap(&val1, &val2);

	printf("val1 = %d, val2 = %d\n", val1, val2);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void sort2(int *na, int *nb)
{
	int temp;

	if (*na > *nb) {
		temp = *na;
		*na = *nb;
		*nb = temp;
	}

}

void main()
{
	int na, nb;

	puts("두 개의 정수값을 입력해주세요.");
	printf("정수 A : "); scanf("%d", &na);
	printf("정수 b : "); scanf("%d", &nb);

	sort2(&na, &nb);;

	puts("이들의 값을 오름차순으로 나열합니다.");
	printf("정수 A는 %d입니다.\n", na);
	printf("정수 B는 %d입니다.\n", nb);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

void swap(int *nx, int *ny)
{
	int temp;

	temp = *nx;
	*nx = *ny;
	*ny = temp;

}

void sort3(int *n1, int *n2, int *n3)
{
	if (*n1 > *n2)
		swap(n1, n2);
	if (*n2 > *n3)
		swap(n2, n3);
	if (*n1 > *n2)
		swap(n1, n2);
}

void main()
{
	int na, nb, nc;

	puts("세 개의 정수값을 입력해주세요.");
	printf("정수 A : "); scanf("%d", &na);
	printf("정수 b : "); scanf("%d", &nb);
	printf("정수 c : "); scanf("%d", &nc);

	sort3(&na, &nb, &nc);;

	puts("이들의 값을 오름차순으로 나열합니다.");
	printf("정수 A는 %d입니다.\n", na);
	printf("정수 B는 %d입니다.\n", nb);
	printf("정수 C는 %d입니다.\n", nc);
	_getch();
}
*/

/*
#include <stdio.h>
#include <conio.h>

int day[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

// year가 윤년이라면 1을 그렇지 않다면 0을 반환

int isleap(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
		return 1;
	else
		return 0;
}

void yesterday(int *y, int *m, int *d)
{
	int code;
	code = isleap(*y);

	switch (code) {
	case 0:
		if (*d != day[0][*m]) {
			(*d)++;
		} else {
			*d = 1;
			(*m)++;
			if (*m > 12) {
				*m = 1;
				(*y)++;
			}
		}
		break;
	case 1:
		if (*d != day[1][*m]) {
			(*d)++;
		} else {
			*d = 1;
			(*m)++;
			if (*m > 12) {
				*m = 1;
				(*y)++;
			}
		}
	}
}

void tomorrow(int *y, int *m, int *d)
{
	int code;
	code = isleap(*y);

	switch (code) {
	case 0:
		if (*d != 1) {
			(*d)--;
		} else {
			*d = day[0][*m];
			(*m)--;
			if (*m < 1) {
				*m = 12;
				(*y)--;
			}
		}
		break;
	case 1:
		if (*d != 1) {
			(*d)--;
		} else {
			*d = day[1][*m];
			(*m)--;
			if (*m < 1) {
				*m = 12;
				(*y)--;
			}
		}
	}
}

void main()
{
	int y, m, d;
	int ay, am, ad;
	int by, bm, bd;

	printf("년:"); scanf("%d", &y);
	printf("월:"); scanf("%d", &m);
	printf("일:"); scanf("%d", &d);

	ay = by = y;
	am = bm = m;
	ad = bd = d;

	yesterday(&ay, &am, &ad);
	tomorrow(&by, &bm, &bd);

	printf("다음날 : %d년%d월%d일\n", ay, am, ad);
	printf("전날 : %d년%d월%d일\n", by, bm, bd);

	_getch();
}
*/