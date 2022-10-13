#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0;
	int star = 0;
	//int arr[1000000] = { 0, };
	scanf("%d", &a);

	int* arr = (int*)malloc(sizeof(int) * a);

	for (int i = 0; i < a; i++) {
		scanf(" %d", &arr[i]);
	}
	int big = arr[0];
	int small = arr[0];
	for (int i = 0; i < a; i++) {
		if (arr[i] >= big) {
			big = arr[i];
		}
		if (arr[i] <= small) {
			small = arr[i];
		}
	}/*
	for (int i = 0; i < a; i++) {
		if (arr[i] <= small) {
			small = arr[i];
		}
	}*/
	
	printf("%d %d", small, big);
	free(arr);
	return 0;
}