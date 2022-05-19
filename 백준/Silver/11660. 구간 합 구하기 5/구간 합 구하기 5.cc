#include <iostream>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        int N, M;

        cin >> N >> M;

        int input[1025][1025] = {0,};

        register int temp;
        register int temp_1 = 0;

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= N; j++){
                        cin >> temp;
                        temp_1 += temp;
                        input[i][j] += temp_1;
                }
                temp_1 = 0;
        }

        register int x1, y1, x2, y2;

        register int result = 0;

        for(register int i = 0; i < M; i++){
                cin >> x1 >> y1 >> x2 >> y2;
                result = 0;
                for(register int j = x1; j <= x2; j++){
                        result += input[j][y2] - input[j][y1-1];
                }
                cout << result << '\n';
        }

        return 0;

}
