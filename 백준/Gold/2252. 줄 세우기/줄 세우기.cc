#include <bits/stdc++.h>

using namespace std;

int person[32001];

vector<int> input[32001];
int N, M;

void topological(){

        queue<int> q;

        for(register int i = 1; i <= N; i++){

                if(!person[i]) q.push(i);

        }

        for(register int i = 0; i < N; i++){

                if(q.empty()) return;

                int result = q.front();
                q.pop();

                cout << result << ' ';

                for(register int j = 0; j < input[result].size(); j++){
                        int com = input[result][j];
                        person[com]--;

                        if(!person[com]){
                                q.push(com);
                        }

                }

        }

        return;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> N >> M;

        int temp_1, temp_2;

        for(register int i = 0; i < M; i++){
                cin >> temp_1 >> temp_2;

                person[temp_2]++;

                input[temp_1].push_back(temp_2);
        }

        topological();

        return 0;

}
