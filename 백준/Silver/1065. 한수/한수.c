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
	int input = 0;
	int cal = 0;
	int one = 0, ten = 0, hun = 0, thou = 0, mil = 0;
	scanf("%d", &input);
	for (int i = 1; i <= input; i++) {
		if (i < 100) {
			stan++;
		}
		else if (i < 1000 && i >= 100) {
			hun = i / 100;
			ten = (i % 100) / 10;
			one = i % 10;
			int fir = 0, sen = 0;
			fir = hun - ten;
			sen = ten - one;
			if (fir == sen) {
				stan++;
			}
		}
	}
	printf("%d", stan);

}