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
	int n = 0;
	int ans = 0;
	int num = 10001;
	int* arr;
	arr = (int*)malloc((num ) * sizeof(int));
	for (int i = 0; i < num; i++) {
		arr[i] = i;
	}
	arr[1] = 0;

	for (int i = 2; i < num; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i + i; j < num; j += i) {
			arr[j] = 0;
		}
	}

	scanf(" %d", &n);

	while (n--) {
		scanf(" %d", &num);
		
		for (int i = num/2;; i--) {
			if (num/2 == arr[i]) {
				printf("%d %d\n", num/2, num/2);
				break;
			}
			else if (i == arr[i]) {
				if (num - i == arr[num - i]) {
					printf("%d %d\n", i, num - i);
					break;
				}
			}
		}

	}
	free(arr);
	return 0;
}
