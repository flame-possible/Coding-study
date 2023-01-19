#include <bits/stdc++.h>

using namespace std;

int input[501][501];
int dp[501][501];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= i; j++){
                        cin >> input[i][j];
                }
        }

        int result = input[1][1];

        dp[1][1] = input[1][1];

        for(register int i = 2; i <= N; i++){
                for(register int j = 1; j <= i; j++){
                        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + input[i][j];
                        result = max(result, dp[i][j]);

                }
        }

        cout << result << '\n';


        return 0;

}
