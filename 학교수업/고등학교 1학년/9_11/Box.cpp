void Box(int x, int y, int w, int h)
{
	int i, j;
	gotoxy(x, y);	puts("¦£");
	for(j = 2; j <= w; j+=2 )
	{
		gotoxy(x+j, y);		puts("¦¡");
	}
	gotoxy(x+j, y);	puts("¦¤");

	for( i = 1; i <= h; ++i )
	{
		gotoxy(x, y+i);	puts("¦¢");
		for(j = 2; j <= w; j+=2 )
		{
			gotoxy(x+j, y+i);		puts("  ");
		}
		gotoxy(x+j, y+i);	puts("¦¢");
	}
	gotoxy(x, y+h);	puts("¦¦");
	for(j = 2; j <= w; j+=2 )
	{
		gotoxy(x+j, y+h);		puts("¦¡");
	}
	gotoxy(x+j, y+h);	puts("¦¥");
}