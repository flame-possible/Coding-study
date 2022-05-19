#include <iostream>

using namespace std;

int input[101][101];

int check[101];

int result;

int bfs_list[101];
int bfs_cnt = 0;

int N, M;

void BFS(int n){

        for(register int i = 1; i <= N; i++){
                if((input[n][i] & 1) && !(check[i] & 1)){
                        check[i] = 1;
                        result++;
                        bfs_list[bfs_cnt++] = i;

                }
        }

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> N >> M;

        int temp_a, temp_b;

        for(register int i = 0; i < M; i++){

                cin >> temp_a >> temp_b;

                input[temp_a][temp_b] = input[temp_b][temp_a] = 1;

        }

        check[1] = 1;
        bfs_list[bfs_cnt++] = 1;

        for(register int i = 0; i < bfs_cnt; i++){
                BFS(bfs_list[i]);
        }

        cout << result << '\n';

        return 0;

}
