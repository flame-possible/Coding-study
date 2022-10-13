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
                if(len == 0){
                        for(int i = 1; i <= N; i++){
                                output[len] = i;
                                DFS(len + 1, N, M);
                        }
                }
                else{
                        for(int i = output[len - 1]; i <= N; i++){
                                output[len] = i;
                                DFS(len + 1, N, M);
                        }

                }
        }

}

int main(){

        int N, M;
        scanf(" %d %d", &N, &M);
        DFS(0, N, M);


        return 0;

}
