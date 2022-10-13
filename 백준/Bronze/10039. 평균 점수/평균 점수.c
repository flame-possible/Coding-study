#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0;
	int result = 0;
	
	int arr[5];

	for (int i = 0; i < 5; i++) {
		scanf(" %d", &a);
		if (a <= 40) {
			a = 40;
		}
		arr[i] = a;
		result += arr[i];
	}
	printf("%d", result / 5);

	return 0;
}