#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int n, answer = -2147000000;
char str[20] = {0,};

int calculate(int a, int b, char op) {
	switch(op) {
		case '+':
			a += b; 
			break;
		case '-':
			a -= b;
			break;
		case '*':
			a *= b;
			break;
	}
	
	return a;
}

void DFS(int idx, int cur) {
	if(idx >= n) {
		answer = max(answer, cur);
		return;
	}
	
	char op = idx == 0 ? '+' : str[idx - 1];
	
	if(idx + 2 < n) {
		int bracket = calculate(str[idx] - '0', str[idx + 2] - '0', str[idx + 1]);
		DFS(idx + 4, calculate(cur, bracket, op));
	}
	
	DFS(idx + 2, calculate(cur, str[idx] - '0', op));
}


int main(void)
{
        cin.tie(NULL);
        ios::sync_with_stdio(false);
        int count = 0;

        cin >> n >> str;

	DFS(0,0);

        cout << answer << '\n';

        return 0;
}
