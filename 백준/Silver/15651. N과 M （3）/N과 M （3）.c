#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int check[9] = {0,};
int output[9] = {0,};


void DFS(int len, int N, int M){


        if(len == M){
                for(int i = 0; i < M; i++){
                        printf("%d ", output[i]);
                }
                printf("\n");
        }
        else{
                for(int i = 1; i <= N; i++){
                        //if(check[i] == 1){
                        //        continue;
                        //}
                        //check[i] = 1;
                        output[len] = i;
                        DFS(len + 1, N, M);
                        //check[i] = 0;
                }
        }

}

int main(){

        int N, M;
        scanf(" %d %d", &N, &M);
        DFS(0, N, M);


        return 0;

}
