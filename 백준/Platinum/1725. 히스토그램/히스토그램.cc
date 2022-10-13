#include <bits/stdc++.h>

using namespace std;

int stack_[1000002], stack_cnt;
int input[1000002];
int result;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        for(register int i = 1; i <= N; i++){

                cin >> input[i];

        }

        stack_[stack_cnt++] = 0;


        for(register int i = 1; i <= N+1; i++){

                while(stack_cnt != 0 && input[stack_[stack_cnt - 1]] > input[i]){

                        int height = input[stack_[stack_cnt - 1]];
                        stack_cnt--;
                        int width = i - stack_[stack_cnt - 1] - 1;

                        result = max(result, height * width);

                }

                stack_[stack_cnt++] = i;

        }

        cout << result << '\n';

        return 0;

}
