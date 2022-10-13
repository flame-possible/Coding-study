#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int standard;

	scanf(" %d", &standard);

	if (standard >= 90) {
		printf("A");
	}
	else if (standard >= 80 && standard < 90) {
		printf("B");
	}
	else if (standard >= 70 && standard < 80) {
		printf("C");
	}
	else if (standard >= 60 && standard < 70) {
		printf("D");
	}
	else if (standard < 60) {
		printf("F");
	}

	return 0;
}