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

        int input[301] = {0,};
        int dp[301] = {0,};
        int max = 0;

        int N;
        scanf(" %d", &N);
        for(int i = 0; i < N; i++){
                scanf(" %d", &input[i]);
        }

        dp[0] = input[0];
        dp[1] = get_max(input[0] + input[1], input[1]);
        dp[2] = get_max(input[0] + input[2], input[1] + input[2]);

        for(int i = 3; i < N; i++){
                dp[i] = get_max(input[i] + dp[i-2], input[i] + input[i-1] + dp[i-3]);

        }
        printf("%d\n", dp[N-1]);

        return 0;
}
