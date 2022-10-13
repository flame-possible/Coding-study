#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int input[1001][4] = {0,};
int DP[1001][4] = {0,};
int num = 0;
int N = 0;

int Min(int A, int B) { if (A < B) return A; return B; }


int main(){

        scanf(" %d", &N);

        for(int i = 1; i <= N; i++){
                scanf(" %d %d %d", &input[i][0], &input[i][1], &input[i][2]);
        }

        for (int i = 1; i <= N; i++){
                DP[i][0] = Min(DP[i - 1][1] + input[i][0], DP[i - 1][2] + input[i][0]);
                DP[i][1] = Min(DP[i - 1][0] + input[i][1], DP[i - 1][2] + input[i][1]);
                DP[i][2] = Min(DP[i - 1][0] + input[i][2], DP[i - 1][1] + input[i][2]);
        }

        printf("%d\n",  Min(Min(DP[N][0], DP[N][1]), DP[N][2]));

        return 0;

}
