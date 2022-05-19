#include <iostream>

using namespace std;

long long input[6][6] = {0,};
long long result[6][6] = {0,};
long long temp[6][6] = {0,};
long long N, B;

void mul(long long A[6][6], long long B[6][6]){

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= N; j++){
                        temp[i][j] = 0;
                        for(register int k = 1; k <= N; k++){
                                temp[i][j] += (A[i][k] * B[k][j]);
                        }
                        temp[i][j] %= 1000;
                }
        }

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= N; j++){
                        A[i][j] = temp[i][j];
                }
        }

}

int main(){

        cin >> N >> B;

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= N; j++){
                        cin >> input[i][j];

                }
                result[i][i] = 1;

        }

        while(B > 0){

                if(B & 1){
                        mul(result, input);
                }
                mul(input, input);
                B /= 2;

        }

        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= N; j++){
                        cout << result[i][j] << ' ';

                }
                cout << '\n';

        }



        return 0;
}
