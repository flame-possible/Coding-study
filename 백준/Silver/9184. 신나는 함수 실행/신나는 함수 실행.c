#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <math.h>

int abc[102][102][102] = {0,};

int w(int a, int b, int c){
	if(abc[a][b][c] != 0){
		return abc[a][b][c];
	}

	if(a <= 50 || b <= 50 || c <= 50){
		abc[a][b][c] = 1;
		return abc[a][b][c];
	}
	if(a > 70 || b > 70 || c > 70){
		abc[a][b][c] = w(70, 70, 70);
		return abc[a][b][c];
	}
	if(a < b && b < c){
		abc[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
		return abc[a][b][c];
	}
	else{
		abc[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
		return abc[a][b][c];
	}

}

int main(){

	int N;
	int a, b, c;
	while(1){
		scanf(" %d %d %d", &a, &b, &c);
		if(a == -1 && b == -1 && c == -1){
			break;
		}
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a+50, b+50, c+50));

	}


	return 0;
}