#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <math.h>

int main(){

	int N, M;
	char input[51][51] = {0};
	int count_w, count_b = 0;
	int result = 0;

	scanf(" %d %d", &N, &M);

	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			scanf(" %c", &input[i][j]);
		}
	}
	

	for(int i = 1; i <= N - 7; i++){
		for( int j = 1; j <= M - 7; j++){
			for(int k = i; k <= i + 7; k++){
				for(int l = j; l <= j + 7; l++){
					if(k % 2 == 1 && l % 2 == 1){
                                 	       if (input[k][l] != 'W'){
                                        	        count_w += 1;
                                        	}
                                        	else{
                                                	count_b += 1;
                                        	}
                                	}
                                	if(k % 2 == 1 && l % 2 == 0){

                                        	if (input[k][l] != 'B'){
                                                	count_w += 1;
                                        	}
                                        	else{
                                                	count_b += 1;
                                        	}

                                	}
                                	if(k % 2 == 0 && l % 2 == 1){

                                        	if (input[k][l] != 'B'){
                                                	count_w += 1;
                                        	}
                                        	else{
                                                	count_b += 1;
                                        	}

                                	}
                                	if(k % 2 == 0 && l % 2 == 0 ){

                                        	if (input[k][l] != 'W'){
                                                	count_w += 1;
                                        	}
                                        	else{
                                                	count_b += 1;
                                        	}

                                	}
				}
			}
			if (i == 1 && j == 1){
				if (count_w > count_b){
					result = count_b;
					count_w = 0;
					count_b = 0;
					continue;
				}
				else{
					result = count_w;
					count_w = 0;
					count_b = 0;
					continue;
				}
			}
			if (count_w > count_b){
				if(result > count_b){
					result = count_b;
				}
			}
			else{
				if(result > count_w){
					result = count_w;
				}
			}
			count_w = 0;
			count_b = 0;
		}
	}
	printf("%d", result);

	return 0;
}