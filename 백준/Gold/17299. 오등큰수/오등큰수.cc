#include <bits/stdc++.h>

using namespace std;

int cnt[1000002], input[1000002];
int stack_[1000002][2], result[1000002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

        int N;

        cin >> N;

        for(register int i = 0; i < N; i++){

                cin >> input[i];
                cnt[input[i]]++;

        }

        int stack_cnt = 0;

        for(register int i = N - 1; i >= 0; i--){

                while(stack_cnt != 0 && cnt[input[i]] >= stack_[stack_cnt - 1][1]){
                        stack_cnt--;
                }

                if(stack_cnt == 0){
                        result[i] = -1;
                }
                else{
                        result[i] = stack_[stack_cnt - 1][0];
                }

                stack_[stack_cnt][0] = input[i];
                stack_[stack_cnt++][1] = cnt[input[i]];


        }

        for(register int i = 0; i < N; i++){
                cout << result[i] << ' ';
        }

        cout << '\n';


        return 0;

}
