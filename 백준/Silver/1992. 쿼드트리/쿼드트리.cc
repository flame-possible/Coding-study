#include <iostream>

using namespace std;

char input[65][65] = {0,};
int final_input[65][65] = {0,};

char result[1024] = {0,};

int result_cnt = 0;

void divide(int x_1, int x_2, int y_1, int y_2){

        register int pan = 0;

        for(register int i = y_1; i <= y_2; i++){
                for(register int j = x_1; j <= x_2; j++){
                        if(input[i][j] != input[y_1][x_1]){
                                pan = 1;
                                break;
                        }
                }
                if(pan & 1){
                        break;
                }
        }

        if(pan & 1){
                int mid1 = (x_1 + x_2) / 2;
                int mid2 = (y_1 + y_2) / 2;
                result[result_cnt++] = '(';

                divide(x_1, mid1, y_1, mid2);
                divide(mid1+1, x_2, y_1, mid2);
                divide(x_1, mid1, mid2+1, y_2);
                divide(mid1+1, x_2, mid2+1, y_2);
                result[result_cnt++] = ')';
        }
        else{

                result[result_cnt++] = input[y_1][x_1];
        }



        return;
}

int main(){

        int N;

        cin >> N;

        for(register int i = 0; i < N; i++){
                cin >> input[i];
        }


        divide(0, N-1, 0, N-1);
        cout << result << '\n';

        return 0;

}
