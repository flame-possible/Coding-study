#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int leap;

	scanf(" %d", &leap);

	if (leap % 4 == 0) {
		if (leap >= 100) {
			if (leap % 100 == 0) {
				if (leap % 400 == 0) {
					printf("1");
				}
				else printf("0");
			}
			else printf("1");
		}
		else printf("1");
	}
	else if (leap % 4 != 0) {
		printf("0");
	}


	return 0;
}
