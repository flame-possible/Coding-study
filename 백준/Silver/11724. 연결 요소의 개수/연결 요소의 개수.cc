#include <bits/stdc++.h>

using namespace std;

int input[1001][1001];
int visited[1001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M;

        cin >> N >> M;

        for(register int i = 0; i < M; i++){

                int u, v;

                cin >> u >> v;

                input[u][v] = input[v][u] = 1;

        }

        vector<int> v;
        int cur = 0;

        int result = 0;

        for(register int i = 1; i <= N; i++){

                if(visited[i]) continue;

                v.push_back(i);
                visited[i] = 1;

                while(v.size()){
                        cur = v.front();
                        v.erase(v.begin());
                        for(register int i = 1; i <= N; i++){
                                if(input[cur][i] && !visited[i]){
                                        visited[i] = 1;
                                        v.push_back(i);
                                }
                        }
                }
                result++;
        }

        cout << result << '\n';

        return 0;



}
