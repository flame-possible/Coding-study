#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 0;

	scanf("%d", &a);
	char *arr = (char*)malloc(sizeof(char) * a);
	for (int i = 0; i < a; i++) {
		arr[i] = ' ';
	}
	for (int i = a; i > 0; i--) {
		arr[i-1] = '*';
		for (int p = 0; p < a; p++) {
			printf("%c", arr[p]);
		}
		printf("\n");
	}
	
	free(arr);

	return 0;
}
