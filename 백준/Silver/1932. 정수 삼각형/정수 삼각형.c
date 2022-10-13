#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int get_max(int a, int b) { return a > b ? a : b; }
int main() {

    int n, i, j, max = 0;
    int dp[500][500] = {0, };

    scanf("%d", &n);

    for (i = 0; i < n; i++){
         for (j = 0; j <= i; j++){
                 scanf("%d", &dp[i][j]);
        }
    }

    for (i = 1; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0) dp[i][j] = dp[i-1][0] + dp[i][j];
            else if (j == i) dp[i][j] = dp[i-1][j-1] + dp[i][j];
            else dp[i][j] = get_max(dp[i-1][j-1] + dp[i][j], dp[i-1][j] + dp[i][j]);

            max = get_max(max, dp[i][j]);
        }
    }

        if(n == 1){
                printf("%d\n", dp[0][0]);
        }
        else{
                printf("%d\n", max);
        }

    return 0;
}

