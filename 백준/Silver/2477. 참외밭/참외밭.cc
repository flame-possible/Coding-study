#include <bits/stdc++.h>

using namespace std;

int main(){

        int K;

        cin >> K;

        int input[6][2] = {0,};

        int num[5][2] = {0,};

        for(register int i = 0; i < 6; i++){

                cin >> input[i][0] >> input[i][1];

                num[input[i][0]][0]++;
                num[input[i][0]][1] = i;

        }

        int start = 0;
        int pan_1, pan_2;

        int big_result = 0;

        if (num[2][0] & 1 && num[4][0] & 1){
                start = 2;
                pan_1 = 3;
                pan_2 = 1;
                big_result = input[num[2][1]][1] * input[num[4][1]][1];
        }

        else if(num[1][0] & 1 && num[4][0] & 1){
                start = 4;
                pan_1 = 2;
                pan_2 = 3;
                big_result = input[num[1][1]][1] * input[num[4][1]][1];

        }

        else if(num[1][0] & 1 && num[3][0] & 1){
                start = 1;
                pan_1 = 4;
                pan_2 = 2;
                big_result = input[num[1][1]][1] * input[num[3][1]][1];

        }

        else{
                start = 3;
                pan_1 = 1;
                pan_2 = 4;
                big_result = input[num[2][1]][1] * input[num[3][1]][1];

        }


        for(register int i = 0; i < 6; i++){
                if(input[i][0] == start){
                        start = i;
                        break;
                }
        }


        int temp_1 = input[(start + 2) % 6][1];
        int temp_2 = input[(start + 3) % 6][1];

        big_result -= temp_1 * temp_2;

        cout << big_result * K << '\n';






        return 0;

}
