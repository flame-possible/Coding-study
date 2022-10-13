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
	int num = 0;
	scanf(" %d %d", &a, &b);
	int* arr = (int*)malloc((b+1) * sizeof(int));
	for (int i = 0; i <= b; i++) {
		arr[i] = i;
	}
	
	for (int i = 2; i <= b; i++) {
		if (arr[i] == 0) {
			continue;
		}
		for (int j = i + i; j <= b; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = a; i <= b; i++) {
        if (arr[i] != 0 && arr[i] != 1) {
			printf("%d\n", arr[i]);
		}
	}
	
	return 0;
}
