#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int N, K;
int input[11] = {0,};

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int count = 0;

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		cin >> input[i];

	for (int i = N; i > 0; i--){
		if(K == 0){
                        break;
                }
		if(K >= input[i]){
			K -= input[i];
			i++;
			count++;
			continue;
		}
	}

	cout << count << '\n';

	return 0;
}
