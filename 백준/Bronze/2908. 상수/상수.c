#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{
	char arr[10][10] = { 0, };
	int a = 0;
	char b = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			arr[i][j] = getchar();
		}
		b= getchar();
	}
	
		for (int j = 2; j >= 0; j--) {
			
			if (arr[0][j] > arr[1][j]) {
				a = 2;
				break;
			}
			else if (arr[0][j] < arr[1][j]) {
				a = 3;
				break;
			}
			else if (arr[0][j] == arr[1][j]) {
				continue;
			}

		}
		int k = 2;
		for (int j = 0; j < 3; j++) {
			arr[a][j] = arr[a-2][k];
			k--;
			printf("%c", arr[a][j]);
		}
	
	return 0;
}
