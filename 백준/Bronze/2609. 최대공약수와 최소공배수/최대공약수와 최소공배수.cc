#include <iostream>

using namespace std;

int main(){

	int input1, input2;

	cin >> input1 >> input2;

	int result1 = 1;
	int result2 = 1;

	for(register int i = 2; i <= (input1 > input2 ? input2 : input1); i++){

		if(input1 < i || input2 < i){
			break;
		}

		if(input1 >= i && input2 >= i && input1 % i == 0 && input2 % i == 0){
			result1 *= i;
			input1 /= i;
			input2 /= i;
			i = 1;
			continue;
		}

	}

	result2 = result1;
	result2 *= input1 * input2;

	cout << result1 << '\n' << result2 << '\n';

	return 0;

}