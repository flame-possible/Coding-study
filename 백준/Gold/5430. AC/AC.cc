#include <iostream>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 10100001
using namespace std;

int main(){

        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int T;

        cin >> T;

        for(register int i = 0; i < T; i++){

                char input[100001] = {0,};

                cin >> input;

                int N;

                cin >> N;

                int arr[100001] = {0,};
                int arr_index = 0;

                char temp[900000] = {0,};
                //string temp;
                cin >> temp;

                int temp_cnt = 0;
                while(temp[temp_cnt]){
                        int temp1;
                        if(temp[temp_cnt] >= '0' && temp[temp_cnt] <= '9'){
                                temp1 = temp[temp_cnt] - '0';
                                if(arr[arr_index] != 0){
                                        arr[arr_index] *= 10;
                                }
                                arr[arr_index] += temp1;
                        }
                        else if(temp[temp_cnt] == ']'){
                                break;
                        }
                        else if(temp[temp_cnt] == ','){
                                arr_index++;
                        }
                        temp_cnt++;
                }
                int input_index = 0;

                int *cursor;
                int cursor_end = arr_index;
                int cursor_start = 0;
                int D_count = 0;

                for(register int i = 0; i < 100001; i++){
                        if(input[i] == 'D'){
                                D_count++;
                        }
                        else if(input[i] == 0){
                                break;
                        }
                }

                if(D_count > N){
                        cout << "error\n";
                        continue;
                }

                cursor = &cursor_start;

                while(input[input_index]){
                        //cout << cursor_start << ' ' << cursor_end << '\n';


                        if(input[input_index] == 'R'){
                                if(cursor == &cursor_start){
                                        cursor = &cursor_end;
                                }
                                else{
                                        cursor = &cursor_start;
                                }
                        }
                        else{
                                if(cursor == &cursor_start){
                                        *cursor += 1;
                                }
                                else{
                                        *cursor -= 1;
                                }

                        }
                        input_index++;
                }
                //cout << cursor_start << ' ' << cursor_end << '\n';
                if(cursor_start > cursor_end || N == 0){
                        cout << "[]\n";
                }
                else if(cursor == &cursor_start){
                        cout << '[';
                        for(register int i = cursor_start; i < cursor_end; i++){
                                cout << arr[i] << ',';
                        }
                        cout << arr[cursor_end] << ']' << '\n';
                }
                else{
                        cout << '[';
                        for(register int i = cursor_end; i > cursor_start; i--){
                                cout << arr[i] << ',';
                        }
                        cout << arr[cursor_start] << ']' << '\n';
                }

        }

        return 0;

}
