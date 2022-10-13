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
	int test = 0;
	double a = 0, b = 0;
	int pres = 0;
	double a1 = 0, b1 = 0;
	double stan = 0;

	scanf("%d", &test);

	for (int i = 0; i < test; i++) {
		scanf(" %lf %lf", &a, &b);
		stan = b - a;
		pres = 1;
		if (stan == 1) {
			printf("1\n");
			continue;
		}
		for (int j = 1;; j++) {
			a1 = (double)j*j;
			b1 = (double)(j+1)*(j+1);
			if (stan > a1 && stan < b1) {
				stan=stan- a1;
				for (int k = 1;; k++) {
					stan=stan - j;
					pres++;
					if (stan <= 0) {
						break;
					}
				}
				printf("%d\n", pres);
				break;
			}
			if (stan == a1) {
				printf("%d\n", pres + 2);
				break;
			}
			if (stan == b1) {
				printf("%d\n", pres+2);
				break;
			}
			pres += 2;

		}
	}


	return 0;
}
