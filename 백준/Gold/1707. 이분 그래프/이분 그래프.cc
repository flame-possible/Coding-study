#include <bits/stdc++.h>

using namespace std;

vector<int> v[20001];
int check[20001];
int color[20001];

int bfs_list[10000000];
int bfs_start;
int bfs_end;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int K;

        cin >> K;


        for(register int test_case = 0; test_case < K; test_case++){


                int V, E;

                cin >> V >> E;

                int temp_a, temp_b;

                //cout << "Start " << V << ' ' << E << '\n';

                for(register int i = 0; i < 20001; i++){

                        check[i] = 0;
                        color[i] = 0;
                        v[i].clear();

                }

                bfs_start = 0;
                bfs_end = 0;

                for(register int i = 0; i < E; i++){
                        cin >> temp_a >> temp_b;

                        v[temp_a].push_back(temp_b);
                        v[temp_b].push_back(temp_a);

                }


                for(register int i = 1; i <= V; i++){
                        sort(v[i].begin(), v[i].end());
                }


                /*
                for(register int i = 1; i <= V; i++){
                        for(register int j = 0; j < v[i].size(); j++){
                                cout << v[i][j] << ' ';
                        }
                        cout << '\n';
                }
                */


                bfs_list[bfs_end++] = 1;

                check[1] = 1;

                int pan = 0;

                int temp_color = 1;

                int remain = 1;

                while(bfs_start < bfs_end){

                        int temp_cur_start = bfs_start;
                        int temp_cur_end = bfs_end;

                        //cout << "bfs_list " << bfs_start << ' ' << bfs_end << '\n';

                        for(register int bfs_test = temp_cur_start; bfs_test < temp_cur_end; bfs_test++){

                                int cur = bfs_list[bfs_start++];



                                color[cur] = temp_color;

                        //      cout << cur << ' ' << v[cur].size() << " color " << temp_color << '\n';

                                for(register int i = 0; i < v[cur].size(); i++){
                        //              cout << "v[cur] index " << v[cur][i] << '\n';
                                        if(v[cur][i] <= 0 || v[cur][i] > V) break;

                                        if(color[v[cur][i]] != 0){
                                                if(color[v[cur][i]] == temp_color){

                        //                              cout << "color "  << color[cur] << ' ' << cur << " color2 "  << color[v[cur][i]] << ' ' << v[cur][i] << '\n';
                                                        pan = 1;
                                                        break;
                                                }
                                         }



                                        if(check[v[cur][i]] & 1){

                                                continue;
                                        }

                                        bfs_list[bfs_end++] = v[cur][i];
                                        check[v[cur][i]] = 1;


                                }
                                if(pan & 1) break;


                        }


                        if(pan & 1) break;

                        if(temp_color == 1) temp_color = 3;

                        else{
                                temp_color = 1;
                        }

                        if(bfs_start >= bfs_end){
                                for(register int i = remain; i <= V; i++){
                                        if(check[i] == 0){
                                                bfs_list[bfs_end++] = i;
                                                check[i] = 1;
                                                remain = i + 1;
                                                break;
                                        }
                                }
                        }


                }

                if(pan & 1) cout << "NO\n";
                else{
                        cout << "YES\n";
                }

        }

        return 0;

}
