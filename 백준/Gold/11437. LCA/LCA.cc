#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> input[50001];
int dep[50001];
int parent[18][50001];

void BFS(){

        dep[1] = 0;
        parent[0][1] = 1;

        queue<int> q;
        q.push(1);

        int cur;

        while(!q.empty()){

                cur = q.front();
                q.pop();

                int len = input[cur].size();
                for(register int i = 0; i < len; i++){
                        int next = input[cur][i];

                        if(dep[next] == -1){
                                parent[0][next] = cur;
                                dep[next] = dep[cur] + 1;
                                q.push(next);
                        }
                }

        }

}

int LCA(int a, int b){

        if(dep[a] < dep[b]){
                for(register int k = 17; k >= 0; k--){
                        if(a != b && dep[parent[k][b]] >= dep[a]){
                                b = parent[k][b];
                        }
                }
        }

        else if(dep[a] > dep[b]){
                for(register int k = 17; k >= 0; k--){
                        if(a != b && dep[parent[k][a]] >= dep[b]){
                                a = parent[k][a];
                        }
                }
        }

        for(register int k = 17; k >= 0; k--){
                if(a != b && parent[k][a] != parent[k][b]){
                        a = parent[k][a];
                        b = parent[k][b];
                }
        }

        return (a == b) ? a : parent[0][a];

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> N;

        int temp_1, temp_2;

        for(register int i = 0; i < N - 1; i++){
                cin >> temp_1 >> temp_2;

                input[temp_1].push_back(temp_2);
                input[temp_2].push_back(temp_1);
        }

        for(register int i = 0; i <= N; i++){
                dep[i] = -1;
        }

        BFS();

        for(register int k = 1; k < 18; k++){
                for(register int i = 1; i <= N; i++){
                        parent[k][i] = parent[k-1][parent[k - 1][i]];
                }
        }

        cin >> M;

        for(register int i = 0; i < M; i++){
                cin >> temp_1 >> temp_2;

                cout << LCA(temp_1, temp_2) << '\n';
        }

        return 0;
}
