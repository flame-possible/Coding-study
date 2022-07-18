#include <bits/stdc++.h>
#define INF 0x7FFFFFFF

using namespace std;

vector< pair < int, int>  > input[801];
long long int dis[3][801];

void dijkstra(int order, int start){

        priority_queue< pair < int, int> > pq;

        pq.push(make_pair(0, start));

        dis[order][start] = 0;

        int cur = start;

        while(!pq.empty()){

                cur = pq.top().second;
                pq.pop();

                for(register int i = 0; i < input[cur].size(); i++){
                        int next = input[cur][i].first;
                        int cur_value = input[cur][i].second + dis[order][cur];
                        int sum_value = dis[order][next];
                        if(cur_value < sum_value){
                                dis[order][next] = cur_value;
                                pq.push(make_pair(-1 * cur_value, next));
                        }
                }

        }

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, E;

        int c;

        int u, v;

        cin >> N >> E;

        for(register int i = 0; i < E; i++){
                int temp_1, temp_2, temp_3;

                cin >> temp_1 >> temp_2 >> temp_3;

                int pan = 1;

                for(register int j = 0; j < input[temp_1].size(); j++){
                        if(input[temp_1][j].first == temp_2){
                                pan = 0;
                                if(input[temp_1][j].second > temp_3){
                                        input[temp_1][j].second = temp_3;
                                }
                        }

                }

                for(register int j = 0; j < input[temp_2].size(); j++){
                        if(input[temp_2][j].first == temp_1){
                                pan = 0;
                                if(input[temp_2][j].second > temp_3){
                                        input[temp_2][j].second = temp_3;
                                }
                        }

                }


                if(pan & 1){
                        input[temp_1].push_back(make_pair(temp_2, temp_3));
                        input[temp_2].push_back(make_pair(temp_1, temp_3));
                }

        }

        cin >> u >> v;

        for(register int i = 1; i < 3; i++){
                for(register int j = 0; j < 801; j++){
                        dis[i][j] = INF;
                }
        }

        dijkstra(1, u);
        dijkstra(2, v);

        long long int result_1 = 0;
        long long int result_2 = 0;
/*
        for(register int i = 1; i < 3; i++){
                for(register int j = 0; j <= N; j++){
                        cout << dis[i][j] << ' ';
                }
                cout << '\n';
        }
        cout << '\n';
*/
        result_1 += dis[1][1] + dis[1][v] + dis[2][N];

        result_2 += dis[2][1] + dis[2][u] + dis[1][N];

//      cout << result_1 << ' ' << result_2 << '\n';

        if(E == 0){
                cout << "-1\n";
                return 0;
        }

        if(result_1 < result_2){
                if(result_1 > INF){
                        cout << "-1\n";
                }
                else{
                        cout << result_1 << '\n';
                }
        }
        else{
                if(result_2 > INF){
                        cout << "-1\n";
                }
                else{
                        cout << result_2 << '\n';
                }
        }

        return 0;

}
