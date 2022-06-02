#include <bits/stdc++.h>

using namespace std;

int input[1001][1001];

int check[1001][1001][2];

int bfs_list[5000001][3];
int bfs_start;
int bfs_end;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	int N, M;
	string in;

	int dx[4] = {-1, 1, 0, 0};
	int dy[4] = {0, 0, -1, 1};

	cin >> N >> M;

	for(register int i = 1; i <= N; i++){

		cin >> in;

		for(register int j = 1; j <= M; j++){
			input[i][j] = in[j-1] - '0';
			in[j-1] = 0;
		}

	}

	bfs_list[bfs_end][0] = 1;
	bfs_list[bfs_end][1] = 1;
	bfs_list[bfs_end++][2] = 0;

	check[1][1][0] = 1;

	int result = 0;

	while(1){

//		cout << bfs_start << ' ' << bfs_end << '\n';

		if(bfs_start == bfs_end){
			cout << "-1\n";
			return 0;
		}

		int temp_bfs_start = bfs_start;
		int temp_bfs_end = bfs_end;

		

		int pan = 0;

		for(register int i = temp_bfs_start; i < temp_bfs_end; i++){

			int cur_y = bfs_list[bfs_start][0];
			int cur_x = bfs_list[bfs_start][1];
			int cur_one = bfs_list[bfs_start++][2];

//			cout << cur_y << ' ' << cur_x << '\n';

			if(cur_y == N && cur_x == M){
				pan = 1;
				break;
			}

			for(register int j = 0; j < 4; j++){


				if(cur_y + dy[j] < 1 || cur_y + dy[j] > N || cur_x + dx[j] < 1 || cur_x + dx[j] > M){
					continue;
				}

				if(check[cur_y + dy[j]][cur_x + dx[j]][cur_one] & 1) continue;
				
				//cout << "inner " << cur_y + dy[j] << ' ' << cur_x + dx[j] << '\n';

				if(cur_one & 1){
					if(input[cur_y + dy[j]][cur_x + dx[j]] & 1) continue;
					else{
						bfs_list[bfs_end][0] = cur_y + dy[j];
	                                        bfs_list[bfs_end][1] = cur_x + dx[j];
        	                                bfs_list[bfs_end++][2] = 1;

                	                        check[cur_y + dy[j]][cur_x + dx[j]][1] = 1;
					}
				}

				else{
					if(input[cur_y + dy[j]][cur_x + dx[j]] & 1){
						bfs_list[bfs_end][0] = cur_y + dy[j];
						bfs_list[bfs_end][1] = cur_x + dx[j];
						bfs_list[bfs_end++][2] = 1;
					
						check[cur_y + dy[j]][cur_x + dx[j]][1] = 1;
					}
					else{
						bfs_list[bfs_end][0] = cur_y + dy[j];
                                                bfs_list[bfs_end][1] = cur_x + dx[j];
                                                bfs_list[bfs_end++][2] = 0;

                                                check[cur_y + dy[j]][cur_x + dx[j]][0] = 1;
					}
				}

			}

		}
		result++;

		if(pan & 1) break;

	}

	cout << result << '\n';

	return 0;

}
