#include <iostream>

using namespace std;

int input[2500][2500] = {0,};

int minus_1 = 0;
int zero = 0;
int one = 0;

void divide(int row, int col, int num){

        register int pan = 0;

        for(register int i = row; i < row+num; i++){

                for(register int j = col; j < col+num; j++){
                        if(input[row][col] != input[i][j]){
                                pan = 1;
                                break;
                        }
                }
                if(pan & 1){
                        break;
                }
        }

        if(pan & 1){
                int size = num / 3;

                for(register int i = 0; i < 3; i++){
                        for(register int j = 0; j < 3; j++){
                                divide(row+size*i, col+size*j, size);
                        }
                }

        }
        else{
                if(input[row][col] == -1){
                        minus_1++;
                }
                else if(input[row][col] == 0){
                        zero++;
                }
                else{
                        one++;
                }

                return;
        }

        return;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);
    
        int N;

        cin >> N;


        for(register int i = 1; i <= N; i++){
                for(register int j = 1; j <= N; j++){
                        cin >> input[i][j];
                }
        }

        divide(1, 1, N);

        cout << minus_1 << '\n' << zero << '\n' << one << '\n';

        return 0;

}
