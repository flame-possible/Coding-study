#include <bits/stdc++.h>

using namespace std;

struct Node{

        int end, val;

};

vector<Node> input[501];

long long dis[501];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M;

        cin >> N >> M;

        int temp_1, temp_2, temp_3;

        for(register int i = 0; i < M; i++){

                cin >> temp_1 >> temp_2 >> temp_3;

                Node temp = {temp_2, temp_3};

                input[temp_1].push_back(temp);

        }

        for(register int i = 0; i <= N; i++){
                dis[i] = 2e9;
        }

        dis[1] = 0;

        for(register int i = 0; i < N - 1; i++){

                for(register int now = 1; now <= N; now++){

                        for(register int k = 0; k < input[now].size(); k++){

                                int next_end = input[now][k].end;
                                int next_val = input[now][k].val;

                                if(dis[now] != 2e9 && dis[next_end] > dis[now] + next_val){
                                        dis[next_end] = dis[now] + next_val;
                                }

                        }

                }

        }

        int cycle = 0;

        for(register int now = 1; now <= N; now++){

                for(register int k = 0; k < input[now].size(); k++){

                        int next_end = input[now][k].end;
                        int next_val = input[now][k].val;

                        if(dis[now] != 2e9 && dis[next_end] > dis[now] + next_val){
                                cycle = 1;
                                break;
                        }

                }

                if(cycle) break;

        }

        if(cycle) cout << "-1\n";

        else{
                for(register int i = 2; i <= N; i++){
                        if(dis[i] == 2e9) cout << "-1\n";
                        else cout << dis[i] << '\n';
                }
        }


        return 0;

}
