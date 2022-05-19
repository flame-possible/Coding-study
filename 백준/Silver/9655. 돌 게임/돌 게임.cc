#include <iostream>

using namespace std;

int main(){

	int N;

	cin >> N;


	int divide = N / 3;
	int remain = N % 3;

	int present = 0;

	if(divide & 1){
		present = 0;
	}
	else{
		present = 1;
	}

	if(remain == 1){
		if(present & 1){
			present = 0;
		}
		else{
			present = 1;
		}
	}

	if(present & 1){
		cout << "CY\n";
	}
	else{
		cout << "SK\n";
	}

	return 0;

}
