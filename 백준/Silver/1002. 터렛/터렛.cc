#include <stdio.h>

int pow(int x, int n) {
	int res = 1;
	for (int i = 0; i < n; i++)
		res *= x;
	return res;
}

int main() {
	int size = 0;
	int x1, y1, r1, x2, y2, r2;
	int d;

	scanf("%d", &size);	// Test Case 개수 입력
	
	for (int i = 0; i < size; i++) {

		// i번째 Test Case의 정보 입력
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

		// 두 원의 중심좌표간의 거리 의 제곱
		d = pow(x1-x2, 2) + pow(y1-y2, 2);

		// 두 원이 일치하는 경우
		if (r1 == r2 && d == 0)
			printf("-1\n");

		// 두 원이 두 점에서 만나는 경우
		else if (pow(r1 - r2, 2) < d && d < pow(r1 + r2, 2))
			printf("2\n");
		
		// 두 원이 한 점에서 만나는 경우
		else if (pow(r1 - r2, 2) == d || d == pow(r1 + r2, 2))
			printf("1\n");

		// 두 원이 만나지 않는 경우
		else 
			printf("0\n");
	}
}