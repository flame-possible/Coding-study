#include <bits/stdc++.h>

using namespace std;

long long input[400001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, Q;

        cin >> N >> Q;

        int cnt_start = 1;

        while(cnt_start < N){
                cnt_start <<= 1;
        }

        int leaf_start = cnt_start;

        for(register int i = 0; i < N; i++){
                cin >> input[leaf_start];

                int temp = leaf_start++;

                while(temp/2){
                        input[temp/2] += input[leaf_start-1];
                        temp /= 2;
                }

        }
/*
        for(register int i = 0; i < (leaf_start * 2) + 1; i++){
                cout << input[i] << ' ';
        }
        cout << '\n';
*/
        for(register int i = 0; i < Q; i++){

                long long temp_1, temp_2, temp_3, temp_4;

                cin >> temp_1 >> temp_2 >> temp_3 >> temp_4;

                int l, r;

                if(temp_1 < temp_2){

                        l = temp_1 + cnt_start - 1;
                        r = temp_2 + cnt_start - 1;
                }

                else{
                        l = temp_2 + cnt_start - 1;
                        r = temp_1 + cnt_start - 1;
                }

                long long sum = 0;

                while(l <= r){

                        if(l & 1) sum += input[l++];
                        if(!(r & 1)) sum += input[r--];
                        l /= 2;
                        r /= 2;
//                              cout << sum << ' ' << l << ' ' << r << '\n';

                        }

                cout << sum << '\n';



                int temp = temp_3 + cnt_start - 1;

                long long sub = input[temp];

                input[temp] = temp_4;

                while(temp/2){
                        input[temp/2] -= sub;
                        input[temp/2] += temp_4;
                        temp /= 2;
                }

        }


        return 0;

}
