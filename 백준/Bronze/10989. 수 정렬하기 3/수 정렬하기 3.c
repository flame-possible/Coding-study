#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

# define SIZE 10001

int main() {
        int N;

        scanf(" %d", &N);

        int input;
        int count[SIZE] = {0,};
        for(int i = 0; i < N; i++){
                scanf(" %d", &input);
                count[input]++;
        }
        for(int i = 1; i < SIZE; i++){
                for(int j = 0; j < count[i]; ++j){
                        printf("%d\n", i);
                }
        }


        return 0;

}
