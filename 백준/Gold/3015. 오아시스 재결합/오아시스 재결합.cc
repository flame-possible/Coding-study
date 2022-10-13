#include <bits/stdc++.h>

using namespace std;

pair<int, int> input[500001];
int input_cnt;
long long int result;


int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        for(register int i = 0; i < N; i++){

                int idx = 1;
                pair<int, int> temp;

                cin >> temp.first;

                while(input_cnt != 0 && input[input_cnt-1].first <= temp.first){

                        if(input[input_cnt-1].first == temp.first){
                                idx += input[input_cnt-1].second;
                                result += input[input_cnt-1].second;
                        }
                        else{
                                result += input[input_cnt-1].second;
                        }

                        input_cnt--;

                }

                if(input_cnt) result++;

                input[input_cnt].first = temp.first;
                input[input_cnt++].second = idx;

        }

        cout << result << '\n';



        return 0;

}
