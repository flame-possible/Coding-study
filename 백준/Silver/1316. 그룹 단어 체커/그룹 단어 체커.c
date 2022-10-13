#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{
	int big = 0;
	int times[101] = { 0, };
	char arr[101][101] = { 0, };

	scanf("%d", &big);

	for (int i = 0; i < big; i++) {
		scanf("%s", &arr[i][0]);
	}
	for (int i = 0; i < big; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 0) {
				break;
			}
			times[i] += 1;
		}
	}
	int num = big;
	for (int i = 0; i < big; i++) {
		for (int j = 0; j < times[i]; j++) {
			for (int k = j; k < times[i]; k++) {
				if ((arr[i][j] != arr[i][j + 1]) && (arr[i][j] == arr[i][k + 2])) {
					num--;
					i++;
					j = -1;
					break;
				}
			}
		}
	}
	printf("%d", num);

	return 0;
}
