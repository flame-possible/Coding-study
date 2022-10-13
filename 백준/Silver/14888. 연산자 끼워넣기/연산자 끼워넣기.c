#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int input[12] = {0,};
int operand[5] = {0,};
char cal[12] = {0,};

int big = 0;
int small = 0;
int fir = 0;

void DFS(int N, int len){
        int num = 0;

        if(len == N - 1){
                int result = input[0];
                for(int i = 1, temp = 0; i < N; i++, temp++){
                        if(cal[temp] == '+'){
                                result += input[i];
                        }
                        else if(cal[temp] == '-'){
                                result -= input[i];
                        }
                        else if(cal[temp] == '*'){
                                result *= input[i];
                        }
                        else if(cal[temp] == '/'){
                                result /= input[i];
                        }
                }
                if(fir == 0){
                        big = result;
                        small = result;
                }
                else{
                        if(big < result){
                                big = result;
                        }
                        if(small > result){
                                small = result;
                        }
                }
                fir++;
        }

        else{
                for(int i = 0; i < 4; i++){
                        if(operand[i] == 0){
                                continue;
                        }
                        else{
                                if(i == 0){
                                        cal[len] = '+';
                                        operand[i] -= 1;
                                        DFS(N, len+1);
                                        operand[i] += 1;
                                }
                                else if(i == 1){
                                        cal[len] = '-';
                                        operand[i] -= 1;
                                        DFS(N, len+1);
                                        operand[i] += 1;
                                }
                                else if(i == 2){
                                        cal[len] = '*';
                                        operand[i] -= 1;
                                        DFS(N, len+1);
                                        operand[i] += 1;
                                }
                                else if(i == 3){
                                        cal[len] = '/';
                                        operand[i] -= 1;
                                        DFS(N, len+1);
                                        operand[i] += 1;
                                }



                        }
                }
        }

}

int main(){

        int N;
        scanf(" %d", &N);
        for(int i = 0; i < N; i++){
                scanf(" %d", &input[i]);
        }
        for(int i = 0; i < 4; i++){
                scanf(" %d", &operand[i]);
        }

        DFS(N, 0);

        printf("%d\n%d", big, small);

        return 0;

}
