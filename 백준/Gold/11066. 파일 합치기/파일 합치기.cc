#include <bits/stdc++.h>

using namespace std;

int dp[2001][2001], input[501], sum[2001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int T;

        cin >> T;

        for(register int t = 0; t < T; t++){

                int N;

                cin >> N;

                int temp = 0;

                for(register int i = 1; i <= N; i++){

                        cin >> input[i];

                        sum[i] = sum[i-1] + input[i];

                }

                for(register int i = 1; i <= N; i++){

                        for(register int j = 1; j <= N; j++){
                                dp[j][i+j] = 2147483647;

                                for(register int k = j; k < i+j; k++){
                                        dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
                                }

                        }

                }

                cout << dp[1][N] << '\n';


        }

        return 0;

}
