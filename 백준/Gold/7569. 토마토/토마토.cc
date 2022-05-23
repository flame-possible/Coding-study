#include <bits/stdc++.h>

using namespace std;

int bfs_list[1000000][3];
int input[110][110][110];
int check[110][110][110];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int M, N, H;

	cin >> M >> N >> H;

	int bfs_start = 0;
	int bfs_cnt = 0;

	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};
	int dz[2] = {-1, 1};

	for(register int i = 1; i <= H; i++){
		for(register int j = 1; j <= N; j++){
			for(register int k = 1; k <= M; k++){
				cin >> input[j][k][i];
				if(input[j][k][i] == 1){
					check[j][k][i] = 1;
	
					bfs_list[bfs_cnt][0] = j;
					bfs_list[bfs_cnt][1] = k;
					bfs_list[bfs_cnt++][2] = i;
				}
			}
		}
	}

	int result = 0;

	if(bfs_cnt == 0){
		cout << "-1\n";
		return 0;
	}

	while(bfs_start < bfs_cnt){

		//cout << bfs_start << ' ' << bfs_cnt << '\n';

		int temp_start = bfs_start;
		int temp_end = bfs_cnt;

		bfs_start = temp_end;

		int pan = 0;

		for(register int i = temp_start; i < temp_end; i++){
			
			int cur_y = bfs_list[i][0];
			int cur_x = bfs_list[i][1];
			int cur_z = bfs_list[i][2];
			
//			cout << cur_y << ' ' << cur_x << ' ' << cur_z << '\n';

			for(register int j = 0; j < 4; j++){
				if(cur_y + dy[j] > 0 && cur_y + dy[j] <= N && cur_x + dx[j] > 0 && cur_x + dx[j] <= M){
					//cout << cur_y + dy[j] << ' ' << cur_x + dx[j] << '\n';
					if(input[cur_y + dy[j]][cur_x + dx[j]][cur_z] == 0 && !(check[cur_y + dy[j]][cur_x + dx[j]][cur_z] & 1)){
						check[cur_y + dy[j]][cur_x + dx[j]][cur_z] = 1;
						input[cur_y + dy[j]][cur_x + dx[j]][cur_z] = 1;
	
						bfs_list[bfs_cnt][0] = cur_y + dy[j];
						bfs_list[bfs_cnt][1] = cur_x + dx[j];
						bfs_list[bfs_cnt++][2] = cur_z;
						pan = 1;
					}
				}
			}

			for(register int j = 0; j < 2; j++){
				if(cur_z + dz[j] > 0 && cur_z + dz[j] <= H){
					if(input[cur_y][cur_x][cur_z + dz[j]] == 0 && !(check[cur_y][cur_x][cur_z + dz[j]] & 1)){
						check[cur_y][cur_x][cur_z + dz[j]] = 1;
						input[cur_y][cur_x][cur_z + dz[j]] = 1;

						bfs_list[bfs_cnt][0] = cur_y;
						bfs_list[bfs_cnt][1] = cur_x;
						bfs_list[bfs_cnt++][2] = cur_z + dz[j];
						pan = 1;
					}
				}
			}

			

		}

		if(pan & 1){
			result++;
		}

	}

	for(register int i = 1; i <= H; i++){
		for(register int j = 1; j <= N; j++){
			for(register int k = 1; k <= M; k++){
				//cout << input[i][j] << ' ';
				if(input[j][k][i] == 0){
					cout << "-1\n";
					return 0;
				}
			}
		}
		//cout << '\n';
	}

	cout << result << '\n';

	return 0;

}