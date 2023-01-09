#include <bits/stdc++.h>

using namespace std;

int main(){

        int N, S;

        cin >> N >> S;

        int input[100001] = {0,};

        for(register int i = 0; i < N; i++){
                cin >> input[i];
        }

        int start = 0;
        int end = 0;

        int result = 100001;

        int temp = 0;

        while(1){

//              cout << start << ' ' << end << ' ' << temp << '\n';

                if(temp < S){
                        temp += input[end];
                        if(end < N){
                                end++;
                        }
                        else break;
                }

                else{
                        if(result > end - start) result = end - start;
                        temp -= input[start];

                        if(start != end) start++;
                }

        }

        if(result == 100001) cout << "0\n";

        else cout << result << '\n';

        return 0;

}
