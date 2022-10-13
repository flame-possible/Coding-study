#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<cursor.h>
//#include<time.h>
//#include<conio.h>

int main()
{
	
	int x, y, w, h;
	int a = 0, b = 0;

	scanf(" %d %d %d %d", &x, &y, &w, &h);
	a = w - x >= h - y ? h - y : w - x;
	b = x > y ? y : x;

	printf("%d",a > b ? b : a);

	return 0;
}
