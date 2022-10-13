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
	int a = 0, b = 0;
	int ans = 0;
	int wick = 0;
	int num = 0;
	scanf(" %d %d", &a, &b);
	int* first = (int*)malloc((b - a+1) * sizeof(int));
	for (int i = 0; i < b - a+1; i++) {
		first[i] = 0;
	}
	for (int i = a; i <= b; i++) {
		if (i == 1) {
            num++;
			continue;
		}
		else if (i == 2) {
			ans += 2;
			first[0] = 2;
            num++;
			continue;
		}
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				wick = -1;
				break;
			}
		}
		if (wick == -1) {
			wick = 0;
			num++;
			continue;
		}
		else if (wick == 0) {
			first[num] = i;
			ans += i;
			num++;
		}
	}
	if (ans == 0) {
		printf("-1");
	}
	else if (ans != 0) {
		printf("%d\n", ans);
		for (int i = 0; i < b-a+1; i++) {
			if (first[i] != 0) {
				printf("%d", first[i]);
				return 0;
			}
		}

	}
	return 0;
}
