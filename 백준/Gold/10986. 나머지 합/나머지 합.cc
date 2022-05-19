#include <iostream>

using namespace std;

int input[1000001] = {0,};

long long result[1001] = {0,};

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        int N, M;

        cin >> N >> M;

        long long temp = 0;

        for(register int i = 0; i < N; i++){
                cin >> input[i];
                temp += input[i];

                result[temp % M]++;

        }

        temp = 0;

        for(register int i = 0; i < 1000; i++){
                temp += (result[i] * (result[i] - 1)) / 2;
        }

        cout << result[0] + temp << '\n';

        return 0;

}
