#include <bits/stdc++.h>

using namespace std;

int prime[4000001];

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N;

        cin >> N;

        prime[0] = prime[1] = 1;

        vector<int> num;

        for(register int i = 2; i <= N; i++){

                if(prime[i]) continue;
                num.push_back(i);

                for(register int j = i*2; j <= N; j+=i){
                        prime[j] = 1;
                }

        }

        int result = 0;
        int temp = 0;

        if(!prime[N]) result++;

        for(register int i = 0; i < num.size(); i++){

                temp = 0;

                for(register int j = i; j < num.size(); j++){
                        if(num[j] >= N) break;

                        temp += num[j];
//                      cout << temp << ' ';
                        if(temp == N){
                                result++;
                                break;
                        }
                        if(temp > N){
                                break;
                        }
                }
//              cout << '\n';

        }

        cout << result << '\n';

        return 0;

}
