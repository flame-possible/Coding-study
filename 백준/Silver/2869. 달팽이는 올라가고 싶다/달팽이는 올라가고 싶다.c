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
	int a=0, b=0, v=0;
	int goal = 0;
	int day = 0;
	int temp = 0;
	scanf(" %d %d %d", &a, &b, &v);

	goal = v - a;
	temp = a - b;
	day = goal / temp +1;
	if (goal % temp != 0) {
		day += 1;
	}


	printf("%d", day);
	return 0;
}