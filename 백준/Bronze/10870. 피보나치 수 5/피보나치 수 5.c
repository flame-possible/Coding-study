#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <math.h>

int fibo(int n){

	if(n == 0){
		return 0;
	}
	else if(n == 1){
		return 1;
	}
	else if(n == 2){
		return 1;
	}
	else{
		return fibo(n-1) + fibo(n-2);
	}

}

int main(){

	int N;
	scanf(" %d", &N);

	printf("%d", fibo(N));

	return 0;

}
