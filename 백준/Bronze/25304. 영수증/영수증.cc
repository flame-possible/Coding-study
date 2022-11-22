#include <bits/stdc++.h>

using namespace std;

int main(){

        int X, N;

        int input[100][2] = {0,};

        cin >> X >> N;

        int result = 0;

        for(register int i = 0; i < N; i++){

                cin >> input[i][0] >> input[i][1];

                result += input[i][0] * input[i][1];

        }


        if(result == X){
                cout << "Yes\n";
        }

        else{
                cout << "No\n";
        }


        return 0;

}
