#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{
	char arr[101] = { 0, };
	int num = 0;
	
	scanf("%s", &arr);
	for (int i = 0; i < 101; i++) {
		if (arr[i] == 0) {
			break;
		}
		num++;
	}
	int a = num;
	for (int i = 0; i < 101; i++) {
		if (arr[i] == 0) {
			break;
		}
		if (arr[i] == 'c') {
			if (arr[i+1] == '=') {
				i++;
				num--;
			}
			else if (arr[i+1] == '-') {
				i++;
				num--;
			}
			else continue;
		}
		else if (arr[i] == 'd') {
			if (arr[i+1] == 'z') {
				if (arr[i+2] == '=') {
					i += 2;
					num-=2;
				}
				else continue;
			}
			else if (arr[i + 1] == '-') {
				i++;
				num--;
			}
			else continue;
		}
		else if (arr[i] == 'l') {
			if (arr[i+1] == 'j') {
				i++;
				num--;
			}
			else continue;
		}
		else if (arr[i] == 'n') {
			if (arr[i+1] == 'j') {
				i++;
				num--;
			}
			else continue;
		}
		else if (arr[i] == 's') {
			if (arr[i+1] == '=') {
				i++;
				num--;
			}
			else continue;
		}
		else if (arr[i] == 'z') {
			if (arr[i+1] == '=') {
				i++;
				num--;
			}
			else continue;
		}
	}
	printf("%d", num);

	return 0;
}

