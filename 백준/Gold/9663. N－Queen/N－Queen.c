#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int N;
int result = 0;
int pan[16][16] = {0,};

void DFS(int num){

	if(num == N){
		/*for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				printf("%d ", pan[i][j]);
			}
			printf("\n");
		}*/
		result++;
		//printf("%d\n", result);
	}
	else{
		if(num == 0){
			for(int i = 0; i < N; i++){
				pan[num][i] = 1;
				DFS(num+1);
				pan[num][i] = 0;
			}
		}
		else{

			for(int i = 0; i < N; i++){
				int temp1 = i-1;
				int temp2 = i+1;
				int pass = 0;
				for(int j = num - 1; j >= 0; j--){
					if(pan[j][i] == 1){
						pass = 1;
					}
					if(temp1 >= 0){
						if(pan[j][temp1] == 1){
							pass = 1;
						}
					}
					if(temp2 < N){
						if(pan[j][temp2] == 1){
							pass = 1;
						}
					}
					temp1--;
					temp2++;
				}
				if(pass == 0){
					pan[num][i] = 1;
					DFS(num+1);
					pan[num][i] = 0;
				}
			}

		}

	}
}

int main(){

	scanf(" %d", &N);

	DFS(0);	
	printf("%d", result);

	return 0;

}
