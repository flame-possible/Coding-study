#include <bits/stdc++.h>

using namespace std;

int main(){

        int input[5];

        int result = 0;

        for(register int i = 0;i < 5; i++){
                cin >> input[i];
                result += input[i];

        }

        sort(input, input+5);



        cout << result/5 << '\n' << input[2] << '\n';

        return 0;

}
