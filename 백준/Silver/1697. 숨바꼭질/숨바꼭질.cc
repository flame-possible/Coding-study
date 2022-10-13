#include <bits/stdc++.h>

using namespace std;

int check[100001];
int bfs_list[1000001];
int bfs_start;
int bfs_end;

int main(){

        int N, M;

        cin >> N >> M;

        int result = 0;


        if(N == M){

                cout << "0\n";
                return 0;

        }

        bfs_list[bfs_end++] = N;
        check[N] = 1;

        while(1){

                int temp_start = bfs_start;
                int temp_end = bfs_end;

                int ans = 0;

                for(register int i = temp_start; i < temp_end; i++){

                        int cur = bfs_list[i];
                        bfs_start++;

                        if(cur == M){
                                ans = 1;
                                break;
                        }

                        if(cur > M){
                                if(cur - 1 >= 0 && !(check[cur - 1] & 1)){
                                        bfs_list[bfs_end++] = cur - 1;
                                        check[cur - 1] = 1;


                                }
                        }
                        else{
                                if(cur - 1 >= 0 && !(check[cur - 1] & 1)){
                                        bfs_list[bfs_end++] = cur - 1;
                                        check[cur - 1] = 1;


                                }

                                if(cur + 1 <= 100000 && !(check[cur + 1] & 1)){
                                        bfs_list[bfs_end++] = cur + 1;
                                        check[cur + 1] = 1;
                                }

                                if(cur * 2 <= 100000 && !(check[cur * 2] & 1)){
                                        bfs_list[bfs_end++] = cur * 2;
                                        check[cur * 2] = 1;
                                }



                        }

                }

                if(ans & 1) break;

                result++;

        }

        cout << result << '\n';

        return 0;

}
