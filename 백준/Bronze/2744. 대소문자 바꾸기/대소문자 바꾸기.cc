#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        string input;

        cin >> input;

        for(register int i = 0; i < input.length(); i++){

                if(input[i] >= 'a') input[i] -= 32;
                else input[i] += 32;

        }

        cout << input << '\n';

        return 0;

}
