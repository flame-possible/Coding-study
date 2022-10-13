#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void selfnumber(void);

int main()
{
	selfnumber();

	return 0;
}

void selfnumber(void) {

	int stan = 0;
	int one = 0, ten = 0, hun = 0, thou = 0, mil = 0;
	int number[10001] = { 0, };
	int arr[10001] = { 0, };

	for (int i = 1; i < 10001; i++) {
		number[i] = i;
		arr[i] = i;
	}

	for (int i = 1; i < 10001; i++) {
		if (number[i] < 10) {
			stan = number[i]+number[i];
			arr[stan] = 0;

		}
		else if (number[i] < 100 && number[i]>9) {
			ten = i / 10;
			one = i - ten * 10;
			stan = ten + one + i;
			arr[stan] = 0;
		}
		else if (number[i] < 1000 && number[i]>99) {
			hun = i / 100;
			ten = (i-(hun*100)) / 10;
			one = i -(hun*100)- ten * 10;
			stan = hun + ten + one + i;
			arr[stan] = 0;
		}
		else if (number[i] <= 10000 && number[i]>999) {
			thou = i / 1000;
			hun = (i -(thou*1000))/ 100;
			ten = (i - (thou*1000)-(hun * 100)) / 10;
			one = i - (thou*1000)-(hun*100)-ten * 10;
			stan = thou + hun + ten + one + i;
			if (stan > 10000) {
				stan = 0;
			}
			arr[stan] = 0;
		}
		if (arr[i] != 0) {
			printf("%d\n", arr[i]);
		}
		stan = 0;
	}
}