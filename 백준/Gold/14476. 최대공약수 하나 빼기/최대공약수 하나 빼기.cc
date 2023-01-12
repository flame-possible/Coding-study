#include <bits/stdc++.h>

using namespace std;


int input[1000001];
int N;
int result;
int minus_result;

int lg[1000001], rg[1000001];

int GCD(int a, int b){

        if(a < b){
                int temp = a;
                a = b;
                b = temp;
        }

//      cout << a << ' ' << b << '\n';

        int temp = a % b;

        if(temp){
                return GCD(b, temp);
        }

        else{
                return b;
        }

}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);


        cin >> N;

        for(register int i = 0; i < N; i++){

                cin >> input[i];

        }

        lg[0] = input[0];
        rg[N-1] = input[N-1];

        int temp_l = lg[0];
        int temp_r = rg[N-1];

        for(register int i = 1; i < N; i++){

                temp_l = GCD(temp_l, input[i]);
                temp_r = GCD(temp_r, input[N - i - 1]);

                lg[i] = temp_l;
                rg[N - i - 1] = temp_r;

//              cout << lg[i] << ' ' << rg[N-i-1] << '\n';

        }

        for(register int i = 0; i < N; i++){

                int temp;

                if(i == 0){
                        temp = rg[1];
                        if(temp <= lg[0]){
                                if(lg[0] % temp){
                                        if(result <= temp){
                                                result = temp;
                                                minus_result = lg[0];
                                        }
                                }
                        }
                        else{
                                if(result <= temp){
                                        result = temp;
                                        minus_result = lg[0];
                                }
                        }
                }

                else if(i == N - 1){
                        temp = lg[N - 2];

                        if(temp <= rg[N-1]){
                                if(rg[N-1] % temp){
                                        if(result <= temp){
                                                result = temp;
                                                minus_result = rg[N-1];
                                        }
                                }
                        }
                        else{
                                if(result <= temp){
                                        result = temp;
                                        minus_result = rg[N-1];
                                }
                        }
                }

                else{
                        temp = GCD(lg[i-1], rg[i+1]);
                        if(temp <= input[i]){
                                if(input[i] % temp){
                                        if(result <= temp){
                                                result = temp;
                                                minus_result = input[i];
                                        }
                                }
                        }
                        else{
                                if(result <= temp){
                                        result = temp;
                                        minus_result = input[i];
                                }
                        }
                }

        }

        if(result == 0 && minus_result == 0) cout << "-1\n";
        else cout << result << ' ' << minus_result << '\n';

        return 0;

}
