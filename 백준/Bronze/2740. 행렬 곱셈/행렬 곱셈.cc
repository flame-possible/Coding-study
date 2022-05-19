#include <iostream>

using namespace std;

int main(){

        register int A_N, A_M;

        int A[101][101] = {0,};

        register int B_N, B_M;

        int B[101][101] = {0,};

        cin >> A_N >> A_M;

        for(register int i = 1; i <= A_N; i++){
                for(register int j = 1; j <= A_M; j++){
                        cin >> A[i][j];
                }
        }

        cin >> B_N >> B_M;

        for(register int i = 1; i <= B_N; i++){
                for(register int j = 1; j <= B_M; j++){
                        cin >> B[i][j];
                }
        }

        int result[101][101] = {0,};

        for(register int i = 1; i <= A_N; i++){

                for(register int j = 1; j <= B_M; j++){

                        register int temp_result = 0;
                        register int temp[101] = {0,};

                        for(register int k = 1; k <= A_M; k++){
                                temp[k] = A[i][k];
                        }
                        for(register int k = 1; k <= B_N; k++){
                                temp[k] *= B[k][j];
                                temp_result += temp[k];
                        }

                        result[i][j] = temp_result;
                        cout << result[i][j] << ' ';
                }
                cout << '\n';
        }



        return 0;

}
