#pragma warning(disable: 4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<cursor.h>
//#include<conio.h>

int main()
{

	char str = 0;
	int prin[27] = { 0, };
	int temprin[27] = { 0, };

	for (int i = 0; i < 1000000; i++) {
		str = getchar();
		if (str == '\n') {
			break;
		}
		for (int j = 0; j < 26; j++) {
			if (str == 97 + j || str == 65 + j) {
				prin[j] += 1;
			}
		}
	}
	for (int i = 0; i < 26; i++) {
		temprin[i] = prin[i];
	}
	for (int i = 0; i < 25; i++) {
		for (int j = 0; j < 26; j++) {
			int temp = 0;
			if (prin[j] < prin[j+1]) {
				temp = prin[j+1];
				prin[j+1] = prin[j];
				prin[j] = temp;
			}
		}
	}
	
	if (prin[0] == prin[1]) {
		printf("?");
	}
	else if (prin[0] != prin[1]) {
		int stan = 0;
		for (int i = 0; i < 26; i++) {
			if (prin[0] == temprin[i]) {
				stan = i;
			}
		}
		stan += 65;
		printf("%c", stan);
	}

	return 0;
}
