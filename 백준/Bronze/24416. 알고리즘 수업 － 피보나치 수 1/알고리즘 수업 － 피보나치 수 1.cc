#include <bits/stdc++.h>

using namespace std;

int result_1, result_2;

int f[100];
int check[2][100];

int fib(int n){

	if(n == 1 || n == 2){
		result_1++;
		return 1;
	}
	else{
		return (fib(n - 1) + fib(n - 2));
	}

}

int fibonacci(int n){


	if(n == 1 || n == 2){
		return f[n];
	}
	else{
		if(f[n] == 0){
			result_2++;
			return f[n] = fibonacci(n - 1) + fibonacci(n - 2);
		}
		else{
			return f[n];
		}
	}
	

}

int main(){

	int n;

	cin >> n;

	f[1] = 1;
	f[2] = 1;

	fib(n);
	fibonacci(n);

	cout << result_1 << ' ' << result_2 << '\n';
	

	return 0;

}