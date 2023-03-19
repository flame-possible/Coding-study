#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int prime[1000001] = {0,};

        prime[0] = prime[1] = 1;

        for(register int i = 2; i < 1000001; i++){

                if(prime[i]) continue;

                for(register int j = i*2; j <= 1000000; j += i){
                        prime[j] = 1;
                }

        }

        int T;

        cin >> T;

        for(register int i = 0; i < T; i++){

                int N;

                cin >> N;

                int result = 0;

                for(register int i = 2; i <= N/2; i++){
                        if(!prime[i]){
                                if(!prime[N-i]){
                                        result++;
                                }
                        }
                }

                cout << result << '\n';

        }

        return 0;

}
