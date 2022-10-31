#include <bits/stdc++.h>

using namespace std;

int input[10001];

int main(){

        int N, k;

        cin >> N >> k;

        for(register int i = 0; i < N; i++){
                cin >> input[i];
        }

        sort(input, input + N, greater<int>());

        cout << input[k-1] << '\n';


        return 0;

}
