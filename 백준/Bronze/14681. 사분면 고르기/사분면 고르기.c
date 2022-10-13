#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int x =0, y=0;

	scanf(" %d %d", &x, &y);

	if (x > 0 && y > 0) {
		printf("1");
	}

	else if (x < 0 && y>0) {
		printf("2");
	}
	else if (x < 0 && y<0) {
		printf("3");
	}
	else if (x > 0 && y<0) {
		printf("4");
	}
	return 0;
}
