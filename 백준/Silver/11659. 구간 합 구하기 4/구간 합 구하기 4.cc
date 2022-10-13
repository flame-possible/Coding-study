#include <iostream>

using namespace std;

int input[100001] = {0,};

int sum_table[100001] = {0,};

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

        int N, M;

        cin >> N >> M;

        int temp = 0;

        for(register int i = 1; i <= N; i++){

                cin >> input[i];
                temp += input[i];
                sum_table[i] += temp;
        }

        int a, b;

        for(register int i = 1; i <= M; i++){

                cin >> a >> b;
                cout << sum_table[b] - sum_table[a-1] << '\n';

        }

        return 0;

}
