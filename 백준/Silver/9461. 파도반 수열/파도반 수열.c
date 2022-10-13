#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <math.h>

double N[102] = {0,};

double pado(int in){

	N[1] = 1;
	N[2] = 1;
	N[3] = 1;
	N[4] = 2;
	N[5] = 2;
	
	if(N[in] != 0){

		return N[in];
	}

	for(int i = 6; i <= in; i++){

		N[i] = N[i-1] + N[i-5];

	}
	return N[in];

}

int main(){


	int N;
	scanf(" %d", &N);

	int input = 0;
	
	for(int i = 0; i < N; i++){

		scanf(" %d", &input);
		printf("%.0lf\n", pado(input));

	}

	return 0;

}
