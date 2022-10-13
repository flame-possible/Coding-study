#include <iostream>
#define SETTING ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main(){

    SETTING;
    
	int N, K;

	cin >> N >> K;

	int input[100001] = {0,};

	int max = -100000000;

	int temp = 0;

	for(register int i = 1; i <= N; i++){

		cin >> input[i];

		temp += input[i];

		if(i > K){
			temp -= input[i - K];
			if(max < temp){
				max = temp;
			}
		}
		else if (i == K){
			if(max < temp){
				max = temp;
			}
		}

	}

	cout << max << '\n';

	return 0;

}