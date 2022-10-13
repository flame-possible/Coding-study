#include <stdio.h>
#include <unistd.h>
#include <string.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <math.h>

int main(){
	
	int card_num;
	int purpose;
	int card[100] = {0};
	int result = 0;
	int temp_result = 0;
	int gap = 0;
	int temp_gap = 0;
	int output = 0;

	scanf(" %d %d", &card_num, &purpose);
	for(int i = 0; i < card_num; i++){
		scanf(" %d", &card[i]);
	}
	for(int i = 0; i < card_num -2; i++){
		for(int j = i + 1; j < card_num - 1; j++){
			for(int k = j + 1; k < card_num; k++){
				if (i == 0 && j == 1 && k == 2){
					result = card[i] + card[j] + card[k];
					gap = purpose - result;
					if(gap < 0){
						gap *= -1;
					}
					output = result;
				}
				else{
					temp_result = card[i] + card[j] + card[k];
					temp_gap = purpose - temp_result;
					if(gap > temp_gap && temp_result <= purpose){
						gap = temp_gap;
						output = temp_result;
					}
				}
				
			}
		}	
	}
	printf("%d", output);
	return 0;

}
