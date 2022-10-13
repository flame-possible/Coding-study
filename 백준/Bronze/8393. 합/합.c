#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n = 0;
	int ans = 0;
	scanf("%d", &n);
	for (; n > 0; n--) {
		ans += n;
	}
	printf("%d", ans);

	return 0;
}
