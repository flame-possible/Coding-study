#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>


int main(void) {

	double input = 0; 
	scanf(" %lf", &input);
	printf("%.6lf\n", input * input * M_PI);
	printf("%.6lf", input * input * 2);


	return 0;
}