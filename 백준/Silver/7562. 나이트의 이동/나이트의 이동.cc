#include <bits/stdc++.h>

using namespace std;

int check[301][301];

int bfs_list[100000][2];
int bfs_start;
int bfs_end;

int dy[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dx[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int T;

        cin >> T;

        for(register int test_case = 0; test_case < T; test_case++){

                memset(check, 0, sizeof(check));
/*
                for(register int i = 0; i < 301; i++){
                        for(register int j = 0; j < 301; j++){
                                cout << check[i][j] << ' ';
                        }
                        cout << '\n';
                }
*/
                bfs_start = 0;
                bfs_end = 0;

                int start_y, start_x, end_y, end_x;

                int result = 0;

                int n;

                cin >> n;


                cin >> start_y >> start_x;

                cin >> end_y >> end_x;

                if(start_y == end_y && start_x == end_x){
                        cout << result << '\n';
                        continue;
                }

                bfs_list[bfs_end][0] = start_y;
                bfs_list[bfs_end++][1] = start_x;

                check[start_y][start_x] = 1;


                while(1){

                        int temp_start = bfs_start;
                        int temp_end = bfs_end;

                        int ans = 0;

//                      cout << temp_start << ' ' << temp_end << '\n';

                        for(register int i = temp_start; i < temp_end; i++){
                                int cur_y = bfs_list[i][0];
                                int cur_x = bfs_list[i][1];

//                              cout << cur_y << ' ' << cur_x << '\n';

                                if(cur_y == end_y && cur_x == end_x){
                                        ans = 1;
                                        break;
                                }

                                bfs_start++;

                                for(register int j = 0; j < 8; j++){
                                        int temp_y = cur_y + dy[j];
                                        int temp_x = cur_x + dx[j];
                                        if(temp_y < 0 || temp_y > n - 1 || temp_x < 0 || temp_x > n - 1){
                                                continue;
                                        }

                                        if(!(check[temp_y][temp_x] & 1)){
                                                bfs_list[bfs_end][0] = temp_y;
                                                bfs_list[bfs_end++][1] = temp_x;
                                                check[temp_y][temp_x] = 1;
                                        }
                                }

                        }

                        if(ans & 1) break;
                        result++;

                }

                cout << result << '\n';

        }

        return 0;

}
