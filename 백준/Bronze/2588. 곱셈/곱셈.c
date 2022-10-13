#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0, b = 0;

	scanf("%d %d", &a, &b);

	int hun = 0;
	int ten = 0;
	int one = 0;

	hun = b / 100;
	ten = (b - hun * 100) / 10;
	one = ((b - hun * 100) - ten * 10);

	printf("%d\n", a*one);
	printf("%d\n", a*ten);
	printf("%d\n", a*hun);
	printf("%d\n", a*b);

	return 0;
}
