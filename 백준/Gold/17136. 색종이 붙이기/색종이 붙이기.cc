#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int X = -1;
int Y = -1;
int D;
int input[20][20] = {0,};
int counting = 0;
int result = 30;
int paper_size[6] = {5,};

void check(int y, int x);
void DFS(int a);

void check(int y, int x){

	int pan_num = 0;

	int ceiling = 4;

	if(y == 7 || x == 7){
		ceiling = 3;
	}
	if(y == 8 || x == 8){
		ceiling = 2;
	}
	if(y == 9 || x == 9){
		ceiling = 1;
	}
	if(y == 10 || x == 10){
		ceiling = 0;
	}

	for(int i = ceiling; i >= 0; i--){
		pan_num = i;
		for(int j = 0; j <= i; j++){
			for(int k = 0; k <= i; k++){
				if(input[y + j][x + k] != 1){
					pan_num = -1;
					break;
				}
			}
			if(pan_num == -1){
				break;
			}
		}
		if(counting > result){
                	return;
        	}
		if(pan_num == i && paper_size[i+1] > 0){
			for(int j = 0; j <= i; j++){
				for(int k = 0; k <= i; k++){
					input[y + j][x + k] = 0;
				}
			}
			paper_size[i+1]--;
			counting++;
			DFS(y);
			counting--;
			paper_size[i+1]++;
			for(int j = 0; j <= i; j++){
                                for(int k = 0; k <= i; k++){
                                        input[y + j][x + k] = 1;
                                }
                        }
		}
	}

}

void DFS(int a){

	if(counting > result){
		return;
	}


	for(int i = a; i <= 10; i++){
		for(int j = 1; j <= 10; j++){
			if(input[i][j] == 1){
				check(i, j);
				return;
			}
		}
	}

	for(int i = 1; i <= 10; i++){
		for(int j = 1; j <= 10; j++){
			if(input[i][j] == 1){
				return;
			}
		}
	}

	if(counting < result){
		result = counting;
	}

}

int main(void)
{
        cin.tie(NULL);
        ios::sync_with_stdio(false);
	
	for(int i = 1; i <= 5; i++){
		paper_size[i] = 5;
	}

        for(int i = 1; i <= 10; i++){
                for(int j = 1; j <= 10; j++){
                        cin >> input[i][j];
			if(X == -1 && Y == -1 && input[i][j] == 1){
				X = j;
				Y = i;
			}
                }
        }

	DFS(Y);

	if(result == 30){
		cout << "-1\n";
	}

	else{
        	cout << result << '\n';
	}
        return 0;
}