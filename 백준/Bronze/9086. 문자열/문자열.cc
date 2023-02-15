#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int T;

        cin >> T;

        for(register int i = 0; i < T; i++){

                string input;

                cin >> input;

                cout << input[0] << input[input.length()-1] << '\n';

        }

        return 0;

}
