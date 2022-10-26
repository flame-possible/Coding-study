#include <bits/stdc++.h>

using namespace std;

int a_list[300001];
int b_list[300001];

int a_start, a_end, b_start, b_end;

string input;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> input;

        int input_idx = 0;
        int result = 0;

        while(input[input_idx]){

                if(input[input_idx] == 'A'){
                        a_list[a_end++] = input_idx;
                }
                else if(input[input_idx] == 'B'){
                        b_list[b_end++] = input_idx;
                }
                else if(b_start != b_end){
                        b_start++;
                        result++;
                }

                input_idx++;

        }

        while(a_start != a_end && b_start != b_end){

                if(a_list[a_start] < b_list[b_start]){
                        result++;
                        a_start++;
                        b_start++;
                }
                else{
                        b_start++;
                }

        }

        cout << result << '\n';

        return 0;

}
