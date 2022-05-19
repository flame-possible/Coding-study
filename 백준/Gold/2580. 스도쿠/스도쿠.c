#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int input[10][10] = {0,};
int space[82][3] = {0,};
int check[82][10] = {0,};
int num = 0;

void DFS(int N){
/*              printf("input:\n");
                for(int i = 0; i<9; i++){
                        for(int j = 0; j<9; j++){
                                printf("%d ", input[i][j]);
                        }
                        printf("\n");
                }
*/

        int ga = space[N][0];
        int se = space[N][1];
        if(num == N){
                for(int i = 0; i<9; i++){
                        for(int j = 0; j<9; j++){
                                printf("%d ", input[i][j]);
                        }
                        printf("\n");
                }
                exit(0);
        }
        else{
                //for(int k = 1; k <= 9; k++){
                        int plus = 0;
                        int minus = 0;
                        for(int i = 1; i < 9; i++){
                                plus++;
                                minus--;
                                if(ga + plus < 9){
                                        if(input[ga+plus][se] != 0){
                                                check[N][input[ga+plus][se]] = 1;
                                        }

                                }
                                if(ga + minus >= 0){
                                        if(input[ga+minus][se] != 0){
                                                check[N][input[ga+minus][se]] = 1;

                                        }
                                }
                                if(se + plus < 9){
                                        if(input[ga][se+plus] != 0){
                                                check[N][input[ga][se+plus]] = 1;
                                        }
                                }
                                if(se + minus >= 0){
                                        if(input[ga][se+minus] != 0){
                                                check[N][input[ga][se+minus]] = 1;
                                        }
                                }

                        }
                        int cross1 = 0;
                        int cross2 = 0;
                        if(ga >= 0 && ga <=2){
                                cross1 = 0;
                        }
                        else if(ga >= 3 && ga <= 5){
                                cross1 = 3;
                        }
                        else if(ga >= 6 && ga <= 8){
                                cross1 = 6;
                        }
                        if(se >= 0 && se <= 2){
                                cross2 = 0;
                        }
                        else if(se >= 3 && se <= 5){
                                cross2 = 3;
                        }
                        else if(se >= 6 && se <= 8){
                                cross2 = 6;
                        }
                        for(int i = cross1; i <= cross1+2; i++){
                                for(int j = cross2; j <= cross2+2; j++){
                                        if(cross1 == ga && cross2 == se){
                                                continue;
                                        }
                                        if(input[i][j] != 0){
                                                check[N][input[i][j]] = 1;
                                        }
                                }
                        }

                for(int k = 1; k <= 9; k++){
                        if(check[N][k] == 0){
                                input[ga][se] = k;
                                DFS(N+1);
                                for(int p = 1; p < 10; p++){
                                        check[N+1][p] = 0;
                                }

                                input[ga][se] = 0;
                        }
                        /*for(int p = 1; p < 10; p++){
                                check[N][p] = 0;
                        }*/
                }

        }

}


int main(){


        for(int i = 0; i < 9; i++){
                for(int j = 0; j < 9; j++){
                        scanf(" %d", &input[i][j]);
                        if(input[i][j] == 0){
                                space[num][0] = i;
                                space[num][1] = j;
                                num++;
                        }
                }
        }

        DFS(0);

        return 0;

}
