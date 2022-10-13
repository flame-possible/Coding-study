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
	int arr[16] = { 0, };

	for (int i = 0; i < 15; i += 2) {
		scanf(" %d", &arr[i]);
	}

	for (int i = 0, j=1, k=8; i < 15; i += 2, j++,k--) {
		if (j == arr[i]) {
			k = 0;
			continue;
		}
		else if (k == arr[i]) {
			j = 0;
			continue;
		}
		else {
			printf("mixed");
			return 0;
		}
	}
	if (arr[14] == 8) {

		printf("ascending");
	}
	else if (arr[14] == 1) {
		printf("descending");
	}

	return 0;
}
