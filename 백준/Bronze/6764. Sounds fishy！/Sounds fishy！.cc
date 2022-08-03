#include <bits/stdc++.h>

using namespace std;

int main(){

        int input[4];

        for(register int i = 0; i < 4; i++){
                cin >> input[i];
        }

        int pan1, pan2, pan3;

        pan1 = pan2 = pan3 = 0;

        for(register int i = 0; i < 3; i++){

                if(input[i] < input[i+1]) pan1 += 1;
                else pan1 = 0;

                if(input[i] > input[i+1]) pan2 += 1;
                else pan2 = 0;

                if(input[i] == input[i+1]) pan3 += 1;
                else pan3 = 0;


        }

        if(pan1 == 3) cout << "Fish Rising\n";

        else if(pan2 == 3) cout << "Fish Diving\n";

        else if(pan3 == 3) cout << "Fish At Constant Depth\n";

        else cout << "No Fish\n";

        return 0;

}
