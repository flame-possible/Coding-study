#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <math.h>

int facto(int n){

	if(n == 0){
		return 1;
	}
	else{
		return n * facto(n-1);
	}

}

int main(){

	int N;
	scanf(" %d", &N);

	printf("%d", facto(N));

	return 0;

}
