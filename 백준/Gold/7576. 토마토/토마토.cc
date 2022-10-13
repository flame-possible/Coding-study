#include <bits/stdc++.h>

using namespace std;

int bfs_list[1000000][2];
int input[1100][1100];
int check[1100][1100];


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);

        int M, N;

        cin >> M >> N;

        int bfs_start = 0;
        int bfs_cnt = 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= M; j++){
                        cin >> input[i][j];
                        if(input[i][j] == 1){
                                check[i][j] = 1;

                                bfs_list[bfs_cnt][0] = i;
                                bfs_list[bfs_cnt++][1] = j;
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

                        for(register int j = 0; j < 4; j++){
                                if(cur_y + dy[j] > 0 && cur_y + dy[j] <= N && cur_x + dx[j] > 0 && cur_x + dx[j] <= M){
                                        //cout << cur_y + dy[j] << ' ' << cur_x + dx[j] << '\n';
                                        if(input[cur_y + dy[j]][cur_x + dx[j]] == 0 && !(check[cur_y + dy[j]][cur_x + dx[j]] & 1)){
                                                check[cur_y + dy[j]][cur_x + dx[j]] = 1;
                                                input[cur_y + dy[j]][cur_x + dx[j]] = 1;

                                                bfs_list[bfs_cnt][0] = cur_y + dy[j];
                                                bfs_list[bfs_cnt++][1] = cur_x + dx[j];
                                                pan = 1;
                                        }
                                }
                        }



                }

                if(pan & 1){
                        result++;
                }

        }

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= M; j++){
                        //cout << input[i][j] << ' ';
                        if(input[i][j] == 0){
                                cout << "-1\n";
                                return 0;
                        }
                }
                //cout << '\n';
        }

        cout << result << '\n';

        return 0;

}
