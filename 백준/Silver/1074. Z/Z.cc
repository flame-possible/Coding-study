#include <bits/stdc++.h>

using namespace std;

int main(){

        int N, r, c;

        cin >> N >> r >> c;

        int result = 0;

        while(N){

                int size = 1 << N;
                int ban = size >> 1;

                if(c / ban == 0 && r / ban == 0){
                        result += ban * ban * 0;
                        N--;
                        c %= ban;
                        r %= ban;
                }
                else if(c / ban == 1 && r / ban == 0){
                        result += ban * ban * 1;
                        N--;
                        c %= ban;
                        r %= ban;
                }
                else if(c / ban == 0 && r / ban == 1){
                        result += ban * ban * 2;
                        N--;
                        c %= ban;
                        r %= ban;
                }
                else{
                        result += ban * ban * 3;
                        N--;
                        c %= ban;
                        r %= ban;

                }
        }

        cout << result << '\n';

        return 0;

}
