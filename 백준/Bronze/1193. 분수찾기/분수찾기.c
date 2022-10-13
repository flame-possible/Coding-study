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
	int stan = 0;
	scanf("%d", &stan);

	if (stan == 1) {
		printf("1/1");
		return 0;
	}
	int a=2, b=3, c=4, d=6;
	int a1 = 5, b1 = 7, c1 = 7, d1 = 9;
	int y1 = 2, x1 = 1, y2 = 1, x2 = 3;
	for (int i = 0;; i++) {
		a1 += i * 4;
		b1 += i * 4;
		c1 += i * 4;
		d1 += i * 4;
		
		if (stan >= a && stan <= b) {
			int num = stan - a;

			for (int j = 0; j < num; j++) {
				x1 += 1;
				y1 -= 1;
			}
			printf("%d/%d", x1, y1);
			return 0;
		}
		else if (stan >= c && stan <= d) {
			int num = stan - c;
			for (int j = 0; j < num; j++) {
				x2 -= 1;
				y2 += 1;
			}
			printf("%d/%d", x2, y2);
			return 0;
		}
		a += a1;
		b += b1;
		c += c1;
		d += d1;
		y1 += 2;
		x2 += 2;
        a1 = 5, b1 = 7, c1 = 7, d1 = 9;
	}


	return 0;
}