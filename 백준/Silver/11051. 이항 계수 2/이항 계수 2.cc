#include <bits/stdc++.h>

using namespace std;

int tri[1001][1001];

int main(){

        int N, K;

        cin >> N >> K;

        tri[0][0] = 1;


        for(register int i = 1; i <= N; i++){

                for(register int j = 0; j <= i; j++){
                        tri[i][j] = (tri[i-1][j-1] + tri[i-1][j]) % 10007;
                }

        }

        cout << tri[N][K] << '\n';


        return 0;

}
