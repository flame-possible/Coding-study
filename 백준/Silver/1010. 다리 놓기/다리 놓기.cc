#include <iostream>

using namespace std;

long long dp[1001][1001] = {0,};

int main(){
ios_base::sync_with_stdio(false);
        cin.tie(0);
        int num;
        cin >> num;

        for(register int k = 0; k < num; k++){
                int N, K;

                cin >> N >> K;

                for(register int i = 1; i <= K; i++){

                        for(register int j = 0; j <= K; j++){
                                if(i == j || j == 0){
                                        dp[i][j] = 1;
                                        continue;
                                }
                                dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]);
                        }

                }

                cout << dp[K][N] << '\n';
        }

        return 0;

}
