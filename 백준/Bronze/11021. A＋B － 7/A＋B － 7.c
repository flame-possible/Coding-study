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
	for (; ans < n; ans++) {
		scanf(" %d %d", &a, &b);
		printf("Case #%d: %d\n", ans+1, a+b);
	}

	return 0;
}
