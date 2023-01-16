#include <bits/stdc++.h>

using namespace std;

int union_find[1001];

int cost;

int N, M;

struct com{

        int start, end, val;


};

bool compare(com a, com b){

        return a.val < b.val;

}

vector<com> input;

int find_parent(int n){

        if(n == union_find[n]) return n;

        int result = find_parent(union_find[n]);
        union_find[n] = result;
        return result;

}

int union_merge(int a, int b){

        a = find_parent(a);
        b = find_parent(b);

        if(a == b) return 1;

        union_find[a] = b;

        return 0;

}

int MST(){

        for(register int i = 0; i <=N; i++){
                union_find[i] = i;
        }

        int cnt = input.size();

        int present_cnt = 0;

        for(register int i = 0; i < cnt; i++){

//              cout << input[i].start << ' ' << input[i].end << ' ' << input[i].val << '\n';

                if(union_merge(input[i].start, input[i].end) == 0){
                        cost += input[i].val;
                        present_cnt++;
                }

                if(present_cnt == N-1) return cost;

        }

        return -1;

}


int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        cin >> N >> M;

        for(register int i = 0; i < M; i++){

                int s, e, v;

                cin >> s >> e >> v;

                com temp = {s, e, v};

                input.push_back(temp);

        }

        sort(input.begin(), input.end(), compare);

        MST();

        cout << cost << '\n';

        return 0;

}
