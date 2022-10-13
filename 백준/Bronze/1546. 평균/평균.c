#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int num = 0;

	scanf("%d", &num);

	double* arr = (double*)malloc(sizeof(double) * num);

	for (int i = 0; i < num; i++) {
		scanf(" %lf", &arr[i]);
	}

	double compare = 0;
	for (int i = 0; i < num; i++) {
		if (compare <= arr[i]) {
			compare = arr[i];
		}
	}
	compare /= 100;

	for (int i = 0; i < num; i++) {
		arr[i] /= compare;
	}
	compare = 0;
	for (int i = 0; i < num; i++) {
		compare += arr[i];
	}

	printf("%lf", compare / num);

	return 0;
}