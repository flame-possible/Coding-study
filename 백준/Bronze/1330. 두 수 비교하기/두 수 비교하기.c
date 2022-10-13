#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0, b = 0;

	scanf(" %d %d", &a, &b);

	if (a > b) {
		printf(">");
	}

	else if (a < b) {
		printf("<");
	}

	else if (a == b) {
		printf("==");
	}

	return 0;
}
