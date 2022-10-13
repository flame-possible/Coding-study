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
	int h, w, n;
	int sum, num;
	int data;
	scanf("%d", &data);


	for (int i = 0; i < data; i++)
	{
		scanf("%d %d %d", &h, &w, &n);

		sum = n % h;
		num = n / h;

		if (sum > 0)num++;
		if (sum == 0) { printf("%d%.2d\n", h, num); }

		else {
			printf("%d%.2d\n", sum, num);
		}
	}
	return 0;
}
