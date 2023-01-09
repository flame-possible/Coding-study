#include <bits/stdc++.h>

using namespace std;

int input[51][51];
int visited[51][51];
int dp[51][51];
int N, M;
int result;
int circle;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int DFS(int y, int x){

//      cout << y << ' ' << x << ' ' << dep << ' ' << result << '\n';

        if(visited[y][x]){
                circle = 1;
                return -1;
        }

        if(circle) return 0;

        if(dp[y][x]) return dp[y][x];

        visited[y][x] = 1;

        int val = input[y][x];

        int temp = 0;

        for(register int i = 0; i < 4; i++){

                int temp_y = y + (dy[i] * val);
                int temp_x = x + (dx[i] * val);

                if(temp_y <= N && temp_y > 0 && temp_x <= M && temp_x > 0 && input[temp_y][temp_x]){

                        temp = DFS(temp_y, temp_x) + 1;

                        if(temp > dp[y][x]) dp[y][x] = temp;
                }

        }

        visited[y][x] = 0;



        return dp[y][x];
}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        cin >> N >> M;


        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= M; j++){

                        char temp;

                        cin >> temp;

                        if(temp <= '9') input[i][j] = temp - '0';

                }
        }

        result = DFS(1, 1) + 1;

        if(circle) cout << "-1\n";
        else cout << result << '\n';

        return 0;

}
