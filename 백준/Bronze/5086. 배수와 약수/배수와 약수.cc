#include <iostream>

using namespace std;

int main(){

	while(1){

		int input1, input2;

		cin >> input1 >> input2;

		if(input1 == 0 && input2 == 0){
			break;
		}
		
		if(input1 < input2 && (input2 / input1) > 0 && (input2 % input1) == 0){
			cout << "factor\n";
			continue;
		}
		
		if(input1 > input2 && (input1 / input2) > 0 && (input1 % input2) == 0){
			cout << "multiple\n";
			continue;
		}
		cout << "neither\n";
		continue;

	}

	return 0;

}