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
	int a = 0;
	int cal = 0;
	for (int i = 0; i < 5; i++) {
		scanf(" %d", &a);
		cal += pow(a, 2);
	}
	printf("%d", cal % 10);


	return 0;
}
