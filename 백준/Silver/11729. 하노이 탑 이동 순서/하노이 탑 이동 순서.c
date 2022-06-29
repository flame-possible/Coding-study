#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

void move(int from, int to){
        printf("%d %d\n", from, to);
}

void hanoi(int n, int from, int by, int to){
    if(n == 1){
        move(from, to);
    }else{
        hanoi(n-1, from, to, by);
        move(from, to);
        hanoi(n-1, by, from, to);
    }
}

int main(){

        int N;
        scanf(" %d", &N);

        int cnt = pow(2, N) - 1;
        printf("%d\n", cnt);
        hanoi(N, 1, 2, 3);

        return 0;
}
