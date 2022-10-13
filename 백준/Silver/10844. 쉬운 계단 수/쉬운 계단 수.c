#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#define N 1000001

long long dp[101][11] = {0,};


int min(int a, int b) {return a <= b ? a : b;}
int main(){

        int n;
        scanf(" %d", &n);

        for(int i = 1; i <= 9; i++){
                dp[1][i] = 1;
        }
        for(int i = 2; i <= n; i++){
                dp[i][0] = dp[i-1][1];
                for(int j = 1; j <= 9; j++){
                        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % (long long)1000000000;
                }
        }

        long long sum = 0;
        for(int i = 0; i < 10; i++){
                sum += dp[n][i];
        }

        printf("%lld\n", sum % (long long)1000000000);

        return 0;

}
