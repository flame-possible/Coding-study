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
	int num = 0;
	scanf("%d", &n);

	for (int i = 0; i < 166666668; i++) {
		num += i * 6;
		if (n == 1) {
			printf("%d", i + 1);
			break;
		}
		if (n <= num+1) {
			printf("%d", i+1);
			break;
		}
	}

	return 0;
}