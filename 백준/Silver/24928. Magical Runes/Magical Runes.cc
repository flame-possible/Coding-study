#include <iostream>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        char input[31] ={0,};
        int int_input[31] = {0,};

        int N;

        cin >> input >> N;


        int len = 0;


        for(register int i = 0; i < 31; i++){
                if(input[i] == 0){
                        len = i;
                        break;
                }
        }

        int temp = 1;

        unsigned int result = 0;


        for(register int j = 0; j < len; j++){
                if(input[j] == 'B'){
                        result += temp;
                }
                temp = temp << 1;
        }

        int len_temp = 1;

        int pos = 1;

        for(register int i = 0; i < len-1; i++){
                len_temp = len_temp << 1;
                pos = pos << 1;
        }
        pos = pos << 1;

        N %= pos;

        int pan = 1;

        result += N;


        char output[31] = {0,};
        int cnt = len-1;

        for(register int i = 0; i < len; i++){
                if(result >= len_temp){
                        //cout << 'B';
                        output[cnt--] = 'B';
                        result -= len_temp;
                }
                else{
                        output[cnt--] = 'A';
                        //cout << 'A';
                }
                len_temp = len_temp >> 1;
        }

        cout << output << '\n';

        return 0;

}
