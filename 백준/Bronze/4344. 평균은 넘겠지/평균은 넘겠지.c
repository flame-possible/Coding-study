#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int num = 0;
	int cul = 0;
	double cal = 0;
	int stan = 0;

	scanf(" %d", &num);

	int** arr = (int**)malloc(sizeof(int*) * num);
	for (int i = 0; i < num; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 1001);
	}
	for (int i = 0; i < num; i++) {
		for (int k = 0; k < 1001; k++) {
			arr[i][k] = 0;
		}
	}

	for (int i = 0; i < num; i++) {
		scanf(" %d", &cul);
		for (int k = 0; k < cul; k++) {
			scanf(" %d", &arr[i][k]);
			cal += arr[i][k];
		}
		cal = cal / cul;
		for (int m = 0; m < cul; m++) {
			if (arr[i][m] > cal) {
				stan++;
			}
		}
		cal = (double)stan * 100 / (double)cul;
		printf("%.3lf%%\n", cal);
		cal = 0;
		stan = 0;
	}	
	return 0;
}