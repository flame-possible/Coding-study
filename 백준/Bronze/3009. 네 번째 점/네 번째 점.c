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
	int arr[4][2] = { 0, };
	int en = 0;
	for (int i = 0; i < 3; i++) {
		scanf(" %d %d", &arr[i][0], &arr[i][1]);
	}
	
	for (int i = 0; i < 2; i++) {
		if (arr[0][i] == arr[1][i]) {
			arr[3][i] = arr[2][i];
		}
		else if (arr[0][i] == arr[2][i]) {
			arr[3][i] = arr[1][i];
		}
		else if (arr[1][i] == arr[2][i]) {
			arr[3][i] = arr[0][i];
		}
		
	}

	printf("%d %d", arr[3][0], arr[3][1]);
	

	return 0;
}
