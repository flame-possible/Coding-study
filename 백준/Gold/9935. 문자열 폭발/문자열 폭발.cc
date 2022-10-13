#include <bits/stdc++.h>

using namespace std;

char input[1000002], target[1000002], result[1000002];
int input_len, target_len, result_cnt;

void str_len(char arr[], int *a){

        int i = 0;

        while(arr[(*a)++]){

                continue;

        }

        (*a)--;

        return;

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> input;
        cin >> target;


        str_len(input, &input_len);
        str_len(target, &target_len);


        for(register int i = 0; i < input_len; i++){

                result[result_cnt++] = input[i];

                if(result_cnt >= target_len){

                        if(result[result_cnt - 1] == target[target_len - 1]){

                                int cnt = 1;

                                for(register int j = target_len - 2; j >= 0; j--){
                                        if(result[result_cnt - (target_len - j)] == target[j]){
                                                cnt++;
                                        }
//                                      cout << result[result_cnt - (target_len - j)] << ' ' << result_cnt - (target_len - j) << ' ' << j << '\n';
                                }

                                if(cnt == target_len){
                                        result_cnt -= target_len;
                                }

                        }
                }


        }



        if(result_cnt == 0){
                cout << "FRULA\n";
        }
        else{
                for(register int i = 0; i < result_cnt; i++){
                        cout << result[i];
                }
                cout << '\n';
        }


        return 0;

}
