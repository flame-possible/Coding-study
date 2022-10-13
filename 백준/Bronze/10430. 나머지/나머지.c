#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0, b = 0, c=0;

	scanf("%d %d %d", &a, &b, &c);

	printf("%d\n", (a + b)%c);
	printf("%d\n", ((a%c)+(b%c))%c);
	printf("%d\n", (a*b)%c);
	printf("%d\n", ((a%c)*(b%c))%c);

	return 0;
}
