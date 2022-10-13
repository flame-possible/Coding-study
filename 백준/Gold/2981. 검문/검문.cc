#include <iostream>

using namespace std;

int func(int a, int b){

	if(a < b){
		int temp = b;
		b = a;
		a = temp;
	}
	int temp;

	while(b){

		temp = a % b;
		a = b;
		b = temp;

	}
	return a;
}

int main(){

	int input[100] = {0,};

	int N;
	
	cin >> N;

	for(register int i = 0; i < N; i++){

		cin >> input[i];

	}

	int gcd = input[1] - input[0];
	if(gcd < 0) gcd = ~gcd + 1;

	for(register int i = 2; i < N; i++){
		int temp = input[i] - input[i-1];
		if(temp < 0) temp = ~temp + 1;
		gcd = func(gcd, temp);
	}

	for(register int i = 2; i <= gcd/2; i++){
		if(gcd % i == 0){
			cout << i << ' ';
		}
	}
	cout << gcd << '\n';
	

	return 0;

}