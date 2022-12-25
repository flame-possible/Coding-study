#include <bits/stdc++.h>

using namespace std;

int prime[10001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int M, N;

        cin >> M >> N;

        prime[0] = prime[1] = 1;


        for(register int i = 2; i <= N; i++){

                if(prime[i]) continue;

                for(register int j = i*2; j <= N; j+=i){
                        prime[j] = 1;
                }

        }

        int sum = 0, small = -1;

        for(register int i = M; i <= N; i++){
                if(!prime[i]){
                        sum += i;

                        if(small == -1){
                                small = i;
                        }
                }
        }

        if(small == -1){
                cout << small << '\n';
        }
        else{
                cout << sum << '\n' << small << '\n';
        }


        return 0;

}
