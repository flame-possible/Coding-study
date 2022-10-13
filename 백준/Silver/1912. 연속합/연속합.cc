#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define len 100000

using namespace std;

int N;
int input[len+1] = {0,};
int dp[len+1] = {0,};

int main(){
        ios_base::sync_with_stdio(false);

        int max1 = 0;
        cin >> N;
        for(int i = 0; i < N; i++){
                cin >> input[i];

                if(i == 0){
                        max1 = input[i];
                        dp[i] = input[i];
                }
                else{

                        if(dp[i-1] + input[i] < input[i]){
                                dp[i] = input[i];
                        }
                        else{
                                dp[i] = dp[i-1] + input[i];
                        }
                        if(max1 < dp[i]){
                                max1 = dp[i];
                        }
                }
        }
        cout << max1 << "\n";


        return 0;
}
