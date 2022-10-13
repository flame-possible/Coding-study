#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int arr[10];
	int num = 0;

	for (int i = 0; i < 10; i++) {
		scanf(" %d", &arr[i]);
	}
	for (int i = 0; i < 10; i++) {
		arr[i] = arr[i] % 42;
	}
	int overlap = 0;
	for (int i = 0; i < 10; i++) {
		int temp = 0;
		temp = arr[i];
		for (int k = i; k < 10; k++) {
			if (arr[k] == temp) {
				num++;
			}
		}
		if (num > 1) {
			overlap++;
		}
		num = 0;
	}
	printf("%d\n", 10-overlap);
	return 0;
}