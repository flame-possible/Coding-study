#include <iostream>
#include <bits/stdc++.h>
#define INF 0x7FFFFFFF

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int V, E;

        cin >> V >> E;

        int start;

        cin >> start;

        vector< pair <int, int> > input[20001];

        int u, v, w;

        for(register int i = 0; i < E; i++){

                cin >> u >> v >> w;
                input[u].push_back(make_pair(v, w));

        }

        int dis[20001] = {0,};

        for(register int i = 0; i < 20001; i++) dis[i] = INF;

        dis[start] = 0;

        priority_queue< pair <int, int> > pq;
        pq.push(make_pair(0, start));

        int cur = start;

        while(!pq.empty()){

                cur = pq.top().second;
                pq.pop();

                for(register int i = 0;i < input[cur].size(); i++){
                        int next = input[cur][i].first;
                        int cur_value = input[cur][i].second + dis[cur];
                        int sum_value = dis[next];
                        if(cur_value < sum_value){
                                dis[next] = cur_value;
                                pq.push(make_pair(-1*cur_value, next));
                        }
                }

        }

        for(register int i = 1; i <= V; i++){
                if(dis[i] == INF){
                        cout << "INF\n";
                }
                else{
                        cout << dis[i] << '\n';
                }
        }


        return 0;

}
