#include <bits/stdc++.h>

using namespace std;

int visited[300001];
int len[300001];

int bfs_list[1000001];
int bfs_start;
int bfs_cnt;

int main() {

        int N, K;

        cin >> N >> K;


        bfs_list[bfs_cnt++] = N;

        visited[N] = 1;


        while(1){

                int temp_cnt = bfs_cnt;

                int pan = 0;

                for(; bfs_start < temp_cnt; bfs_start++){

                        int cur = bfs_list[bfs_start];

                        if(cur == K){
                                pan = 1;
                                break;
                        }

                        if(!visited[cur*2] && cur*2 < 100001){
                                bfs_list[bfs_cnt++] = cur*2;
                                visited[cur*2] = 1;
                                len[cur*2] = len[cur];
                        }


                        if(!visited[cur-1] && cur-1 >= 0){
                                bfs_list[bfs_cnt++] = cur-1;
                                visited[cur-1] = 1;
                                len[cur-1] += len[cur] + 1;
                        }

                        if(!visited[cur+1] && cur+1 < 100001){
                                bfs_list[bfs_cnt++] = cur+1;
                                visited[cur+1] = 1;
                                len[cur+1] += len[cur] + 1;
                        }


//                      cout << cur << ' ' << "len " << len[cur] << ' ';

                }

//              cout << '\n';


                if(pan & 1) break;

        }

        cout << len[K] << '\n';


        return 0;

}
