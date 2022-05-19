#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int N, M, K;
int input[60][60] = {0,};
int input_temp[60][60] = {0,};
int counting = 6000;
int result = 6000;
bool visit[10];

int order[10][10] = {0,};
int copy_order[10][10] = {0,};

void dfs(int temp_order);

void dfs(int temp_order){
	if(temp_order == K+1){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				input_temp[i][j] = input[i][j];
			}
		}

		for(int i = 1; i <= K; i++){
			int jung = (copy_order[i][1] + copy_order[i][3]) - (copy_order[i][1] - copy_order[i][3]) + 1;
			int start_y = copy_order[i][1] - copy_order[i][3];
			int start_x = copy_order[i][2] - copy_order[i][3];
			int daum_jung = 1;
			int move_val = 0;
			for(int j = jung; j > 1; j -= 2){
				move_val = input_temp[start_y][start_x];
				for(int o = 1; o <= (j-1) * 4; o++){
					int temp = 0;
					if(o <= j - 1){
						start_x++;
					}
					else if(o > j - 1 && o <= (j-1) * 2){
						start_y++;
					}
					else if(o > (j - 1) * 2 && o <= (j - 1) * 3){
						start_x--;
					}
					else{
						start_y--;
					}
					temp = input_temp[start_y][start_x];
                                        input_temp[start_y][start_x] = move_val;
                                        move_val = temp;
				}
/*				for(int o = 1; o <= N; o++){
					for(int p = 1; p <= M; p++){
						cout << input_temp[o][p] << ' ';
					}
					cout << '\n';
				}
				cout << '\n';*/
				start_y += daum_jung;
				start_x += daum_jung;
			}

		}
		for(int i = 1; i <= N; i++){
			int temp = 0;
			for(int j = 1; j <= M; j++){
				temp += input_temp[i][j];
			}
			if(counting > temp){
				counting = temp;
			}
		}
		if(counting < result){
			result = counting;
		}

		return;
	}

	for(int i = 1; i <= K; i++){
		if(!visit[i]){
			visit[i] = true;
			copy_order[temp_order][1] = order[i][1];
                        copy_order[temp_order][2] = order[i][2];
                        copy_order[temp_order][3] = order[i][3];
			dfs(temp_order+1);
			visit[i] = false;
                        copy_order[temp_order][1] = 0;
                        copy_order[temp_order][2] = 0;
                        copy_order[temp_order][3] = 0;
		}

	}

}

int main(void)
{
        cin.tie(NULL);
        ios::sync_with_stdio(false);
	
	cin >> N >> M >> K;

        for(int i = 1; i <= N; i++){
                for(int j = 1; j <= M; j++){
                        cin >> input[i][j];
                }
        }
	
	for(int i = 1; i <= K; i++){
		cin >> order[i][1] >> order[i][2] >> order[i][3];
	}

	dfs(1);

        cout << result << '\n';
        
	return 0;
}