#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0;
	int star = 0;

	scanf("%d", &a);
	star = a;
	for (int i = 0; i < a ; i++) {
		for (int k = 0; k < i; k++)printf(" ");
		for (int m = 0; m<star*2-1; m++) {
			printf("*");
		}
		printf("\n");
		
		star -= 1;
	}
	star = 3;
	for (int i = 0; i < a-1 ; i++) {
		for (int k = a-2; k > i; k--)printf(" ");
		for (int m = 0;m<star; m++) {
			printf("*");
		}
		printf("\n");
		star += 2;
		if (star > a*2-1) {
			break;
		}
	}
	return 0;
}