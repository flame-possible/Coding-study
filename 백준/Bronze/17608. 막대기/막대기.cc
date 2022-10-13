#include <iostream>

using namespace std;


int stack[100001] = {0,};

int stack_cnt = 0;

int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
	int N;

	cin >> N;

	int temp;

	for(register int i = 0; i < N; i++){
		cin >> temp;

		stack[stack_cnt++] = temp;

	}
	
	stack_cnt--;

	int com = stack[stack_cnt--];
	
	int result = 1;

	for(register int i = 1; i < N; i++){
		if(stack[stack_cnt] > com){
			com = stack[stack_cnt];
			result++;
		}
		stack_cnt--;
		
	}
	cout << result << '\n';

	return 0;

}