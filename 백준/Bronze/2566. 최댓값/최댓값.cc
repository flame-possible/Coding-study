#include <bits/stdc++.h>

using namespace std;

int main(){

        int input[10][10];
        int y = 1, x = 1;
        int in_max = 0;

        for(register int i = 0; i < 9; i++){
                for(register int j = 0; j < 9; j++){
                        cin >> input[i][j];

                        if(input[i][j] > in_max){
                                y = i + 1;
                                x = j + 1;
                                in_max = input[i][j];
                        }

                }
        }

        cout << in_max << '\n';
        cout << y << ' ' << x << '\n';

        return 0;

}
