#include <bits/stdc++.h>

using namespace std;

int input[301], dp[301];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        for(register int i = 1; i <= N; i++){
                cin >> input[i];
        }

        dp[1] = input[1];

        dp[2] = input[1] + input[2];

        dp[3] = max(input[1] + input[3], input[2] + input[3]);

        for(register int i = 4; i <= N; i++){

                dp[i] = max(input[i-1] + dp[i-3], dp[i-2]) + input[i];

        }

        cout << dp[N] << '\n';


        return 0;

}
