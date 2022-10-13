#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{
	char arr[100] = { 0, };
	int temp[100] = { 0, };
	int ans[123] = { 0, };
	int num = 0;

	for (int i = 0; i < 123; i++) {
		ans[i] = -1;
	}
	for (int i = 0; i < 100; i++) {
		scanf("%[a-z]", &arr[i]);
		num++;
	}
	for (int i = 0; i < num; i++) {
		temp[i] = arr[i];
	}
	for (int i = 0; i < num; i++) {
		for (int k = 97; k < 123; k++) {
			if (temp[i] == k && ans[k]==-1) {
				ans[k] = i;
			}
		}
	}
	for (int i = 97; i < 123; i++) {
		printf("%d ", ans[i]);
	}
    return 0;
}
