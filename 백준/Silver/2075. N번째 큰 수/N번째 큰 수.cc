#include <bits/stdc++.h>

using namespace std;

int input[2250001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        for(register int i = 0; i < N * N; i++){

                cin >> input[i];

        }

        sort(input, input + (N * N), greater<int>());

        cout << input[N - 1] << '\n';


        return 0;
}
