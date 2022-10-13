#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 1, b = 1;

	while (scanf(" %d %d", &a, &b) != EOF) {
		/*scanf(" %d %d", &a, &b);
		if (a == 0 && b == 0) break;*/
		printf("%d\n", a + b);
	}



	return 0;
}