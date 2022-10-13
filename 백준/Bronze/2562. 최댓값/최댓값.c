#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int arr[9] = { 0, };

	for (int i = 0; i < 9; i++) {
		scanf(" %d", &arr[i]);
	}
	int big = 0, num = 0;
	for (int i = 0; i < 9; i++) {
		if (big < arr[i]) {
			big = arr[i];
			num = i;
		}
	}

	printf("%d\n%d", big, num+1);

	return 0;
}