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
	int input[50][2] = {0};
	int result[50] = {0};
	int count = 0;

	scanf(" %d", &N);
	for(int i = 0; i < N; i++){
		scanf(" %d %d", &input[i][0], &input[i][1]);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			
			if (i == j) {
				continue;
			}
			if (input[i][0] < input[j][0] && input[i][1] < input[j][1]) {
				count++;
			}
		}
		if (count == 0) {
			result[i] = 1;
		}
		else{
			result[i] = count + 1;
		}
		count = 0;
	}
	for(int i = 0; i < N; i++){
		printf("%d ", result[i]);
	}

	return 0;
}
