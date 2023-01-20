#include <bits/stdc++.h>

using namespace std;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        string input;

        cin >> input;

        int cnt = 0;

        while(input[cnt]){
                cnt++;
        }

        if(input[cnt - 1] == '(' || input[cnt - 1] == '['){
                cout << "0\n";
                return 0;
        }

        char stack_[31];
        int input_cnt = 0;
        int stack_cnt = 0;

        int result = 0;
        int temp = 1;

        int bug = 0;

        while(input_cnt != cnt){

                if(input[input_cnt] == '('){

                        stack_[stack_cnt++] = '(';

                        temp *= 2;

                }

                else if(input[input_cnt] == '['){

                        stack_[stack_cnt++] = '[';

                        temp *= 3;

                }

                else if(input[input_cnt] == ')'){

                        if(!stack_cnt || stack_[stack_cnt - 1] != '('){
                                bug = 1;
                                break;
                        }

                        if(input[input_cnt - 1] == '('){
                                result += temp;
                        }

                        temp /= 2;
                        stack_cnt--;

                }

                else if(input[input_cnt] == ']'){

                        if(!stack_cnt || stack_[stack_cnt - 1] != '['){
                                bug = 1;
                                break;
                        }

                        if(input[input_cnt - 1] == '['){
                                result += temp;
                        }

                        temp /= 3;
                        stack_cnt--;


                }

                input_cnt++;

        }

        if(bug || stack_cnt){
                cout << "0\n";
        }

        else{
                cout << result << '\n';
        }

        return 0;

}
