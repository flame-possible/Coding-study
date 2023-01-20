#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M;

        cin >> N >> M;

        int input;

        int dp[41] = {0,};

        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(register int i = 3; i <= N; i++){
                dp[i] = dp[i-1] + dp[i-2];
        }

        int result = 1;

        int start = 1;

        for(register int i = 0; i < M; i++){
                cin >> input;

                result *= dp[input - start];

                start = input+1;
        }

        result *= dp[N - input];

        cout << result << '\n';




        return 0;

}
