#include <iostream>

using namespace std;

long long two(long long n) {
	long long ret = 0;
	for (long long i = 2; n / i >= 1; i *= 2) {
		ret += n / i;
	}
	return ret;
}
long long five(long long n) {
	long long ret = 0;
	for (long long i = 5; n / i >= 1; i *= 5) {
		ret += n / i;
	}
	return ret;
}

int main(){

	long long a, b;

	cin >> a >> b;

	long long sum_5 = five(a) - five(a-b) - five(b);

	long long sum_2 = two(a) - two(a-b) - two(b);

	if(sum_2 >= sum_5){
		cout << sum_5 << '\n';
	}
	else{
		cout << sum_2 << '\n';
	}

	

	return 0;

}
