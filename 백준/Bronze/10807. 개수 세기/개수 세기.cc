#include <bits/stdc++.h>

using namespace std;

int main(){

        int N;
        int v;

        cin >> N;

        int input[101];

        for(register int i = 0; i < N; i++){
                cin >> input[i];
        }

        cin >> v;

        int result = 0;

        for(register int i = 0; i < N; i++){
                if(v == input[i]) result++;
        }

        cout << result << '\n';

        return 0;

}
