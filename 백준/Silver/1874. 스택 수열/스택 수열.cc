#include <iostream>

using namespace std;

int stack[100001];
char output[300001];
int nodecnt = 0;

int main(){

ios_base::sync_with_stdio(false);
        cin.tie(0);
	int N;

	cin >> N;

	int key = 0;

	int out_num = 0;

	for(register int i = 0; i < N; i++){

		int input;
		
		cin >> input;
	
		while(key < input){

			key++;
			stack[nodecnt++] = key;
			output[out_num++] = '+';

		}

		if(stack[nodecnt - 1] == input){
			nodecnt--;
			output[out_num++] = '-';
		}
		else{
			out_num = -1;
			break;
		}

	}

	if(out_num == -1){
		cout << "NO\n";
		return 0;
	}

	for(register int i = 0; i < out_num; i++){

		cout << output[i] << '\n';

	}


	return 0;

}