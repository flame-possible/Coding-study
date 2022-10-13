#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{
	int check(char a);
	char arr[20] = { 0, };
	int sum = 0;

	scanf("%s", &arr);

	for (int i = 0; i < 15; i++) {
		if (arr[i] < 65 || arr[i]>90) {
			break;
		}
		char all = arr[i];
		sum += check(all);
	}
	printf("%d", sum);

	return 0;
}

int check(char a) {
	int num = 0;
	if (a >= 65 && a <= 67) {
		num += 3;
	}
	else if (a >= 68 && a <= 70) {
		num += 4;
	}
	else if (a >= 71 && a <= 73) {
		num += 5;
	}
	else if (a >= 74 && a <= 76) {
		num += 6;
	}
	else if (a >= 77 && a <= 79) {
		num += 7;
	}
	else if (a >= 80 && a <= 83) {
		num += 8;
	}
	else if (a >= 84 && a <= 86) {
		num += 9;
	}
	else if (a >= 87 && a <= 90) {
		num += 10;
	}
	return num;
}