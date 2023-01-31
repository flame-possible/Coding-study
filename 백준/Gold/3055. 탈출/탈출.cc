#include <bits/stdc++.h>

using namespace std;

char input[51][51];

struct Pos{

        int y, x;

};

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int result;

int bfs_water[10000][3];
int bfs_water_cnt;
int bfs_water_start;
int visit_water[51][51];

int bfs_beaver[10000][3];
int bfs_beaver_cnt;
int bfs_beaver_start;
int visit_beaver[51][51];

Pos start, end_, water;

int R, C;

int dao;

void BFS(int time){

        if(time > 3000) return;

        if(dao) return;

        while(bfs_water_cnt != bfs_water_start){

                int cur_y = bfs_water[bfs_water_start][0];
                int cur_x = bfs_water[bfs_water_start][1];
                int cur_time = bfs_water[bfs_water_start++][2];

//              cout << "water\n";
//              cout << cur_y << ' ' << cur_x << ' ' << cur_time << '\n';

                if(cur_time != time){
                        bfs_water_start--;
                        break;
                }

                for(register int i = 0; i < 4; i++){

                        int temp_y = cur_y + dy[i];
                        int temp_x = cur_x + dx[i];
                        int temp_time = time;

                        if(temp_y >= 0 && temp_y < R && temp_x >= 0 && temp_x < C && input[temp_y][temp_x] == '.'){

                                if(!visit_water[temp_y][temp_x]){
                                        visit_water[temp_y][temp_x] = 1;

                                        bfs_water[bfs_water_cnt][0] = temp_y;
                                        bfs_water[bfs_water_cnt][1] = temp_x;
                                        bfs_water[bfs_water_cnt++][2] = time + 1;
                                }

                        }

                }

        }

        while(bfs_beaver_cnt != bfs_beaver_start){

                int cur_y = bfs_beaver[bfs_beaver_start][0];
                int cur_x = bfs_beaver[bfs_beaver_start][1];
                int cur_time = bfs_beaver[bfs_beaver_start++][2];

//              cout << "beaver \n";
//              cout << cur_y << ' ' << cur_x << ' ' << cur_time << '\n';

                if(cur_time != time){
                        bfs_beaver_start--;
                        break;
                }

                for(register int i = 0; i < 4; i++){

                        int temp_y = cur_y + dy[i];
                        int temp_x = cur_x + dx[i];
                        int temp_time = time;

                        if(temp_y >= 0 && temp_y < R && temp_x >= 0 && temp_x < C && (input[temp_y][temp_x] == '.' || input[temp_y][temp_x] == 'D')){

                                if(temp_y == end_.y && temp_x == end_.x){
                                        dao = 1;
                                        result = time + 1;
                                        break;
                                }

                                if(!visit_beaver[temp_y][temp_x] && !visit_water[temp_y][temp_x]){
                                        visit_beaver[temp_y][temp_x] = 1;

                                        bfs_beaver[bfs_beaver_cnt][0] = temp_y;
                                        bfs_beaver[bfs_beaver_cnt][1] = temp_x;
                                        bfs_beaver[bfs_beaver_cnt++][2] = time + 1;
                                }

                        }

                }

                if(dao) break;

        }

        BFS(time + 1);

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> R >> C;

        for(register int i = 0; i < R; i++){

                for(register int j = 0; j < C; j++){
                        cin >> input[i][j];

                        if(input[i][j] == 'S'){
                                start.y = i;
                                start.x = j;
                        }

                        else if(input[i][j] == 'D'){
                                end_.y = i;
                                end_.x = j;
                        }

                        else if(input[i][j] == '*'){
                                water.y = i;
                                water.x = j;

                                bfs_water[bfs_water_cnt][0] = water.y;
                                bfs_water[bfs_water_cnt][1] = water.x;
                                bfs_water[bfs_water_cnt++][2] = 0;
                        }

                }

        }

//      cout << end_.y << ' ' << end_.x << '\n';

        bfs_beaver[bfs_beaver_cnt][0] = start.y;
        bfs_beaver[bfs_beaver_cnt][1] = start.x;
        bfs_beaver[bfs_beaver_cnt++][2] = 0;

        BFS(0);

        if(result)
                cout << result << '\n';
        else
                cout << "KAKTUS\n";

        return 0;

}
