#include <bits/stdc++.h>

using namespace std;

int input[101][101];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int n, m;

        cin >> n >> m;

        for(register int i = 0; i <= n; i++){
                for(register int j = 0; j <= n; j++){
                        input[i][j] = i == j ? 0 : 1e9;
                }
        }

        int temp_1, temp_2, temp_3;

        for(register int i = 0; i < m; i++){

                cin >> temp_1 >> temp_2 >> temp_3;

                input[temp_1][temp_2] = temp_3 < input[temp_1][temp_2] ? temp_3 : input[temp_1][temp_2];

        }

        for(register int k = 1; k <= n; k++){

                for(register int i = 1; i <= n; i++){

                        for(register int j = 1; j <= n; j++){
                                input[i][j] = min(input[i][j], input[i][k] + input[k][j]);
                        }
                }

        }

        for(register int i = 1; i <= n; i++){

                for(register int j = 1; j <= n; j++){

                        if(input[i][j] != 1e9) cout << input[i][j] << ' ';
                        else cout << "0 ";

                }

                cout << '\n';

        }

        return 0;

}
