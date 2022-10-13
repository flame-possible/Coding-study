#include <iostream>
#include <string>

using namespace std;

int main(){

	int input[1000001] = {0,};

	int temp_input[1000001] = {0,};
	
	int N;

	cin >> N;

	cin >> input[0];
	
	temp_input[0] = input[0];

	int temp_cnt = 0;

	for(register int i = 1; i < N; i++){

		cin >> input[i];

		if(temp_input[temp_cnt] < input[i]){
			temp_cnt++;
			temp_input[temp_cnt] = input[i];
		}
		else{

			int left = 0;
			int right = temp_cnt;
			
			while(left <= right){
				int mid = (left + right) >> 1;

				if(temp_input[mid] >= input[i]){
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}
			temp_input[left] = input[i];

		}

	}

	cout << temp_cnt+1 << '\n';

	return 0;

}