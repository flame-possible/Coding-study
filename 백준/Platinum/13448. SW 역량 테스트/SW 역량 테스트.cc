#include <iostream>
#include <bits/stdc++.h>

using namespace std;

double dp[51][100001];

struct Input{

        int M, P, R;
        double order;

        bool operator <(Input &input){
                return this->order < input.order;
        }

};

bool compare(int a, int b){
        return a < b;
}

int main(){

        ios_base::sync_with_stdio(false);
        cin.tie(0);

        int N, T;

        cin >> N >> T;

        int M, P, R;

        Input input[51];

        for(register int i = 0; i < 51; i++){
                input[i].order = 0;
        }


        for(register int i = 1; i <= N; i++){
                cin >> M;

                input[i].M = M;
        }

        for(register int i = 1; i <= N; i++){
                cin >> P;

                input[i].P = P;
        }

        for(register int i = 1; i <= N; i++){
                cin >> R;

                input[i].R = R;
                input[i].order = (double)input[i].R / (double)input[i].P;
        }


        sort(input, input + N+1);
/*
        for(register int i = 1; i <= 50; i++){
                cout << input[i].M << ' ' << input[i].P << ' ' << input[i].R << ' ' << input[i].order << '\n';

        }
*/
        for(register int i = 1; i <= N; i++){
        //      cout << input[i].M << ' ' << input[i].P << ' ' << input[i].R << ' ' << input[i].order << '\n';
                for(register int j = 1; j <= T; j++){
                        if(j - input[i].R >= 0){
                                dp[i][j] = max(dp[i-1][j], dp[i-1][j - input[i].R] + (double)input[i].M - ((double)j * (double)input[i].P));
                        //      cout << " j * P " << (double)input[i].M - ((double)j * (double)input[i].P) << ' ';
                        }
                        else{
                                dp[i][j] = dp[i-1][j];
                        }
                        //cout << dp[i][j] << ' ';
                }
                //cout << '\n';
        }

        int max = 0;

        for(register int i = 0; i <= T; i++){
                if(dp[N][i] > max) max = dp[N][i];
        }

        cout << max << '\n';



        return 0;

}
