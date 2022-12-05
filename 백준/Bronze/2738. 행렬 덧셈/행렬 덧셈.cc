#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int input1[101][101] = {0,};

        int N, M;

        cin >> N >> M;

        for(register int i = 0; i < N; i++){

                for(register int j = 0; j < M; j++){
                        cin >> input1[i][j];
                }

        }

        int temp = 0;

        for(register int i = 0; i < N; i++){

                for(register int j = 0; j < M; j++){
                        cin >> temp;
                        input1[i][j] += temp;
                        cout << input1[i][j] << ' ';
                }
                cout << '\n';
        }

        return 0;

}
