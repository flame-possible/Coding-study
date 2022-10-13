#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>

int input1[100000] = {0,};
char input2[100000][101] = {0,};

int sorted1[100000] = {0,};
char sorted2[100000][101] = {0,};

int N;

void merge(int left, int mid, int right){
  int i, j, k, l;
  i = left;
  j = mid+1;
  k = left;

  while(i<=mid && j<=right){
    if(input1[i] <= input1[j]){
      sorted1[k] = input1[i];
      memcpy(sorted2[k++], input2[i++], sizeof(char)*101);
    }
    else{
      sorted1[k] = input1[j];
      memcpy(sorted2[k++], input2[j++], sizeof(char)*101);

    }
  }

  if(i>mid){
    for(l=j; l<=right; l++){
      sorted1[k] = input1[l];
      memcpy(sorted2[k++], input2[l], sizeof(char)*101);
    }
  }
  else{
    for(l=i; l<=mid; l++){
      sorted1[k] = input1[l];
      memcpy(sorted2[k++], input2[l], sizeof(char)*101);
    }
  }

  for(l=left; l<=right; l++){
      input1[l] = sorted1[l];
      memcpy(input2[l], sorted2[l], sizeof(char)*101);
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

        scanf(" %d", &N);

        for(int i = 0; i < N; i++){
                scanf(" %d %s", &input1[i], input2[i]);
        }

        merge_sort(0, N - 1);

        for(int i = 0; i < N; i++){
                printf("%d %s\n", input1[i], input2[i]);
        }

        return 0;

}
