#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int T;

        cin >> T;

        for(register int t = 0; t < T; t++){

                int N, M;

                cin >> N >> M;

                int result = 1;
                int temp = 1;

                for(register int i = M; i > M - N; i--){

                        result *= i;
                        result /= temp++;

                }

                cout << result << '\n';

        }

        return 0;

}
