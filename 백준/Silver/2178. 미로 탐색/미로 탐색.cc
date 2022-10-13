#include <bits/stdc++.h>

using namespace std;

int input[110][110];

int check[110][110];

int dis[110][110];

int bfs_list[10000][2];
int bfs_cnt;
int bfs_start;

int N, M;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> N >> M;

        string temp;

        for(register int i = 1; i <= N; i++){

                cin >> temp;

                for(register int j = 1; j <= M; j++){

                        input[i][j] = temp[j-1] - '0';
                }

        }

        bfs_list[bfs_cnt][0] = 1;
        bfs_list[bfs_cnt++][1] = 1;

        dis[1][1] = 1;

        check[1][1] = 1;


        while(bfs_start < bfs_cnt){

                int cur_y = bfs_list[bfs_start][0];
                int cur_x = bfs_list[bfs_start++][1];


                //cout << cur_y << ' ' << cur_x << ' ' << dis[cur_y][cur_x] << '\n';
                //cout << bfs_start << ' ' << bfs_cnt << '\n';

                if(input[cur_y-1][cur_x] & 1 && !check[cur_y-1][cur_x]){
                        bfs_list[bfs_cnt][0] = cur_y-1;
                        bfs_list[bfs_cnt++][1] = cur_x;
                        check[cur_y-1][cur_x] = 1;

                        dis[cur_y-1][cur_x] = dis[cur_y][cur_x] + 1;
                }

                if(input[cur_y][cur_x+1] & 1 && !check[cur_y][cur_x+1]){
                        bfs_list[bfs_cnt][0] = cur_y;
                        bfs_list[bfs_cnt++][1] = cur_x+1;
                        check[cur_y][cur_x+1] = 1;

                        dis[cur_y][cur_x+1] = dis[cur_y][cur_x] + 1;

                }

                if(input[cur_y+1][cur_x] & 1 && !check[cur_y+1][cur_x]){
                        bfs_list[bfs_cnt][0] = cur_y+1;
                        bfs_list[bfs_cnt++][1] = cur_x;
                        check[cur_y+1][cur_x] = 1;

                        dis[cur_y+1][cur_x] = dis[cur_y][cur_x] + 1;

                }

                if(input[cur_y][cur_x-1] & 1 && !check[cur_y][cur_x-1]){
                        bfs_list[bfs_cnt][0] = cur_y;
                        bfs_list[bfs_cnt++][1] = cur_x-1;
                        check[cur_y][cur_x-1] = 1;

                        dis[cur_y][cur_x-1] = dis[cur_y][cur_x] + 1;

                }

                if(cur_y == N && cur_x == M){
                        cout << dis[cur_y][cur_x] << '\n';
                        break;
                }


        }

//      cout << dis[N][M] << '\n';

        return 0;

}
