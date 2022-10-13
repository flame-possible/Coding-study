#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int sort[3] = { 0, };
	
	for (int i = 0; i < 3; i++) {
		scanf(" %d", &sort[i]);
	}
	for (int i = 2; i > 0; i--) {
		for (int m = 0; m < i; m++) {
			int temp = 0;
			if (sort[m] > sort[m + 1]) {
				temp = sort[m];
				sort[m] = sort[m + 1];
				sort[m + 1] = temp;
			}
		}
	}
	printf("%d", sort[1]);

	return 0;
}