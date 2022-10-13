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
	int num = 0;
	int ans = 0;
	scanf(" %d", &num);

	int* arr = (int*)malloc(num * sizeof(int));

	for (int i = 0; i < num; i++) {
		scanf(" %d", &arr[i]);
	}

	for (int i = 0; i < num; i++) {
		if (arr[i] == 1) {
			continue;
		}
		else if (arr[i] == 2) {
			ans++;
			continue;
		}
		for (int j = 2; j < 33; j++) {
			if (arr[i] % j == 0 && arr[i] > j) {
				ans--;
				break;
			}
		}
		ans++;
	}

	printf("%d", ans);

	return 0;
}
