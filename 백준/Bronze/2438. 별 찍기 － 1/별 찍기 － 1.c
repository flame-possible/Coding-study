#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0;

	scanf("%d", &a);

	for (int i = 0; i < a; i++) {
		for (int p = 0; p < i; p++) {
			printf("*");
		}
		printf("*\n");
	}

	return 0;
}
