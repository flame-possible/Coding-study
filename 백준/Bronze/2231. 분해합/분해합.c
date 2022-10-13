#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <math.h>

int main(){

	int input;

	scanf(" %d", &input);
	if (input == 1){
		printf("0");
		return 0;
	}

	for(int i = 1; i < input; i++){
		int pos_1 = i % 10;
		int pos_10 = i % 100 / 10;
		int pos_100 = i % 1000 / 100;
		int pos_1000 = i % 10000 / 1000;
		int pos_10000 = i % 100000 / 10000;
		int pos_100000 = i / 100000;
		if ( i + pos_1 + pos_10 + pos_100 + pos_1000 + pos_10000 + pos_100000 == input){
			printf("%d", i);
			return 0;
		}
	}
	printf("0");

	return 0;
}
