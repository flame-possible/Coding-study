#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int input[200001] = {0,};

int main(){


        int N;
        cin >> N;

        long long total = 0;

        for(register int i = 0; i < N; i++){

                cin >> input[i];
                total += input[i];
        }

        int cnt = 0;

        long long room_kit = total / N;

        long long result = 0;

        int temp = 0;

        int curr = 0;

        for(register int i = 0; i < N; i++){

                result += abs(temp);
                curr = input[i];
                temp -= curr - room_kit;
        }


        cout << result << '\n';

        return 0;
}
