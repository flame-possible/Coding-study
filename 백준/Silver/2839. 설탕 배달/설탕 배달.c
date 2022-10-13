#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<cursor.h>
//#include<time.h>
//#include<conio.h>

int main()
{
	int n, a;
	scanf("%d", &n);

	int ans = -1;
	for (a = 0; a * 5 <= n; a++)
		if ((n - a * 5) % 3 == 0)
			ans = a + ((n - a * 5) / 3);

	printf("%d", ans);

	return 0;
}
