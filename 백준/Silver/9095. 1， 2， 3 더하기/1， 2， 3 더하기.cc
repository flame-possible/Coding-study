#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int T;

        cin >> T;

        int DP[20] = {0,};
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 4;

        for(register int i = 0; i < T; i++){

                int n;

                cin >> n;

                for(register int j = 4; j <= n; j++){
                        DP[j] = DP[j-3] + DP[j-2] + DP[j-1];
                }

                cout << DP[n] << '\n';

        }

        return 0;

}
