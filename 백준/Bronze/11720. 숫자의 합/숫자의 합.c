#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int stan = 0;
	int plus = 0;
	int input = 0;
	scanf(" %d", &stan);
	getchar();
	for (int i = 0; i < stan; i++) {
		input = getchar();
		for (int j = 0; j < 11; j++) {
			if (input == 48)input = 0;
			else if (input == 49)input = 1;
			else if (input == 50)input = 2;
			else if (input == 51)input = 3;
			else if (input == 52)input = 4;
			else if (input == 53)input = 5;
			else if (input == 54)input = 6;
			else if (input == 55)input = 7;
			else if (input == 56)input = 8;
			else if (input == 57)input = 9;
		}
		plus = plus + input;
	}
	printf("%d", plus);

	return 0;
}
