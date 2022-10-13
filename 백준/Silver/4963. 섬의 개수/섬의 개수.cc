#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int input[51][51];
int check[51][51];
int result;
int x, y;

void DFS(int y_, int x_){

	for(register int i = -1; i < 2; i++){
		for(register int j = -1; j < 2; j++){
			if((y_ + i >= 0 && y_ + i <= y) && (x_ + j >= 0 && x_ + j <= x)){
				
				if(check[y_ + i][x_ + j]) continue;
				if(i == 0 && j == 0) continue;

				if(input[y_ + i][x_ + j] == 1){ 
					check[y_ + i][x_ + j] = 1;
					DFS(y_ + i, x_ + j);
				}
			}
		}
	}

	return;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	while(1){

		memset(input, 0, sizeof(input));
		memset(check, 0, sizeof(input));

		result = 0;

		cin >> x >> y;

		if(x == 0 && y == 0){
			return 0;
		}

		for(register int i = 0; i < y; i++){
			for(register int j = 0; j < x; j++){
				cin >> input[i][j];
			}
		}

		for(register int i = 0; i < y; i++){
			for(register int j = 0; j < x; j++){
				if(check[i][j] == 0 && input[i][j] & 1){
					result++;
					DFS(i, j);
				}
			}
		}
		
		cout << result << '\n';

	}


	return 0;

}