#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int main(){

        int output[100001] = {0};
        int N;
        int count = 0;
        int c_1 = 0;

        scanf(" %d", &N);
        for(int i = 666; i < 10000000; i++){
                int a = i;
                int b = 0;
                int ceiling = 1000000;
                c_1 = 0;
                while(ceiling > 0){
                        if (a / ceiling == 6){
                                c_1 += 1;
                                a %= ceiling;
                        }
                        else{
                                c_1 = 0;
                                a %= ceiling;
                        }
                        if (c_1 == 3){
                                count += 1;
                                output[count] = i;
                                break;
                        }
                        ceiling /= 10;
                }
        }
        printf("%d", output[N]);


        return 0;
}
