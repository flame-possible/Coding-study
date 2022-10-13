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
	int a = 0, b = 0, c = 0;
	int even = 0;

	scanf(" %d %d %d", &a, &b, &c);

	if (b >= c) {
		printf("-1");
		return 0;
	}
	int temp = 0;
	temp = a;
	int cal = 0;
	cal = c - b;
	printf("%d", (a / cal) + 1);

	return 0;
}