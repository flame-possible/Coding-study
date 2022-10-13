#include <bits/stdc++.h>

using namespace std;

int main(){

	int N;

	double W, H;

	cin >> N >> W >> H;

	double com = 0;

	com = (W * W) + (H * H);
	com = sqrt(com);

	int temp;

	for(register int i = 0; i < N; i++){
		cin >> temp;
		if(temp <= com){
			cout << "DA\n";
		}
		else{
			cout << "NE\n";
		}
	}

	return 0;

}