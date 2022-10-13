#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int main(){

        int N;
        scanf(" %d", &N);

        int number = 2;

        int index = 1;


        while(N != 1){
                if(N % number == 0){
                        printf("%d\n", number);
                        N /= number;
                }
                else{
                        number++;
                }

        }

        return 0;

}
