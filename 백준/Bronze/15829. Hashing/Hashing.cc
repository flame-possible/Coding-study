#include <iostream>

using namespace std;

int main(){

        int L;
        cin >> L;

        int r = 31;

        int M = 1234567891;

        char input[51] = {0,};

        cin >> input;

        long long r_temp = 1;

        long long result = 0;

        for(register int i = 0; i < L; i++){
                result += (input[i] - 'a' + 1) * r_temp;
                r_temp *= r;
                r_temp %= M;
                result %= M;
        }

        cout << result << '\n';

        return 0;
}
