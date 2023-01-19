#include <bits/stdc++.h>

using namespace std;

struct edge{

        int end, val;

        bool operator<(edge a) const{
                return val > a.val;
        }

};

int N, M, S, D;

void dij(vector<edge> input[501], int dis[501], vector<edge> path[501]){

        priority_queue<edge> pq;

        edge temp = {S, 0};
        dis[S] = 0;

        pq.push(temp);

        while(!pq.empty()){

                edge cur = pq.top();
                pq.pop();

                int cur_node = cur.end;

                int len = input[cur_node].size();

                for(register int i = 0; i < len; i++){

                        int tar = input[cur_node][i].end;
                        int tar_val = input[cur_node][i].val;

                        if(tar_val == -1) continue;

                        if(dis[tar] > dis[cur_node] + tar_val){
                                dis[tar] = dis[cur_node] + tar_val;

                                path[tar].clear();

                                edge temp_1 = {tar, dis[tar]};

                                edge temp_path = {cur_node, tar_val};

                                path[tar].push_back(temp_path);

                                pq.push(temp_1);
                        }

                        else if(dis[tar] == dis[cur_node] + tar_val){
                                //edge temp_1 = {tar, tar_val};

                                edge temp_path = {cur_node, tar_val};

                                path[tar].push_back(temp_path);

                                //pq.push(temp_1);

                        }

                }

        }

}

void BFS(vector<edge> input[501], int visited[501], vector<edge> path[501]){

        queue<int> q;
        q.push(D);

        visited[D] = 1;

        while(!q.empty()){

                int cur = q.front();
                visited[cur] = 1;
                q.pop();

                int len = path[cur].size();

                for(register int i = 0; i < len; i++){
                        int tar = path[cur][i].end;

                        if(!visited[tar]){
                                q.push(tar);
                        }

                                for(register int j = 0; j < input[tar].size(); j++){
//                                      cout << cur << ' ' << tar << ' ' << input[tar][j].end << '\n';
                                        if(input[tar][j].end == cur){
                //                              cout << cur << ' ' << tar << ' ' << input[tar][j].end << '\n';
                                                input[tar][j].val = -1;
                                                break;
                                        }
                                }


                }

        }

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        while(1){

                cin >> N >> M;

                if(!N && !M) break;

                vector<edge> input[501];
                vector<edge> path[501];

                cin >> S >> D;

                int temp_1, temp_2, temp_3;

                for(register int i = 0; i < M; i++){
                        cin >> temp_1 >> temp_2 >> temp_3;

                        edge temp = {temp_2, temp_3};

                        input[temp_1].push_back(temp);
                }

                int dis[501];

                for(register int i = 0; i <= N; i++){
                        dis[i] = 1e9;
                }

                dij(input, dis, path);
/*
                cout << "First dij\n";

                for(register int i = 0; i < N; i++){
                        cout << dis[i] << ' ';
                }
                cout << '\n';

                for(register int i = 0; i < N; i++){
                        for(register int j = 0; j < path[i].size(); j++){
                                cout << i << ' ' << path[i][j].end << ' ' << path[i][j].val << ' ';
                        }
                        cout << '\n';
                }
*/
                for(register int i = 0; i <= N; i++){
                        dis[i] = 1e9;
                }

                int visited[501];
                for(register int i = 0; i < N; i++){
                        visited[i] = 0;
                }

                BFS(input, visited, path);

                dij(input, dis, path);
/*
                cout << "Second dij\n";

                for(register int i = 0; i < N; i++){
                        cout << dis[i] << ' ';
                }
                cout << '\n';

                for(register int i = 0; i < N; i++){
                        for(register int j = 0; j < path[i].size(); j++){
                                cout << i << ' ' << path[i][j].end << ' ' << path[i][j].val << ' ';
                        }
                        cout << '\n';
                }

*/
                if(dis[D] == 1e9) cout << "-1\n";
                else cout << dis[D] << '\n';


        }






        return 0;

}
