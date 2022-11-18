#include <bits/stdc++.h>

using namespace std;

int main(){

        int chess[6] = {1, 1, 2, 2, 2, 8};

        int input;

        for(register int i = 0; i < 6; i++){

                cin >> input;

                chess[i] -= input;

                cout << chess[i] << ' ';

        }

        cout << '\n';



        return 0;

}
