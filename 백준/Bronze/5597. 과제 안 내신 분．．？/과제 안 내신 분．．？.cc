#include <bits/stdc++.h>

using namespace std;

int main(){

        int input;

        int check[31] = {0,};
        int output[2] = {0,};
        int output_cnt = 0;

        for(register int i = 0; i < 28; i++){
                cin >> input;
                check[input] = 1;
        }

        for(register int i = 1; i <= 30; i++){
                if(!(check[i] & 1)){
                        output[output_cnt++] = i;
                }
        }

        cout << output[0] << '\n' << output[1] << '\n';

        return 0;

}
