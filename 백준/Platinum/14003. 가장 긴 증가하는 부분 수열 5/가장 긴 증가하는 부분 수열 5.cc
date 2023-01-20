#include <bits/stdc++.h>

using namespace std;

int input[1000001] = {-1000000001,};
int index_list[1000001];


int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        int lis[1000001] = {-1000000001,};


        int lis_cnt = 1;
        int index_cnt = 1;


        for(register int i = 1; i <= N; i++){
                cin >> input[i];

                if(i == 1){
                        lis[i] = input[i];
                        index_list[i] = i;
                }

                else{

                        if(lis[lis_cnt] < input[i]){
                                lis_cnt++;
                                lis[lis_cnt] = input[i];

                                index_list[i] = lis_cnt;

                        }

                        else{
                                int tar = lower_bound(lis, lis + lis_cnt, input[i]) - lis;
                                lis[tar] = input[i];
//                              cout << i << ' ' << input[i] << ' ' << tar << '\n';

                                index_list[i] = tar;
                        }

                }

        }


        cout << lis_cnt << '\n';

        vector<int> result;

        for(register int i = N; i > 0; i--){
                if(index_list[i] == lis_cnt){
                        result.push_back(input[i]);
                        lis_cnt--;
                }
        }

        for(register int i = result.size() - 1; i >= 0; i--){

                cout << result[i] << ' ';

        }
        cout << '\n';


        return 0;

}
