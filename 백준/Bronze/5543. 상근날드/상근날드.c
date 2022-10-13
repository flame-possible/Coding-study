#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0, b=0, c=3;
	int arr[2][3] = { 0, };
	int set[3][2] = { 0, };
	int sort[6] = { 0, };
	for (int i = 0; i < 2; i++) {
		for (int k = 0; k < c; k++) {
			scanf(" %d", &a);
			arr[i][k] = a;
		}
		c--;
	}
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			set[i][k] = arr[0][i] + arr[1][k]-50;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 2; k++) {
			sort[b] = set[i][k];
			b++;
		}
	}
	for (int i = 5; i > 0; i--) {
		for (int m = 0; m < i; m++) {
			int temp = 0;
			if (sort[m] > sort[m + 1]) {
				temp = sort[m];
				sort[m] = sort[m + 1];
				sort[m + 1] = temp;
			}
		}
	}
	printf("%d", sort[0]);

	return 0;
}