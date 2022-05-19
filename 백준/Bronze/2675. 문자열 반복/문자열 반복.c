#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{
	int stan = 0;
	int num = 0;
	char arr[21] = { 0, };
	int len = 0;

	scanf(" %d", &stan);
	for (int i = 0; i < stan; i++) {
		scanf(" %d", &num);
		scanf(" %s", &arr);
		len = strlen(arr);
		for (int j = 0; j < len; j++) {
			for (int k = 0; k < num; k++) {
				printf("%c", arr[j]);
			}
			
		}
		printf("\n");
	}
	return 0;
}
