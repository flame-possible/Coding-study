#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0;
	int star = 0;

	scanf("%d", &a);

	for (int i = 1; i < a ; i++) {
		for (int m = 0; m < i; m++) {
			printf("*");
		}
		printf("\n");
	}
	for (int i = 0; i < a ; i++) {
		for (int m = 0; m < a - i; m++) {
			printf("*");
		}
		printf("\n");
	}
	return 0;
}