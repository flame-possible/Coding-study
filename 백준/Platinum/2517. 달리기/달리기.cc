#include <bits/stdc++.h>

using namespace std;

struct Input{

        int val, temp_val, change_val;

};

int comp_1(const Input& a, const Input& b){

        return a.val < b.val;

}

int comp_2(const Input& a, const Input& b){

        return a.temp_val < b.temp_val;

}

Input input[500001];

int index_tree[2000001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        int N;

        cin >> N;

        for(register int i = 1; i <= N; i++){
                cin >> input[i].val;

                input[i].temp_val = i;

        }

        sort(input+1, input+N+1, comp_1);

        for(register int i = 1; i <= N; i++){
                input[i].change_val = i;
        }

        sort(input+1, input+N+1, comp_2);

        int idx_start = 1;

        while(idx_start < N){
                idx_start <<= 1;
        }

        int leaf_start = idx_start;

        for(register int i = 1; i <= N; i++){

                index_tree[leaf_start + input[i].change_val - 1] = 1;

                int temp = leaf_start + input[i].change_val - 1;

                while(temp/2){
                        index_tree[temp/2] += 1;
                        temp /= 2;
                }

                int l = leaf_start, r = leaf_start + input[i].change_val - 1;

                int result = 0;

                while(l <= r){

                        if(l & 1) result += index_tree[l++];
                        if(!(r & 1)) result += index_tree[r--];

                        l /= 2;
                        r /= 2;

                }

                cout << i - result + 1 << '\n';

        }


        return 0;

}
