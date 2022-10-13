#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int x =0, y=0;
	int sum1 = 0;
	int sum2 = 0;

	scanf(" %d %d", &x, &y);

	sum1 += x * 60;
	sum1 += y;

	sum2 = sum1 - 45;

	if (sum2 < 0) {
		sum2 += 24 * 60;
	}

	printf("%d %d", sum2 / 60, sum2 % 60);
	

	return 0;
}