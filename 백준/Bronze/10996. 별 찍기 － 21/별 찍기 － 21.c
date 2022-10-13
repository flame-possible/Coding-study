#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0;
	int star = 0;

	scanf("%d", &a);

	if (a == 1) {
		printf("*");
		return 0;
	}
	for (int time = 0; time < a; time++) {
		for (int i = 0; i < a; i++) {
			if (i % 2 == 0) {
				printf("*");
			}
			if (i % 2 != 0) {
				printf(" ");
			}
		}
		printf("\n");
		for (int i = 0; i < a; i++) {
			if (i % 2 == 0) {
				printf(" ");
			}
			if (i % 2 != 0) {
				printf("*");
			}
		}
		if (time < a - 1) {
			printf("\n");
		}
	}

	return 0;
}