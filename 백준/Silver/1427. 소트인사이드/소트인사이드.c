#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <math.h>

int main() {

	int N;
	scanf("%d", &N);

	int pan = 1000000000;
	int output[12] = {0,};
	int ceiling = 0;
	
	for(int i = 0; i < 10; i++){
		
		output[i] = N/pan;
		N %= pan;
		pan /= 10;

	}
	
	for(int i = 0; i < 10; i++){
		if(output[i] != 0){
			ceiling = i;
			break;
		}

	}
	int counting[11] = {0,};
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			if(output[j] == i){
				counting[i] += 1;
			}
		}
	}
	
	int result[12] = {0,};
	int j = 0;
	for(int i = 9; i >= 0; i--){
		if(counting[i] != 0){
			counting[i]--;
			result[j] = i;
			j++;
			i++;
			continue;
		}
		
	}

	for(int i = 0; i < 10 - ceiling; i++){
		printf("%d", result[i]);
	}

	return 0;

}
