#include <iostream>
#include <string>

using namespace std;

int main(){

	string input;

	cin >> input;

	for(register int i = 0; i < input.length(); i++){

		int temp = input[i] - '0';

		int temp_out[3] = {0,};
//		cout << temp << '\n';

		if(i == 0){
			if(temp < 4){
				if(temp == 1){
					cout << '1';
				}
				else if(temp == 2){
					cout << "10";
				}
				else if(temp == 3){
					cout << "11";
				}
				else{
					cout << '0';
				}
				continue;
			}
			else{
				for(register int j = 0; j < 3; j++){
					if(temp & 1){
						temp_out[j] = 1;
					}
					else{
						temp_out[j] = 0;
					}
					temp = temp >> 1;
				}
			}
		}
		else{
			for(register int j = 0; j < 3; j++){
                                if(temp & 1){
                                        temp_out[j] = 1;
                                }
                                else{
                                        temp_out[j] = 0;
                                }
				temp = temp >> 1;
                        }
		}

		for(register int j = 2; j >= 0; j--){
			cout << temp_out[j];
		}
//		cout << '\n';
	}
	cout << '\n';
	return 0;

}