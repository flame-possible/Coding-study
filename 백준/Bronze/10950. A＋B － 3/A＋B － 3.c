#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n = 0;
	int num = 0;
	int a = 0, b = 0;
	

	scanf("%d", &n);

	int** test = malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		test[i] = malloc(sizeof(int) * 2);
	}


	for (int i = 0; i < n; i++) {
		scanf(" %d %d", &a, &b);
		test[i][0] = a;
		test[i][1] = b;
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", test[i][0]+test[i][1]);
	}

	for (int i = 0; i < n; i++) {
		free(test[i]);
	}
	free(test);

	return 0;
}