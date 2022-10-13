#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a=0, b=0, c =0;
	int cal = 0;
	int arr1[10];
	int arr2[10];
	int con = 1000000000;
	int reserve = 0;
	scanf("%d %d %d", &a, &b, &c);

	cal = a * b * c;
	for (int i = 0; i < 10; i++) {
		reserve = cal/ con;
		cal -= con * reserve;
		con = con/ 10;
		arr1[i] = reserve;
	}
	int k = 0;
	while (1) {
		if (arr1[k] != 0) {
			break;
		}
		k++;
	}
	int p = 0;
	for (int i = 0; i < 10; i++) {
		for (int m = k; m < 10; m++) {
			if (arr1[m] == i) {
				p++;
			}
		}
		arr2[i] = p;
		p = 0;
	}
	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr2[i]);
	}
	return 0;
}