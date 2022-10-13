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
	int input[1000] = {0};

	scanf(" %d", &N);

	for(int i = 0; i < N; i++){
		scanf(" %d", &input[i]);
	}

	for(int i = 0; i < N; i++){
		int temp = i;
		for(int j = i + 1; j < N; j++){
			if (input[temp] >= input[j]){
				temp = j;
			}
		}
		int swap = input[temp];
		input[temp] = input[i];
		input[i] = swap;
	}
	for(int i = 0; i < N; i++){
		printf("%d\n", input[i]);
	}

	return 0;
}
