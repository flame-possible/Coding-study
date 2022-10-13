#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int num[300001];
int num_list[300001];
int num_list_cnt;

bool compare(int a, int b){
        return a > b;
}

int main() {

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        string input;

        cin >> input;

        char cur;
        cur = input[0];


        for(register int i = 0; i < N; i++){
                cin >> num[i];
                if(i == 0){
                        num_list[num_list_cnt++] = num[i];
                }
                else{
                        if(cur != input[i]){
                                num_list[num_list_cnt++] = num[i];
                                cur = input[i];
                        }
                        else{
                                if(num_list[num_list_cnt-1] < num[i]){
                                        num_list[num_list_cnt-1] = num[i];
                                }
                        }
                }
        }

        if(N == 1 || N == 2){
                cout << "0\n";
                return 0;
        }

        num_list[0] = 0;
        num_list[num_list_cnt-1] = 0;

        sort(num_list, num_list+num_list_cnt, compare);

        int temp = num_list_cnt - 2;

        int result = temp / 2;

        if(temp % 2){
                result++;
        }

        long long int output = 0;

        for(register int i = 0; i < result; i++){
                output += num_list[i];
        }

        cout << output << '\n';




        return 0;

}
