#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	double a = 0, b = 0;

	scanf("%lf %lf", &a, &b);

	printf("%.9lf", a / b);

	return 0;
}
