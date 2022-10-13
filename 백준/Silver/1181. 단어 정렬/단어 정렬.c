#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

char input[20001][51] = {0,};
int input_len[20001] = {0,};
char sorted[20001][51] = {0,};
int sorted_len[20001] = {0,};

void merge(int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;


  while(i<=mid && j<=right){
    if(input_len[i] < input_len[j]){
      memcpy(sorted[k], input[i], sizeof(char)*51);
      sorted_len[k++] = input_len[i++];
    }
    else if(input_len[i] > input_len[j]){
      memcpy(sorted[k], input[j], sizeof(char) * 51);
      sorted_len[k++] = input_len[j++];

    }
    else{
        for(int m = 0; m < input_len[j]; m++){
                if(input[i][m] > input[j][m]){
                        memcpy(sorted[k], input[j], sizeof(char) * 51);
                        sorted_len[k++] = input_len[j++];
                        break;
                }
                else if(input[i][m] < input[j][m]){
                        memcpy(sorted[k], input[i], sizeof(char) * 51);
                        sorted_len[k++] = input_len[i++];
                        break;
                }
                else{
                        continue;
                }
        }
    }
  }

  if(i>mid){
    for(l=j; l<=right; l++){
        memcpy(sorted[k], input[l], sizeof(char) * 51);
        sorted_len[k++] = input_len[l];
    }
  }
  else{
    for(l=i; l<=mid; l++){
        memcpy(sorted[k], input[l], sizeof(char) * 51);
        sorted_len[k++] = input_len[l];
    }
  }

  for(l=left; l<=right; l++){
        memcpy(input[l], sorted[l], sizeof(char) * 51);
        input_len[l] = sorted_len[l];
  }

}


void merge_sort( int left, int right){
  int mid;

  if(left<right){
    mid = (left+right)/2;
    merge_sort(left, mid);
    merge_sort(mid+1, right);
    merge(left, mid, right);
  }
}


int main(){

        int N;
        scanf(" %d", &N);
        int temp = 0;
        for(int i = 0; i < N - temp; i++){
                scanf(" %s", input[i]);
                for(int j = 0; j < 20000; j++){
                        if(input[i][j] == 0){
                                input_len[i] = j;
                                break;
                        }
                }
                for(int k = 0; k < i; k++){
                        if(strcmp(input[i], input[k]) == 0){
                                i--;
                                temp++;
                                break;
                        }
                }

        }
        merge_sort(0, N - 1 - temp);
        for(int i = 0; i < N - temp; i++){
                printf("%s\n", input[i]);
        }



        return 0;
}
