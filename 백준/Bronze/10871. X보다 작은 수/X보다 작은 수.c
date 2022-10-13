#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n = 0, a = 0;
	int num = 0;
	int time = 0;
	scanf(" %d %d", &n, &a);

	int *stan=(int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		scanf(" %d", &num);
		if (num < a) {
			stan[time] = num;
			time++;

		}
	}
	for (int i = 0; i < time; i++) {
		printf("%d ", stan[i]);
	}


	return 0;
}