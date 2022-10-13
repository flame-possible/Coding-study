#include <bits/stdc++.h>

using namespace std;

int input[101];

int bfs_list[1000];
int check[101];
int bfs_start;
int bfs_end;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M;

        cin >> N >> M;

        int temp_a, temp_b;

        for(register int i = 0; i < 101; i++){
                input[i] = i;
        }

        for(register int i = 0; i < N; i++){
                cin >> temp_a >> temp_b;

                input[temp_a] = temp_b;

        }

        for(register int i = 0; i < M; i++){

                cin >> temp_a >> temp_b;

                input[temp_a] = temp_b;

        }

        bfs_list[bfs_end++] = 1;
        check[1] = 1;

        int result = 0;

        while(1){

                int temp_start = bfs_start;
                int temp_end = bfs_end;

                int pan = 0;

                //cout << "while " << bfs_list[temp_start] << '\n';

                for(register int j = bfs_start; j < temp_end; j++){

                        int cur = bfs_list[j];
                        bfs_start++;

                        //cout << "bfs" << cur << '\n';

                        for(register int i = 1; i <= 6; i++){

                                cur += i;


                                if(cur > 100) break;

                                if(cur == 100){
                                        pan = 1;
                                        break;
                                }

                                int temp_cur = input[cur];

                                //cout << cur << ' ' << temp_cur << '\n';


                                if(!(check[cur] & 1)){
                                        bfs_list[bfs_end++] = temp_cur;
                                        check[cur] = 1;

                                }

                                cur -= i;

                        }
                }
                result++;
                if(pan & 1) break;

        }

        cout << result << '\n';

}
