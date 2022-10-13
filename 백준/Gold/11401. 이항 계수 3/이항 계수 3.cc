#include <iostream>

using namespace std;

int MOD = 1000000007;

long long fact(int s, int n){

        long long temp = 1;

        for(register int i = s; i <= n; i++){
                temp = temp * i % MOD;
        }
        return temp;
}

long long mul(int in, int in_2){

        if(in_2 == 1){
                return in % MOD;
        }

        unsigned long long temp = mul(in, in_2/2);

        if(in_2 % 2 == 0){
                return temp * temp % MOD;
        }
        else{
                return temp * temp % MOD * in % MOD;
        }

}


int main(){

        int N, M;

        cin >> N >> M;

        cout << fact(N - M + 1, N) * mul(fact(1, M), MOD - 2) % MOD << '\n';

        return 0;
}
