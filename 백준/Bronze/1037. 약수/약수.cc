#include <iostream>

using namespace std;

int main(){

	int N;
	
	cin >> N;

	int min = 1000000;
	int max = 0;

	for(register int i = 0; i < N; i++){

		int temp;
		cin >> temp;
		if(temp < min){
			min = temp;
		}
		if(temp > max){
			max = temp;
		}

	}

	cout << min * max << '\n';

	return 0;

}
