#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n = 0;
	int ans = 0;
	int a = 0, b = 0;
	scanf("%d", &n);
	a = n;
	for (; a > 0; a--) {
		printf("%d\n", n-(a-1));
	}

	return 0;
}
