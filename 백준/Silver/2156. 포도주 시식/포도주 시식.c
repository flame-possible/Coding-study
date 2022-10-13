#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#define N 10002

int dp[N] = {0,};


int max(int a, int b) {return a >= b ? a : b;}
int main(){

        int n;
        scanf(" %d", &n);
        int input[10001] = {0,};

        for(int i = 0; i < n; i++){
                scanf(" %d", &input[i]);
        }

        dp[1] = input[0];
        dp[2] = input[0] + input[1];
        for(int i = 3; i <= n; i++){
                dp[i] = dp[i-3] + input[i-2] + input[i-1];
                dp[i] = max(dp[i], dp[i-2] + input[i-1]);
                dp[i] = max(dp[i], dp[i-1]);
        }

        printf("%d\n", dp[n]);

        return 0;
}
