#include <bits/stdc++.h>

using namespace std;

vector<int> v[100001];

int check[100001];
int bfs_list[500001];
int bfs_cnt;
int result[1000001];

int N, M, n;

void BFS(int R){

        if(check[R] & 1){
                n--;
                return;
        }

        check[R] = 1;
        result[R] = n;

        for(register int i = 0; i < v[R].size(); i++){
                if(!(check[v[R][i]] & 1)){
                        bfs_list[bfs_cnt++] = v[R][i];
                }
        }

        return;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int R;

        cin >> N >> M >> R;

        register int temp_a, temp_b;

        for(register int i = 0; i < M; i++){

                cin >> temp_a >> temp_b;

                v[temp_a].push_back(temp_b);
                v[temp_b].push_back(temp_a);

        }

        for(register int i = 1; i <= N; i++){
                sort(v[i].begin(), v[i].end(), greater<int>());
        }

        n = 1;

        BFS(R);

        for(register int i = 0; i < bfs_cnt; i++){
                n++;
                //cout << bfs_list[i] << ' ' << n << '\n';
                BFS(bfs_list[i]);
        }

        for(register int i = 1; i <= N; i++){
                cout << result[i] << '\n';
        }

        return 0;

}
