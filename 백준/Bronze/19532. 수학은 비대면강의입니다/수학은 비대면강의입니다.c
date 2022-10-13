#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{
	int str[10] = { 0, };
	int x = 0, y = 0;
	int temp = 0;
	for (int i = 0; i < 6; i++) {
		scanf(" %d", &str[i]);
	}
	if (str[0] == 0 || str[1] == 0 || str[3] == 0 || str[4] == 0) {
		if (str[0] == 0) {
			y = str[2] / str[1];
			temp = str[4] * y;
			str[5] -= temp;
			x = str[5] / str[3];
		}
		else if (str[1] == 0) {
			x = str[2] / str[0];
			temp = str[3] * x;
			str[5] -= temp;
			y = str[5] / str[4];
		}
		else if (str[3] == 0) {
			y = str[5] / str[4];
			temp = str[1] * y;
			str[2] -= temp;
			x = str[2] / str[0];
		}
		else if (str[4] == 0) {
			x = str[5] / str[3];
			temp = str[0] * x;
			str[2] -= temp;
			y = str[2] / str[1];
		}
		printf("%d %d", x, y);
		return 0;
	}
	x = str[0], y = str[3];
		for (int i = 0; i < 6; i++) {
			if (i >= 0 && i <= 2) {
				str[i] *= y;
			}
			else if (i >= 3 && i <= 5) {
				str[i] *= x;
			}
		}
	

	if ((str[0] > 0 && str[3] > 0) || (str[0] < 0 && str[3] < 0)) {
		str[3] *= -1;
		str[4] *= -1;
		str[5] *= -1;
	}
	str[1] += str[4];
	str[2] += str[5];
	if (str[1] == 0) {	
		y = 0;
	}
	else if (str[1] != 0) {
		y = str[2] / str[1];
	}
	str[4] *= y;
	str[5] -= str[4];
	if ((str[3] < 0 && str[5]>0) || (str[3] > 0 && str[5] < 0)) {
		str[3] *= -1;
		if (str[3] == 0) {
			x = 0;
		}
		else if (str[3] != 0) {
			x = str[5] / str[3];
		}
		printf("%d %d", -x, y);
	}
	else {
		if (str[3] == 0) {
			x = 0;
		}
		else if (str[3] != 0) {
			x = str[5] / str[3];
		}
		printf("%d %d", x, y);
	}

	return 0;
}