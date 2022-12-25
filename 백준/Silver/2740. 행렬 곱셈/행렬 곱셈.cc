#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, M, K;

        int input_1[101][101] = {0,};
        int input_2[101][101] = {0,};

        cin >> N >> M;

        for(register int i = 1; i <= N; i++){

                for(register int j = 1; j <= M; j++){
                        cin >> input_1[i][j];
                }

        }

        cin >> M >> K;

        for(register int i = 1; i <= M; i++){

                for(register int j = 1; j <= K; j++){
                        cin >> input_2[i][j];
                }

        }

        int result[101][101] = {0,};

        for(register int i = 1; i <= N; i++){

                for(register int j = 1; j <= K; j++){

                        for(register int k = 1; k <= M; k++){
                                result[i][j] += input_1[i][k] * input_2[k][j];
                        }

                        cout << result[i][j] << ' ';

                }

                cout << '\n';

        }


        return 0;

}
