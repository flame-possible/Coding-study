#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

	int T;
	cin >> T;

	for(register int i = 0; i < T; i++){

		int a, b;
		cin >> a >> b;

		int result = 1;

		for(register int j = 0; j < b; j++){
		
			result *= a;
			result %= 10;
			if(result == 0) break;

		}

		if(result == 0){
			cout << "10\n";
			continue;
		}
		else{
			cout << result << '\n';
		}

	}

	return 0;

}