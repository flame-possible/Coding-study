#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	int input[1000] = {0,};
	int a, b, c;
	int i = 1;
	for (; ; i++) {
		scanf(" %d %d %d", &a, &b, &c);
		int temp = 0;
		if (a == 0 || b == 0 || c == 0) {
			break;
		}
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}
		if (a < c) {
			temp = a;
			a = c;
			c = temp;
		}
		if (b < c) {
			temp = b;
			b = c;
			c = temp;
		}
		if (a * a == (b * b) + (c * c)) {
			input[i] = 1;
		}
	}

	for (int j = 1; j < i; j++) {
		if (input[j] == 1) {
			printf("right");
		}
		else {
			printf("wrong");
		}
		printf("\n");
	}


	return 0;
}