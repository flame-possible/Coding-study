#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M;

        int input[101] = {0,};

        cin >> N >> M;

        for(register int i = 0; i < M; i++){

                int k, p, l;

                cin >> k >> p >> l;

                for(register int j = k; j <= p; j++){
                        input[j] = l;
                }

        }

        for(register int i = 1; i <= N; i++){
                cout << input[i] << ' ';
        }

        cout << '\n';


        return 0;

}
