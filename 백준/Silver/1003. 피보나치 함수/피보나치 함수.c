#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int d[100] = {0,};

int fibonacci(int x) {
        if(x == 0){
                d[x] = 0;
                return 0;
        }
        if(x == 1){
                d[x] = 1;
                return 1;
        }
        if(d[x] != 0){
                return d[x];
        }
        return d[x] = fibonacci(x - 1) + fibonacci(x - 2);
}


int main(){

        int N;

        scanf(" %d", &N);

        int pur[1000] = {0,};

        for(int i = 0; i<N; i++){
                scanf(" %d", &pur[i]);
        }

        for(int i = 0; i< N; i++){
                fibonacci(pur[i]);
                if(pur[i] == 0){
                        printf("%d %d\n", 1, 0);
                }
                else if(pur[i] == 1){
                        printf("%d %d\n", 0, 1);
                }
                else{
                printf("%d %d\n", d[pur[i]-1], d[pur[i]]);
                }
        }

        return 0;

}
