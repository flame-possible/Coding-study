#include <iostream>

using namespace std;

int dp[1001][1001] = {0,};

int main(){

        int N, K;

        cin >> N >> K;

        for(register int i = 1; i <= N; i++){

                for(register int j = 0; j <= N; j++){
                        if(i == j || j == 0){
                                dp[i][j] = 1;
                                continue;
                        }
                        dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 10007;
                }

        }

        cout << dp[N][K] << '\n';

        return 0;

}
