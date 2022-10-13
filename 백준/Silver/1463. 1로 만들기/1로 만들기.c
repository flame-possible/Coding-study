#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#define N 1000001

int dp[N] = {0,};


int min(int a, int b) {return a <= b ? a : b;}
int main(){

        int n;
        scanf(" %d", &n);

        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        int result = 0;
        int temp1, temp2, temp3 = 0;
        for(int i = 4; i <= n; i++){

                if(i % 3 == 0){
                        temp1 = dp[i/3] + 1;
                }
                else{
                        temp1 = -1;
                }
                if(i % 2 == 0){
                        temp2 = dp[i/2] + 1;
                }
                else{
                        temp2 = -1;
                }

                temp3 = dp[i-1] + 1;

                if(temp1 != -1 && temp2 != -1){
                        dp[i] = min(min(temp1, temp2), temp3);
                }
                else if(temp1 == -1 && temp2 != -1){
                        dp[i] = min(temp2, temp3);
                }
                else if(temp1 != -1 && temp2 == -1){
                        dp[i] = min(temp1, temp3);
                }
                else{
                        dp[i] = temp3;
                }

        }
        printf("%d\n", dp[n]);


        return 0;
}
