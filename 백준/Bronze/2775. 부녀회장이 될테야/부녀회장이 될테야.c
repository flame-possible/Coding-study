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
	int arr[16][16] = { 0, };

	for (int i = 0; i < 15; i++) {
		arr[0][i] = i + 1;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			for (int k = 0; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
			}
		}
	}

	int test = 0;
	scanf("%d", &test);
	int a, b;
	for (int i = 0; i < test; i++) {
		scanf(" %d", &a);
		scanf(" %d", &b);
		printf("%d\n", arr[a][b-1]);
	}
	return 0;
}
