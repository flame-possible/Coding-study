#include <bits/stdc++.h>

using namespace std;

int N, K;

struct Ju{

        int w, v;

        Ju(int a, int b) : w(a), v(b) {}

};

bool operator<(Ju a, Ju b){

        if(a.w > b.w) return true;

        else{
                if(a.w == b.w){
                        return a.v < b.v;
                }

                return false;
        }

}

priority_queue<int, vector<int>, greater<int> > bag;
priority_queue<Ju> ju;

priority_queue<int> po;

long long result;

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        cin >> N >> K;

        for(register int i = 0; i < N; i++){

                int a, b;

                cin >> a >> b;

                ju.push(Ju(a, b));

        }

        for(register int i = 0; i < K; i++){

                int a;

                cin >> a;

                bag.push(a);

        }

        while(!bag.empty()){

                int bag_temp = bag.top();
                bag.pop();

                while(!ju.empty()){

                        Ju ju_temp = ju.top();

//                      cout << bag_temp << ' ' << ju_temp.v << '\n';

                        if(ju_temp.w <= bag_temp){
                                po.push(ju_temp.v);
                                ju.pop();
                        }
                        else{
                                break;
                        }
                }

                if(!po.empty()){
                        int temp = po.top();
                        result += temp;
                        po.pop();
                }

        }

        cout << result << '\n';


        return 0;

}
