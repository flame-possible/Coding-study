#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int N;
int answer = -2147000000;
int input[20][20] = {0,};
int counting = 0;

void DFS(int x1, int y1, int x2, int y2) {
	//cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	if(x2 > N || y2 > N){
		return;
	}

	if(x2 == N && y2 == N){
		//cout << counting << '\n';
		counting++;
		return;
	}

	if(x1 == x2 && y1 + 1 == y2){
		if(input[x2][y2+1] == 0){
			DFS(x2, y2, x2, y2+1);
		}
		if(input[x2][y2+1] == 0 && input[x2+1][y2+1] == 0 && input[x2+1][y2] == 0){
			DFS(x2, y2, x2+1, y2+1);
		}
	}
	
	if(x1 + 1 == x2 && y1 == y2){
		
		if(input[x2+1][y2] == 0){
			DFS(x2, y2, x2+1, y2);
		}

		if(input[x2][y2+1] == 0 && input[x2+1][y2+1] == 0 && input[x2+1][y2] == 0){
                        DFS(x2, y2, x2+1, y2+1);
                }

	}

	if(x1 + 1 == x2 && y1 + 1 == y2){
		if(input[x2][y2+1] == 0){
                        DFS(x2, y2, x2, y2+1);
                }
		if(input[x2+1][y2] == 0){
                        DFS(x2, y2, x2+1, y2);
                }
		if(input[x2][y2+1] == 0 && input[x2+1][y2+1] == 0 && input[x2+1][y2] == 0){
                        DFS(x2, y2, x2+1, y2+1);
                }
	}

}


int main(void)
{
        cin.tie(NULL);
        ios::sync_with_stdio(false);

        cin >> N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			cin >> input[i][j];
		}
	}

	DFS(1,1,1,2);

        cout << counting << '\n';

        return 0;
}
