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
	int a = 0, b = 0;
	int ans = 0;
	int wick = 0;
	int num = 123456;
	int* arr;
	arr = (int*)malloc((num * 2 + 1) * sizeof(int));
	for (int i = 0; i < num * 2 + 1; i++) {
		arr[i] = i;
	}
	arr[1] = 0;

	for (int i = 2; i < num * 2 + 1; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i + i; j < num * 2 + 1; j += i) {
			arr[j] = 0;
		}
	}


	while (1) {
		scanf(" %d", &num);
		if (num == 0) {
			return 0;
		}
		for (int i = num+1; i < num * 2+1; i++) {
			if (arr[i] != 0) {
				ans++;
			}
		}
		for (int i = a; i <= b; i++) {
				printf("%d\n", ans);
		}
		ans = 0;
	}
	free(arr);
	return 0;
}
