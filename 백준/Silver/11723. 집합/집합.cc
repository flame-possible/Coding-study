#include <iostream>
#include <string>


using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	int S[21] = {0,};
	for(register int i = 0; i < N; i++){

		string input;
		cin >> input;
		if(input == "all"){
                        for(register int j = 1; j < 21; j++){
                                S[j] = 1;
                        }
			continue;
                }
                else if(input == "empty"){
                        for(register int j = 1; j < 21; j++){
                                S[j] = 0;
                        }
			continue;
                }
		int temp;
		switch(input[0]){
	
			case 'a':
                        	cin >> temp;
                        	if(!(S[temp] & 1)){
                        	        S[temp] = 1;
                        	}
				break;
			case 'r':
                        	cin >> temp;
                        	if(S[temp] & 1){
                        	        S[temp] = 0;
                        	}
				break;
			case 'c':
                        	cin >> temp;
                        	if(S[temp] & 1){
                        	        cout << "1\n";
                        	}
                        	else{
                        	        cout << "0\n";
                        	}
				break;
			case 't':
                        	cin >> temp;
                        	if(S[temp] & 1){
                        	        S[temp] = 0;
                        	}
                        	else{
                        	        S[temp] = 1;
                        	}

		}


	}

	return 0;

}