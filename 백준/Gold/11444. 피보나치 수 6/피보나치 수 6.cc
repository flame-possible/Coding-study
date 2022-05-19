#include <iostream>

using namespace std;

unsigned long long result[2][2] = {0,};
unsigned long long base[2][2] = {0,};
unsigned long long temp[2][2] = {0,};

void mul(unsigned long long A[][2], unsigned long long B[][2]){

        for(register int i = 0; i < 2; i++){
                for(register int j = 0; j < 2; j++){
                        temp[i][j] = 0;
                        for(register int k = 0; k < 2; k++){
                                temp[i][j] += A[i][k] * B[k][j];
                        }
                        temp[i][j] %= 1000000007;
                }
        }

        for(register int i = 0; i < 2; i++){
                for(register int j = 0; j < 2; j++){
                        A[i][j] = temp[i][j];
                }
        }

}

int main(){

        unsigned long long N;

        cin >> N;

        result[0][0] = 1;
        result[1][1] = 1;

        base[0][0] = 1;
        base[0][1] = 1;
        base[1][0] = 1;

        while(N > 0){

                if(N & 1){
                        mul(result, base);
                }
                mul(base, base);
                N /= 2;

        }

        cout << result[0][1] << '\n';

        return 0;
}
